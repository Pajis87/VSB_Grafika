#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;

out vec3 vertexColor;

uniform vec3 offset = vec3(0.0, 0.0, 0.0);
uniform vec3 scale = vec3(1.0, 1.0, 1.0);

void main()
{
    vertexColor = color;
    gl_Position = vec4(offset + (position * scale), 1.0);
}