#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D inputTexture;
uniform int kernelSize;
uniform float kernel[9]; // Maximum 3x3 kernel

void main() {
    vec2 texelSize = 1.0 / textureSize(inputTexture, 0);
    vec3 result = vec3(0.0);
    
    // Calculate offset for kernel center
    int offset = kernelSize / 2;
    
    // Apply convolution
    for(int i = 0; i < kernelSize; i++) {
        for(int j = 0; j < kernelSize; j++) {
            vec2 offset = vec2(float(i - offset) * texelSize.x,
                               float(j - offset) * texelSize.y);
            vec3 pixel = texture(inputTexture, TexCoord + offset).rgb;
            result += pixel * kernel[i * kernelSize + j];
        }
    }
    
    // Output convolved color
    FragColor = vec4(result, 1.0);
}