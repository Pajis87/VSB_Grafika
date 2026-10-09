// This file was created by Pavel Brazda - BRA0241

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "gl_includer.h"
#include "ShaderProgram.h"
#include "Model.h"

class DrawableObject {
public:
	glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f);

	DrawableObject(Model* model, ShaderProgram* shaderProgram);
	void setShaderProgram(ShaderProgram* shaderProgram);
	void draw();
	virtual void start();
	virtual void update();

protected:
	ShaderProgram *shaderProgram;
	Model* model;
};

#endif