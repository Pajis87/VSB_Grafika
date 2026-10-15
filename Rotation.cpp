// This file was created by Pavel Brazda - BRA0241

#include "Rotation.h"

Rotation::Rotation(float angle, const glm::vec3& axis) {
    this->angleDegrees = angle;
    this->axis = axis;
}

void Rotation::setAngle(float angle) {
    angleDegrees = angle;
}

glm::mat4 Rotation::getMatrix() {
    return glm::rotate(glm::mat4(1.0f), glm::radians(angleDegrees), axis);
}
