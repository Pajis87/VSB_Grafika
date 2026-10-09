// This file was created by Pavel Brazda - BRA0241

#include "DrawableObject.h"


void DrawableObject::setShaderProgram(ShaderProgram *shaderProgram) {
	this->shaderProgram = shaderProgram;
}
void DrawableObject::draw() {
	this->shaderProgram->setVariable("offset", position.x, position.y, position.z);
	this->shaderProgram->setVariable("rotation", rotation.x, rotation.y, rotation.z);
	this->shaderProgram->setVariable("scale", scale.x, scale.y, scale.z);


	glUseProgram(shaderProgram->getShaderProgram());
	model->draw();
	glUseProgram(0);
}




void DrawableObject::start() {}
void DrawableObject::update() {}

ShaderProgram *shaderProgram;
