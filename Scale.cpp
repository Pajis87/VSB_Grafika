// This file was created by Pavel Brazda - BRA0241

#include "Scale.h"

Scale::Scale(const glm::vec3& factors) {
    this->factors = factors;
}

void Scale::setFactors(const glm::vec3& factors) {
    this->factors = factors;
}

glm::mat4 Scale::getMatrix() {
    return glm::scale(glm::mat4(1.0f), factors);
}