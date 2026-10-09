#include "Triangle.h"
#include "Assets/models/triangle.h"


Triangle::Triangle(ShaderProgram* shaderProgram): DrawableObject(new Model(points, {3, 3}), shaderProgram) {
	y_rotation_transform = new Rotation(0.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	transform.add(y_rotation_transform);
}

void Triangle::update() {
	y_rotation_angle += 0.5f;
	y_rotation_transform->setAngle(y_rotation_angle);
}