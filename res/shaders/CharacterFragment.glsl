#version 450 core

layout (location = 0) out vec4 fragColor;

uniform sampler2D uTexture;
uniform vec4 uColor;

in vec2 textureCoord;

void main() {
	fragColor = vec4(uColor.rgb, uColor.a * texture(uTexture, textureCoord).r);
};