#version 330 core
out vec4 FragColor;

in vec2 texCoord;

uniform sampler2D ssaoInput;

void main() {
    vec2 texelSize = 1.0 / vec2(textureSize(ssaoInput, 0));
    float result = 0.0;

    float blurSize = 4.0f;

    vec2 hlim = vec2(float(-blurSize) * 0.5 + 0.5);
    for (int x = 0; x < blurSize; x++)
    {
        for (int y = 0; y < blurSize; y++)
        {
            vec2 offset = (hlim + vec2(float(x), float(y))) * texelSize;
            result += texture(ssaoInput, texCoord + offset).r;
        }
    }
    float r = result / (blurSize * blurSize);
    FragColor = vec4(r, r, r, r);
}