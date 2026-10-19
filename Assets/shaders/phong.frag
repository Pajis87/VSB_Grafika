#version 330 core

in vec3 worldPos;
in vec3 worldNorm;
in vec4 vertexColor;
out vec4 FragColor;


uniform vec3 cameraPosition;

void main()
{
    vec3 lightPosition = vec3(0.0, 0.0, 0.0);
    vec3 lightDir = normalize(lightPosition - worldPos);
    
    vec3 viewDir = normalize(cameraPosition - worldPos);
    vec3 reflectDir = reflect(-lightDir, normalize(worldNorm));

    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);

    float diff = max(dot(lightDir, normalize(worldNorm)), 0.1);
    vec4 ambient = vec4 (0.1, 0.1, 0.1, 1.0);
    FragColor = ambient + (diff * vertexColor) + (spec * vec4(0.5, 0.5, 1.0, 1.0));
}