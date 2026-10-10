#include "Sun.h"
#include "../Rotation.h"
#include "../Scale.h"

Sun::Sun(Model* model, ShaderProgram* shaderProgram, float axis_tilt_angle_y, float axis_tilt_angle_x): DrawableObject(model, shaderProgram) {
	this->axis_tilt_angle_y = axis_tilt_angle_y;
	this->axis_tilt_angle_x = axis_tilt_angle_x;

	transform.add(new Rotation(axis_tilt_angle_y, glm::vec3(0.0f, 0.0f, 1.0f)));
	transform.add(new Rotation(axis_tilt_angle_x, glm::vec3(1.0f, 0.0f, 0.0f)));

	axis_rotation_transform = new Rotation(0.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	transform.add(axis_rotation_transform);
	transform.add(new Scale(glm::vec3(0.2f, 0.2f, 0.2f)));
}

void Sun::update() {
	axis_rotation_angle += 4.0f;
	axis_rotation_transform->setAngle(axis_rotation_angle);
}