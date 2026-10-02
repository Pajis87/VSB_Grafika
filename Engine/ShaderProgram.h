// This file was created by Pavel Brazda - BRA0241

#ifndef SHADER_PROGRAM_H
#define SHADER_PROGRAM_H

#include "gl_includer.h"

class ShaderProgram {
public:
	ShaderProgram(const char* vertexShaderFile, const char* fragmentShaderFile) {
		this->vertexShader = createShaderFromFile(GL_VERTEX_SHADER, vertexShaderFile);
		this->fragmentShader = createShaderFromFile(GL_FRAGMENT_SHADER, fragmentShaderFile);

		this->shaderProgram = glCreateProgram();
		glAttachShader(this->shaderProgram, this->fragmentShader);
		glAttachShader(this->shaderProgram, this->vertexShader);
		glLinkProgram(this->shaderProgram);
	}

	GLuint getShaderProgram() const {
		return this->shaderProgram;
	}

	void setVec3Variable(const GLchar *name, float v1, float v2, float v3) {
		glUseProgram(this->shaderProgram);
		int location = glGetUniformLocation(this->shaderProgram, name);
		if (location == -1) {
			std::cout << "Uniform variable " << name << " not found in shader program." << std::endl;
		}
		else {
			glUniform3f(location, v1, v2, v3);
		}
		glUseProgram(0);
	}
private:
	GLuint vertexShader;
	GLuint fragmentShader;
	GLuint shaderProgram;

	// ==== THIS CODE WAS TAKEN FROM MARTIN NEMEC AT LMS.VSB.CZ vvv
	GLuint createShaderFromFile(GLenum shaderType, const char* shaderFile) {
		// Creates an empty shader
		GLuint shaderID = glCreateShader(shaderType);

		if (shaderID == 0) {
			std::cout << "Unable to create shader" << std::endl;
			exit(EXIT_FAILURE);
		}

		//Loading the contents of a file into a variable
		std::ifstream file(shaderFile);
		if (!file.is_open()) {
			std::cout << "Unable to open file " << shaderFile << std::endl;
			glDeleteShader(shaderID);
			exit(-1);
		}
		std::string shaderCode((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

		// Set the shader source code
		const char* source = shaderCode.c_str();
		glShaderSource(shaderID, 1, &source, nullptr);

		// Compile the shader source code
		glCompileShader(shaderID);

		// Check specialization/compilation status
		GLint success;
		glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
		if (!success) {
			char infoLog[1024];
			glGetShaderInfoLog(shaderID, sizeof(infoLog), nullptr, infoLog);
			std::cout
				<< "Shader failed:\n"
				<< infoLog << std::endl;
			glDeleteShader(shaderID);
			exit(1);
		}
		return shaderID;
	}
	// ==== THIS CODE WAS TAKEN FROM MARTIN NEMEC AT LMS.VSB.CZ ^^^
};

#endif