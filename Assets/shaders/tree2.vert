#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec3 color;

out vec3 vertexColor;
vec3 vert_color = vec3(0.0, 0.6, 0.0);

uniform mat4 modelMatrix = mat4(1.0);
uniform mat4 viewMatrix = mat4(1.0);
uniform mat4 projectionMatrix = mat4(1.0);


void main()
{
    float shade = 0.3 + 0.5 * abs(normal.y) + position.z * 0.02;
    if (gl_VertexID>65043) {
        vert_color = vec3(0.0f, shade, 0.0f);
    }
    else {
        vert_color = vec3(0.4, 0.3, 0.0);
    }

    vertexColor = abs(vert_color);
    gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(position, 1.0);
}