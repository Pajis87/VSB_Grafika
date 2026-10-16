// This file was created by Pavel Brazda - BRA0241

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "gl_includer.h"
#include "ShaderProgram.h"
#include "Model.h"
#include "CompositeTransform.h"

class DrawableObject {
public:
	CompositeTransform transform;

	DrawableObject(Model* model, ShaderProgram* shaderProgram);
	void setShaderProgram(ShaderProgram* shaderProgram);
	void setCamera(Camera* camera);
	void draw();
	virtual void start();
	virtual void update();

protected:
	ShaderProgram *shaderProgram;
	Model* model;
};

#endif