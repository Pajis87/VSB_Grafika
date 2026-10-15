// This file was created by Pavel Brazda - BRA0241

#include "DrawableObject.h"

DrawableObject::DrawableObject(Model* model, ShaderProgram* shaderProgram) {
	this->model = model;
	this->shaderProgram = shaderProgram;
}

void DrawableObject::setShaderProgram(ShaderProgram *shaderProgram) {
	this->shaderProgram = shaderProgram;
}
void DrawableObject::draw() {
	this->shaderProgram->setVariable("modelMatrix", transform.getMatrix());

	this->shaderProgram->useShaderProgram();
	model->draw();
	glUseProgram(0);
}


void DrawableObject::start() {}
void DrawableObject::update() {}
