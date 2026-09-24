#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;

out vec3 vertexColor;
vec3 offset = vec3(-0.35, -0.45, -0.2);


void main()
{
    vertexColor = position;
    gl_Position = vec4(position.xyz + offset.xyz, 1.0);
}