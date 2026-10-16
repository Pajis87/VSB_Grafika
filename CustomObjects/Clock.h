// This file was created by Pavel Brazda - BRA0241

#ifndef CLOCK_H
#define CLOCK_H

#include "../DrawableObject.h"
#include "../ShaderProgram.h"
#include "../Rotation.h"

class Clock : public DrawableObject {
public:
	Clock(Model* model, ShaderProgram* shaderProgram);

	void update() override;

private:
	glm::mat4 secondsMatrix = glm::mat4(1.0);
	glm::mat4 minutesMatrix = glm::mat4(1.0);
	glm::mat4 hoursMatrix = glm::mat4(1.0);

	int hours = 0;
	int minutes = 0;
	int seconds = 0;
};

#endif