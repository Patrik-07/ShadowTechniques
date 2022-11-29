#version 330 core
layout (location = 0) out vec4 gPosition;
layout (location = 1) out vec4 gNormal;
layout (location = 2) out vec4 gAlbedoSpec;
layout (location = 3) out vec4 gTextureCoord;

in vec2 TexCoords;
in vec3 FragPos;
in vec3 Normal;
in vec4 c;

void main() {
    gPosition = vec4(FragPos, 1.0f);
    gNormal = vec4(normalize(Normal), 1.0f);
    gAlbedoSpec = c;
    gTextureCoord = vec4(TexCoords, 1.0f, 1.0f);
}