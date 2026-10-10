// This file was created by Pavel Brazda - BRA0241

#ifndef SUN_H
#define SUN_H

#include "../DrawableObject.h"
#include "../ShaderProgram.h"
#include "../Rotation.h"

class Sun : public DrawableObject {
public:
	float axis_tilt_angle_y;
	float axis_tilt_angle_x;

	Sun(Model* model, ShaderProgram* shaderProgram, float axis_tilt_angle_y, float axis_tilt_angle_x);
	void update() override;

private:
	float axis_rotation_angle = 0.0f;
	Rotation* axis_rotation_transform;
};

#endif