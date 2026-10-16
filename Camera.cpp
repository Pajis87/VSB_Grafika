#include "Camera.h"


glm::mat4 Camera::getViewMatrix() {
	return glm::lookAt(position, position + target, up);
}

glm::mat4 Camera::getProjectionMatrix() {
	return glm::perspective(glm::radians(60.0f), 1.0f, 0.1f, 100.0f);
}


glm::vec3 Camera::getPosition() {
	return position;
}

glm::vec3 Camera::getRotation() {
	float rotYRadians = acos(target.y);
	glm::vec3 rotation =  glm::vec3(glm::degrees(acos(target.x / sin(rotYRadians))), glm::degrees(rotYRadians), 0.0f);
	return rotation;
}


void Camera::setPosition(glm::vec3 position) {
	this->position = position;
	notifySubscribers();
}

void Camera::setRotation(glm::vec3 rotation) {
	target.x = sin(glm::radians(rotation.y)) * cos(glm::radians(rotation.x));
	target.y = cos(glm::radians(rotation.y));
	target.z = -sin(glm::radians(rotation.y)) * sin(glm::radians(rotation.x));
	notifySubscribers();
}


void Camera::moveForward(glm::vec3 offset) {
	glm::vec3 newPosition = glm::vec3();
	setPosition(newPosition);
}

void Camera::addRotationOffset(glm::vec3 offset) {
	setRotation(getRotation() + offset);
}

void Camera::subscribe(Listener* listener) {
	if (std::find(listeners.begin(), listeners.end(), listener) != listeners.end()) {
		return;
	}
	listeners.push_back(listener);
}


void Camera::notifySubscribers() {
	for (Listener* listener : listeners) {
		listener->update();
	}
}