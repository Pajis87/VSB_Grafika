// This file was created by Pavel Brazda - BRA0241

#ifndef TRIANGLE_SWITCHED_H
#define TRIANGLE_SWITCHED_H

#include "DrawableObject.h"
#include "ShaderProgram.h"
#include "Rotation.h"

class TriangleSwitched : public DrawableObject {
public:
	TriangleSwitched(Model* model, ShaderProgram* shaderProgram);

	void update() override;
private:
	float y_rotation_angle = 0.0f;
	Rotation* y_rotation_transform;
};

#endif