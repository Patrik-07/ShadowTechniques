#version 330 core
in vec2 texCoord;

uniform sampler2D position;

out vec4 FragColor;

void main() {
    vec4 color = texture(position, texCoord);
    FragColor = color;
}
