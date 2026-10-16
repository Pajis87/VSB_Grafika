// This file was created by Pavel Brazda - BRA0241

#ifndef CAMERA_H
#define CAMERA_H

#include "gl_includer.h"
#include "CompositeTransform.h"
#include "Listener.h"

class Camera {
public:
	glm::mat4 getViewMatrix();
	glm::mat4 getProjectionMatrix();

	glm::vec3 getPosition();
	glm::vec3 getRotation();

	void setPosition(glm::vec3 position);
	void setRotation(glm::vec3 rotation);

	void moveForward(glm::vec3 offset);
	void addRotationOffset(glm::vec3 offset);

	void subscribe(Listener* listener);
	void notifySubscribers();
private:
	glm::vec3 position = glm::vec3(0.0f, 0.0f, 2.0f);
	glm::vec3 target = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

	std::vector<Listener*> listeners = std::vector<Listener*>();
};

#endif