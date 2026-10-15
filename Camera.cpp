#include "Camera.h"


glm::mat4 Camera::getViewMatrix() {
	return glm::lookAt(position, position + target, up);
}

glm::mat4 Camera::getProjectionMatrix() {
	return glm::perspective(glm::radians(60.0f), 1.0f, 0.1f, 100.0f);
}