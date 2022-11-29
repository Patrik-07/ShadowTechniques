#version 330 core
out vec4 FragColor;

in vec2 texCoord;

uniform sampler2D gPosition;
uniform sampler2D gNormal;
uniform sampler2D gAlbedo;

uniform sampler2D aoOutput;
uniform sampler2D shadowMap;
uniform sampler2D lightBulb;

uniform vec3 cameraPos;
uniform vec3 lightPos;

uniform bool isLightEnable;
uniform bool isLightBulbEnable;

bool isLightCloser(vec3 pos1)
{
    return length(cameraPos - pos1) > length(cameraPos - lightPos);
}

bool isBlackLight()
{
    vec4 light = texture(lightBulb, texCoord);
    return light.x == 0.0f && light.y == 0.0f && light.z == 0.0f;
}

vec4 getOutputColor(vec3 lighting, bool enableLight)
{
    vec4 light     = texture(lightBulb, texCoord);
    vec4 position  = texture(gPosition, texCoord);

    vec4 outputColor = vec4(lighting, 1.0f);
    if (outputColor.x == 0.0f && outputColor.y == 0.0f && outputColor.z == 0.0f)
    {
        if (!isBlackLight() && enableLight)
        {
            outputColor = light;
        }
        else
        {
            outputColor = vec4(0.8f, 0.8f, 0.8f, 1.0f);
        }
    }

    if (isLightCloser(position.xyz) && !isBlackLight() && enableLight)
    {
        outputColor = light;
    }

    return outputColor;
}

void main() {
    vec4 position  = texture(gPosition, texCoord);
    vec4 normal    = texture(gNormal, texCoord);
    vec4 color     = texture(gAlbedo, texCoord);
    vec4 shadow    = texture(shadowMap, texCoord);
    vec4 ssao      = texture(aoOutput, texCoord);

    vec3 lightColor = vec3(1.0f);

    vec3 light = vec3(1.0f);
    if (isLightEnable)
    {
        // ambient
        float ambientOcclusion = ssao.r;
        vec3 ambient = vec3(ambientOcclusion * lightColor);

        // diffuse
        vec3 lightDir = normalize(lightPos - position.xyz);
        float diff = max(dot(lightDir, normal.xyz), 0.0f);
        vec3 diffuse = diff * lightColor;

        // specular
        vec3 viewDir = normalize(cameraPos - position.xyz);
        vec3 reflectDir = reflect(-lightDir, normal.xyz);
        float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
        vec3 specular = 0.5f * spec * lightColor;

        light = (ambient + shadow.z * (diffuse + specular));
    }

    vec3 lighting = light * vec3(color);

    FragColor = getOutputColor(lighting, isLightBulbEnable);
}