// This file was created by Pavel Brazda - BRA0241

#ifndef MOON_H
#define MOON_H

#include "../DrawableObject.h"
#include "../ShaderProgram.h"
#include "../Rotation.h"
#include "Sun.h"
#include "Earth.h"

class Moon : public DrawableObject {
public:
	Moon(Model* model, ShaderProgram* shaderProgram, Sun* sun, Earth* earth);

	void update() override;
private:
	Sun* sun;
	Earth* earth;
	float axis_rotation_angle = 0.0f;
	Rotation* axis_rotation_transform;
	float orbit_rotation_angle = 0.0f;
	Rotation* orbit_rotation_transform;
	Rotation* earth_orbit_rotation_transform;
	Rotation* inverse_earth_orbit_rotation_transform;
};

#endif