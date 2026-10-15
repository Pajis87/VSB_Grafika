// This file was created by Pavel Brazda - BRA0241

#include "Moon.h"
#include "../Rotation.h"
#include "../Scale.h"
#include "../Translation.h"

Moon::Moon(Model* model, ShaderProgram* shaderProgram, Sun* sun, Earth* earth): DrawableObject(model, shaderProgram) {
	this->sun = sun;
	this->earth = earth;

	// Sun tilts
	transform.add(new Rotation(sun->axis_tilt_angle_y, glm::vec3(0.0f, 0.0f, 1.0f)));
	transform.add(new Rotation(sun->axis_tilt_angle_x, glm::vec3(1.0f, 0.0f, 0.0f)));

	// Earth orbit around Sun
	earth_orbit_rotation_transform = new Rotation(0.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	transform.add(earth_orbit_rotation_transform);

	transform.add(new Translation(glm::vec3(0.7f, 0.0f, 0.0f)));

	// Inverse Earth orbit rotation to keep the axis tilt in the same direction
	inverse_earth_orbit_rotation_transform = new Rotation(0.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	transform.add(inverse_earth_orbit_rotation_transform);

	// Earth tilt
	transform.add(new Rotation(earth->axis_tilt_angle, glm::vec3(1.0f, 0.0f, 0.0f)));

	// Earth orbit around Sun again to apply the orbit rotation after the tilt
	transform.add(earth_orbit_rotation_transform);

	// Moon orbit around Earth
	orbit_rotation_transform = new Rotation(0.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	transform.add(orbit_rotation_transform);

	transform.add(new Translation(glm::vec3(0.2f, 0.0f, 0.0f)));

	// Moon rotation around its own axis
	// THIS CODE IS USELESS, THE MOON DOES NOT ROTATE AROUND ITS OWN AXIS TODO: REMOVE
	axis_rotation_transform = new Rotation(0.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	transform.add(axis_rotation_transform);

	transform.add(new Scale(glm::vec3(0.05f, 0.05f, 0.05f)));
}


void Moon::update() {
	earth_orbit_rotation_transform->setAngle(earth->orbit_rotation_angle);
	inverse_earth_orbit_rotation_transform->setAngle(-earth->orbit_rotation_angle);
	
	orbit_rotation_angle += 5.0f;
	orbit_rotation_transform->setAngle(orbit_rotation_angle);
}