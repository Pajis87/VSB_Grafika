// This file was created by Pavel Brazda - BRA0241

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "DrawableObject.h"
#include "ShaderProgram.h"
#include "Rotation.h"

class Triangle : public DrawableObject {
public:
	Triangle(ShaderProgram* shaderProgram);

	void update() override;
private:
	float y_rotation_angle = 0.0f;
	Rotation* y_rotation_transform;
};

#endif