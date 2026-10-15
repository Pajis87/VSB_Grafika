// This file was created by Pavel Brazda - BRA0241

#ifndef SHADER_PROGRAM_H
#define SHADER_PROGRAM_H

#include "gl_includer.h"
#include "Camera.h"

class ShaderProgram {
public:
	ShaderProgram(const char* vertexShaderFile, const char* fragmentShaderFile);
	void setVariable(const GLchar* name, glm::mat4 matrix);
	void useShaderProgram();
	void setCamera(Camera* camera);
private:
	Camera* camera;
	GLuint vertexShader;
	GLuint fragmentShader;
	GLuint shaderProgram;
	GLuint createShaderFromFile(GLenum shaderType, const char* shaderFile);
};

#endif