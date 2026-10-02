#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;

out vec3 vertexColor;

uniform vec3 offset = vec3(0.0, 0.0, 0.0);
uniform vec3 rotation = vec3(0.0, 0.0, 0.0);
uniform vec3 scale = vec3(1.0, 1.0, 1.0);

vec3 rotatedPosition = position;

void main()
{
    vertexColor = abs(color);

    rotatedPosition = vec3(
        position.x * cos(rotation.y) + position.z * sin(rotation.y),
        position.y,
        -position.x * sin(rotation.y) + position.z * cos(rotation.y)
    );

    gl_Position = vec4(offset + (rotatedPosition * scale), 1.0);
}