#version 450 core

layout (location = 0) in vec4 aPosition;

uniform mat4 uMVP;

void main()
{
    gl_Position = uMVP * aPosition;
};