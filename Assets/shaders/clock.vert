#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec3 color;

out vec3 vertexColor;

uniform mat4 modelMatrix = mat4(1.0);
uniform mat4 viewMatrix = mat4(1.0);
uniform mat4 projectionMatrix = mat4(1.0);


uniform mat4 secondsMatrix = mat4(1.0);
uniform mat4 minutesMatrix = mat4(1.0);
uniform mat4 hoursMatrix = mat4(1.0);


void main()
{
    vertexColor = abs(color);
    gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(position, 1.0);
    if (color == vec3(0.0, 0.0, 0.0)) {
        vertexColor = vec3(0.55, 0.55, 0.55);
    }
    if (color == vec3(1.0, 0.0, 0.0)) {
        vertexColor = vec3(0.7, 0.0, 0.0);
        gl_Position = projectionMatrix * viewMatrix * modelMatrix * secondsMatrix * vec4(position, 1.0);
    }
    if (color == vec3(0.0, 1.0, 0.0)) {
        vertexColor = vec3(0.0, 0.0, 0.0);
        gl_Position = projectionMatrix * viewMatrix * modelMatrix * minutesMatrix * vec4(position, 1.0);
    }
    if (color == vec3(0.0, 0.0, 1.0)) {
        vertexColor = vec3(0.0, 0.0, 0.0);
        gl_Position = projectionMatrix * viewMatrix * modelMatrix * hoursMatrix * vec4(position, 1.0);
    }
    if (color == vec3(1.0, 1.0, 0.0)) {
        vertexColor = vec3(0.0196078431372549, 0.7647058823529412, 0.8705882352941176);
    }
}