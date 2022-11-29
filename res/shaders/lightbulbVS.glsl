#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;

out vec4 Albedo;

struct MVP {
    mat4 model;
    mat4 view;
    mat4 projection;
};
uniform MVP mvp;
uniform vec4 color;

void main() {
    Albedo = color;

    gl_Position = mvp.projection * mvp.view * mvp.model * vec4(aPos, 1.0);
}