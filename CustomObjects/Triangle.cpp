// This file was created by Pavel Brazda - BRA0241

#include "Triangle.h"
#include "../Rotation.h"
#include "../Translation.h"

Triangle::Triangle(Model* model, ShaderProgram* shaderProgram) : DrawableObject(model, shaderProgram) {
	transform.add(new Translation(glm::vec3(0.4f, 0.0f, 0.0f)));
	y_rotation_transform = new Rotation(0.0f, glm::vec3(0.0f, 0.0f, 1.0f));
	transform.add(y_rotation_transform);
}

void Triangle::update() {
	y_rotation_angle += 0.5f;
	y_rotation_transform->setAngle(y_rotation_angle);
}