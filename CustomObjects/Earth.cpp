// This file was created by Pavel Brazda - BRA0241

#include "Earth.h"
#include "../Rotation.h"
#include "../Scale.h"
#include "../Translation.h"

Earth::Earth(Model* model, ShaderProgram* shaderProgram, Sun* sun, float axis_tilt_angle): DrawableObject(model, shaderProgram) {
	this->sun = sun;
	this->axis_tilt_angle = axis_tilt_angle;

	// Sun tilts
	transform.add(new Rotation(sun->axis_tilt_angle_y, glm::vec3(0.0f, 0.0f, 1.0f)));
	transform.add(new Rotation(sun->axis_tilt_angle_x, glm::vec3(1.0f, 0.0f, 0.0f)));

	// Earth orbit around Sun
	orbit_rotation_transform = new Rotation(0.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	transform.add(orbit_rotation_transform);

	transform.add(new Translation(glm::vec3(0.7f, 0.0f, 0.0f)));

	// Inverse Earth orbit rotation to keep the axis tilt in the same direction
	inverse_orbit_rotation_transform = new Rotation(0.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	transform.add(inverse_orbit_rotation_transform);

	// Earth tilt
	transform.add(new Rotation(axis_tilt_angle, glm::vec3(1.0f, 0.0f, 0.0f)));

	// Earth orbit around Sun again to apply the orbit rotation after the tilt
	transform.add(orbit_rotation_transform);

	// Earth rotation around its own axis
	axis_rotation_transform = new Rotation(0.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	transform.add(axis_rotation_transform);


	transform.add(new Scale(glm::vec3(0.1f, 0.1f, 0.1f)));
}


void Earth::update() {
	orbit_rotation_angle += 0.8f;
	orbit_rotation_transform->setAngle(orbit_rotation_angle);
	inverse_orbit_rotation_transform->setAngle(-orbit_rotation_angle);

	axis_rotation_angle += 20.0f;
	axis_rotation_transform->setAngle(axis_rotation_angle);
}