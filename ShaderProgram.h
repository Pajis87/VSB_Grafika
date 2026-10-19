// This file was created by Pavel Brazda - BRA0241

#ifndef SHADER_PROGRAM_H
#define SHADER_PROGRAM_H

#include "gl_includer.h"
#include "Listener.h"
#include "Camera.h"

class ShaderProgram : public Listener {
public:
	ShaderProgram(const char* vertexShaderFile, const char* fragmentShaderFile);
	void setVariable(const GLchar* name, glm::mat4 matrix);
	void setVariable(const GLchar* name, glm::vec3 vector);
	void useShaderProgram();
	void setCamera(Camera* camera);

	void update() override;
private:
	Camera* camera;
	GLuint vertexShader;
	GLuint fragmentShader;
	GLuint shaderProgram;
	GLuint createShaderFromFile(GLenum shaderType, const char* shaderFile);
};

#endif