#version 330 core

in vec2 texCoord;

out vec4 FragColor;

uniform sampler2D position;
uniform sampler2D normal;
uniform sampler2D depthMap;

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;

uniform sampler2D ssaoNoiseTexture;

const vec2 noiseScale = vec2(1800.0/4.0, 900.0/4.0);

float occlusion = 0.0f;
float sum = 0.0f;

float PI = 3.1415926535897932384626433832795;
int NUMBER_OF_SAMPLING_DIRECTIONS = 4;
float TANGENT_BIAS = 0.2f;
int NUMBER_OF_STEPS = 4;
float STEP = 0.04f;
float RADIUS = 1.0f;

vec4 depthToNormal(vec2 tc)
{
    float depth = texture(depthMap, tc).x;

    vec4 clipSpace = vec4(tc * 2.0 - 1.0, depth, 1.0);
    vec4 viewSpace = inverse(projectionMatrix) * clipSpace;
    viewSpace.xyz /= viewSpace.w;

    vec3 pos = viewSpace.xyz;
    vec3 n = normalize(cross(dFdx(pos), dFdy(pos)));
    n *= - 1;

    return vec4(n, 1.0);
}

vec3 GetJitter()
{
    return textureLod(ssaoNoiseTexture, (gl_FragCoord.xy / 4), 0).xyz;
}

vec2 RotateDirection(vec2 Dir, vec2 CosSin)
{
    return vec2(Dir.x*CosSin.x - Dir.y*CosSin.y, Dir.x*CosSin.y + Dir.y*CosSin.x);
}

void main() {
    vec3 pos = vec3(texCoord, texture(depthMap, texCoord).r);

    vec4 normalV = (viewMatrix * vec4(texture(normal, texCoord).xyz, 0.0f));
    normalV = normalize(normalV);

    vec3 NDC_POS = (2.0 * pos) - 1.0; // normalized device coordinates
    vec4 unprojectPosition = inverse(projectionMatrix) * vec4(NDC_POS, 1.0);
    vec3 viewPosition  = unprojectPosition.xyz / unprojectPosition.w;

    vec3 sampleNoise = texture(ssaoNoiseTexture, texCoord * noiseScale).xyz;
    sampleNoise.xy = sampleNoise.xy * 2.0 - vec2(1.0);

    float samplingDiskDirection = 2 * PI / NUMBER_OF_SAMPLING_DIRECTIONS;
    vec3 Rand = GetJitter();

    for (int i = 0; i < NUMBER_OF_SAMPLING_DIRECTIONS; i++)
    {
        float samplingDirectionAngle = i * samplingDiskDirection;
        vec2 samplingDirection = RotateDirection(vec2(cos(samplingDirectionAngle), sin(samplingDirectionAngle)), Rand.xy);

        float tangentAngle = acos(dot(vec3(samplingDirection, 0.0), normalV.xyz)) - (0.5 * PI) + TANGENT_BIAS;
        float horizonAngle = tangentAngle;

        vec3 LastDifference = vec3(0);

        for(int j = 0; j < NUMBER_OF_STEPS; j++)
        {
            vec2 stepForward = (Rand.z + float(j+1)) * STEP * samplingDirection;

            vec2 stepPosition = texCoord + stepForward;

            float steppedLocationZ = texture(depthMap, stepPosition.xy).z;

            vec3 steppedLocationPosition = vec3(stepPosition, steppedLocationZ);

            //convert to NDC
            vec3 steppedPositionNDC = (2.0 * steppedLocationPosition) - 1.0;
            vec4 SteppedPositionUnProj = inverse(projectionMatrix) * vec4(steppedPositionNDC, 1.0);
            vec3 viewSpaceSteppedPosition = SteppedPositionUnProj.xyz / SteppedPositionUnProj.w;

            vec3 diff = viewSpaceSteppedPosition.xyz - viewPosition;

            if(length(diff) < RADIUS)
            {
                LastDifference = diff;
                float FoundElevationAngle = atan(diff.z / length(diff.xy));
                horizonAngle = max(horizonAngle, FoundElevationAngle);
            }

            float norm = length(LastDifference) / RADIUS;
            float attenuation = 1 - norm * norm;

            occlusion += clamp(attenuation * (sin(horizonAngle) - sin(tangentAngle)), 0.0, 1.0);
//            sum += 1.0 - occlusion; //control AO darkness
        }

    }

    sum = 1.0f - (occlusion / NUMBER_OF_SAMPLING_DIRECTIONS);

    FragColor = vec4(sum, sum, sum, 1.0f);
}
