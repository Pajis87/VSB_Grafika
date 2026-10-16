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
	return glm::vec3(1.0f);
}


void Camera::setPosition(glm::vec3 position) {
	this->position = position;
	notifySubscribers();
}

void Camera::setRotation(glm::vec3 rotation) {
	notifySubscribers();
}


void Camera::addPositionOffset(glm::vec3 offset) {
	setPosition(position + offset);
}

void Camera::addRotationOffset(glm::vec3 offset) {
	notifySubscribers();
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