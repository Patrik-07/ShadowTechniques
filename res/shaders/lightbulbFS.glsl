#version 330 core
out vec4 FragColor;

in vec4 Albedo;

void main() {
    vec4 outputColor = Albedo;
    FragColor = outputColor;
}