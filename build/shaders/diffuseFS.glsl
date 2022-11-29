#version 330 core
out vec4 FragColor;

in vec2 texCoord;

uniform sampler2D gPosition;
uniform sampler2D gNormal;

uniform vec3 lightColor;
uniform vec3 lightPosition;

void main() {
    vec4 position = texture(gPosition, texCoord);
    vec4 normal   = texture(gNormal,   texCoord);

    // diffuse
    vec3 lightDirection = normalize(lightPosition - position.xyz);
    float diff = max(dot(lightDirection, normal.xyz), 0.0f);
    vec3 diffuse = diff * lightColor;

    FragColor = vec4(diffuse, 1.0f);
}