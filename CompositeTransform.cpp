// This file was created by Pavel Brazda - BRA0241

#include "CompositeTransform.h"

void CompositeTransform::add(Transform* transform) {
    transformations.push_back(transform);
}

glm::mat4 CompositeTransform::getMatrix() {
    glm::mat4 result = glm::mat4(1.0f);
    for (Transform* t : transformations) {
        result = result * t->getMatrix();
    }
    return result;
}
