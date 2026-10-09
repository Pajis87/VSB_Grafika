// This file was created by Pavel Brazda - BRA0241

#ifndef COMPOSITE_TRANSFORM_H
#define COMPOSITE_TRANSFORM_H

#include "gl_includer.h"
#include "Transform.h"

class CompositeTransform : public Transform {
private:
    std::vector<Transform*> transformations;
public:
    void add(Transform* transform) {
        transformations.push_back(transform);
    }

    glm::mat4 getMatrix() override {
        glm::mat4 result = glm::mat4(1.0f);
        for (Transform* t : transformations) {
            result = result * t->getMatrix();
        }
        return result;
    }
};

#endif