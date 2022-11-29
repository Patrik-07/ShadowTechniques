#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;

out vec3 FragPos;
out vec2 TexCoords;
out vec3 Normal;
out vec4 c;

struct MVP {
    mat4 model;
    mat4 view;
    mat4 projection;
};
uniform MVP mvp;
uniform vec4 color;

void main() {
    // pos
    vec4 worldPos = mvp.model * vec4(aPos, 1.0);
    FragPos = worldPos.xyz;

    // texCoord
    TexCoords = aTexCoords;

    // normal
    mat3 normalMatrix = transpose(inverse(mat3(mvp.model)));
    Normal = normalMatrix * normalize(aNormal);

    // albedo
    c = color;

    gl_Position = mvp.projection * mvp.view * worldPos;
}