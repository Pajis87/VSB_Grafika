// This file was mostly created by Pavel Brazda - BRA0241 (exceptions are annotated)

#ifndef SHADER_PROGRAM_H
#define SHADER_PROGRAM_H

#include "gl_includer.h"

class ShaderProgram {
public:
	ShaderProgram(const char* vertexShaderFile, const char* fragmentShaderFile);
	GLuint getShaderProgram() const;
	void setVariable(const GLchar* name, float v1);
	void setVariable(const GLchar* name, float v1, float v2);
	void setVariable(const GLchar* name, float v1, float v2, float v3);

private:
	GLuint vertexShader;
	GLuint fragmentShader;
	GLuint shaderProgram;
	GLuint createShaderFromFile(GLenum shaderType, const char* shaderFile);
};

#endif