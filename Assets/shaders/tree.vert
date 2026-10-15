#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;

out vec3 vertexColor;
vec3 vert_color = vec3(0.0, 0.6, 0.0);

uniform mat4 modelMatrix;


void main()
{
    vert_color.y = vert_color.y + (position.y * 0.05);
    if (position.y < 0.8) {
        vert_color = vec3(0.4, 0.3, 0.0);
    }
    vertexColor = abs(vert_color);
    gl_Position = modelMatrix * vec4(position, 1.0);
}