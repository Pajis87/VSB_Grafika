#include "Camera.h"


glm::mat4 Camera::getViewMatrix() {
	return glm::lookAt(position, position + target, up);
}

glm::mat4 Camera::getProjectionMatrix() {
	return glm::perspective(glm::radians(60.0f), 16.0f / 9.0f, 0.1f, 100.0f);
}


glm::vec3 Camera::getPosition() {
	return position;
}


glm::vec3 Camera::getRotation() {
	float rotX = glm::degrees(acos(target.y));

	float rotY = glm::degrees(atan2(-target.z, target.x));

	if (rotY < 0.0f) {
		rotY += 360.0f;
	}
	return glm::vec3(rotX, rotY, 0.0f);
}


void Camera::setPosition(glm::vec3 position) {
	this->position = position;
	notifySubscribers();
}

void Camera::setRotation(glm::vec3 rotation) {
	rotation.x = std::clamp(rotation.x, 10.0f, 170.0f);

	target.x = sin(glm::radians(rotation.x)) * cos(glm::radians(rotation.y));
	target.y = cos(glm::radians(rotation.x));
	target.z = -sin(glm::radians(rotation.x)) * sin(glm::radians(rotation.y));
	notifySubscribers();
}


void Camera::moveForward(glm::vec3 offset) {
	glm::vec3 front = glm::vec3(target.x, 0.0f, target.z);
	glm::vec3 right = glm::cross(front, glm::vec3(0.0f, 1.0f, 0.0f));

	glm::vec3 newPosition = position + (front * offset.z) + (right * offset.x);

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