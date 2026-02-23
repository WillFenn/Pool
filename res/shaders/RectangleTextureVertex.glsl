#version 450 core

layout (location = 0) in vec4 aPosition;
layout (location = 1) in vec2 aTextureCoord;

uniform mat4 uMVP;

out vec2 textureCoord;

void main()
{
    gl_Position = uMVP * aPosition;
    textureCoord = aTextureCoord;
};