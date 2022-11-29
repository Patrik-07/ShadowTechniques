#version 330 core

in vec2 texCoord;

out vec4 FragColor;

uniform sampler2D position;
uniform sampler2D normal;

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;

uniform sampler2D ssaoNoiseTexture;
uniform vec3 ssaoSampleKernels[64];

uniform float radius;

const vec2 noiseScale = vec2(1800.0/4.0, 900.0/4.0);

void main() {
    vec3 ssaoFragPos = (viewMatrix * vec4(texture(position, texCoord).xyz, 1.0f)).xyz;

    vec3 ssaoNormal = (viewMatrix * vec4(texture(normal, texCoord).xyz, 0.0f)).xyz;
    ssaoNormal = normalize(ssaoNormal);

    vec3 ssaoRandomNoiseVector = texture(ssaoNoiseTexture, texCoord * noiseScale).xyz;
    vec3 tangent   = normalize(ssaoRandomNoiseVector - ssaoNormal * dot(ssaoRandomNoiseVector, ssaoNormal));
    vec3 bitangent = cross(ssaoNormal, tangent);
    mat3 TBN       = mat3(tangent, bitangent, ssaoNormal);

    float occlusion = 0.0f;
    for (int i = 0; i < 64; i++) {
        // get sample position
        vec3 samplePos = TBN * ssaoSampleKernels[i];
        samplePos =  samplePos * radius + ssaoFragPos;

        vec4 offset = vec4(samplePos, 1.0f);
        offset      = projectionMatrix * offset;
        offset.xyz /= offset.w;
        offset.xyz  = offset.xyz * 0.5f + 0.5f; // transform to range 0.0 - 1.0

        float sampleDepth = (viewMatrix * texture(position, offset.xy)).z;

        float rangeCheck = abs(ssaoFragPos.z - sampleDepth) < radius ? 1.0 : 0.0;

//        float rangeCheck = smoothstep(0.0, 1.0, radius / abs(ssaoFragPos.z - sampleDepth));
        occlusion += (sampleDepth >= samplePos.z ? 1.0f : 0.0f) * rangeCheck;
    }

    occlusion = 1.0f - (occlusion / 64);

    FragColor = vec4(occlusion, occlusion, occlusion, 1.0f);
}
