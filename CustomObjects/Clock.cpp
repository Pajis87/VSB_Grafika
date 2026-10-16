// This file was created by Pavel Brazda - BRA0241

#include "Clock.h"
#include "../Rotation.h"
#include "../Translation.h"
#include <time.h>

Clock::Clock(Model* model, ShaderProgram* shaderProgram) : DrawableObject(model, shaderProgram) {

}

void Clock::update() {
	time_t raw_time = time(NULL);
	struct tm t;
	if (localtime_s(&t, &raw_time) != 0) {
		perror("localtime_r failed");
		seconds = 0;
		minutes = 0;
		hours = 0;
	}
	else {
		seconds = t.tm_sec;
		minutes = t.tm_min;
		hours = t.tm_hour;
	}

	secondsMatrix = glm::rotate(glm::mat4(1.0), -seconds * 2.0f * 3.141592653f / 60.0f, glm::vec3(0.0, 0.0, 1.0));
	minutesMatrix = glm::rotate(glm::mat4(1.0), -minutes * 2.0f * 3.141592653f / 60.0f - seconds * 2.0f * 3.141592653f / 60.0f / 60.0f, glm::vec3(0.0, 0.0, 1.0));
	hoursMatrix = glm::rotate(glm::mat4(1.0), -hours * 2.0f * 3.141592653f / 12.0f - minutes * 2.0f * 3.141592653f / 60.0f / 12.0f, glm::vec3(0.0, 0.0, 1.0));

	shaderProgram->setVariable("secondsMatrix", secondsMatrix);
	shaderProgram->setVariable("minutesMatrix", minutesMatrix);
	shaderProgram->setVariable("hoursMatrix", hoursMatrix);
}