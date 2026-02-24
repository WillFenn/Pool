#version 450 core

layout (location = 0) out vec4 fragColor;

uniform sampler2D uTexture;

in vec2 textureCoord;

void main() {
	fragColor = texture(uTexture, textureCoord);
};