// This file was created by Pavel Brazda - BRA0241

#ifndef EARTH_H
#define EARTH_H

#include "../DrawableObject.h"
#include "../ShaderProgram.h"
#include "../Rotation.h"
#include "Sun.h"

class Earth : public DrawableObject {
public:
	float axis_tilt_angle;
	float orbit_rotation_angle = 0.0f;

	Earth(Model* model, ShaderProgram* shaderProgram, Sun* sun, float axis_tilt_angle);
	void update() override;
private:
	Sun* sun;
	float axis_rotation_angle = 0.0f;
	Rotation* axis_rotation_transform;
	Rotation* orbit_rotation_transform;
	Rotation* inverse_orbit_rotation_transform;
};

#endif