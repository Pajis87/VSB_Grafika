#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec3 color;

out vec4 vertexColor;
out vec3 worldPos;
out vec3 worldNorm;

uniform mat4 modelMatrix = mat4(1.0);
uniform mat4 viewMatrix = mat4(1.0);
uniform mat4 projectionMatrix = mat4(1.0);


void main()
{
    vec4 wp = modelMatrix * vec4(position, 1.0);
    worldPos = vec3(wp.xyz / wp.w);
    worldNorm = normal;

    vertexColor = vec4(1.0, 0.0, 0.0, 1.0);
    gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(position, 1.0);
}