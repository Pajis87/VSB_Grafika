// This file was created by Pavel Brazda - BRA0241

#include "Translation.h"

Translation::Translation(const glm::vec3& offset) {
    this->translation = offset;
}

glm::mat4 Translation::getMatrix() {
    return glm::translate(glm::mat4(1.0f), translation);
}