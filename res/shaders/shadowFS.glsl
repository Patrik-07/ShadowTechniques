#version 330 core
out vec4 FragColor;

in vec2 texCoord;

uniform sampler2D gPosition;
uniform sampler2D gNormal;

uniform sampler2D shadowDepth;

uniform vec3 lightPosition;
uniform mat4 lightSpaceMatrix;

float calculateShadow(sampler2D f_shadowMap, vec4 f_fragLightSpacePos, float f_bias) {
    vec3 l_projectionCoords = f_fragLightSpacePos.xyz / f_fragLightSpacePos.w;
    l_projectionCoords = l_projectionCoords * 0.5f + 0.5f;

    float l_closestDepth = texture(f_shadowMap, l_projectionCoords.xy).r;

    float l_currentDepth = l_projectionCoords.z;

    float l_shadow = 0.0f;
    vec2 l_texelSize = 1.0f / textureSize(f_shadowMap, 0);

    for (int x = -1; x <= 1; ++x)
    {
        for (int y = -1; y <= 1; ++y)
        {
            float l_pcfDepth = texture(f_shadowMap, l_projectionCoords.xy + vec2(x, y) * l_texelSize).r;
            l_shadow += l_currentDepth - f_bias > l_pcfDepth ? 0.75f : 0.0f;
        }
    }

    l_shadow = l_shadow / 9.0f;

    if (l_projectionCoords.z > 1.0f)
    {
        l_shadow = 0.0f;
    }

    return 1.0f - l_shadow;
}

void main() {
    vec4 position = texture(gPosition, texCoord);
    vec4 normal = texture(gNormal, texCoord);

    vec3 lightDir = normalize(lightPosition - position.xyz);

    vec4 fragPosLightSpace = lightSpaceMatrix * position;

    float shadow = calculateShadow(shadowDepth, fragPosLightSpace, 0.005f);

    FragColor = vec4(shadow, shadow, shadow, 1.0f);
}