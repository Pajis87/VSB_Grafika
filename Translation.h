// This file was created by Pavel Brazda - BRA0241

#ifndef TRANSLATION_H
#define TRANSLATION_H

#include "gl_includer.h"
#include "Transform.h"

class Translation : public Transform {
public:
    Translation(const glm::vec3& offset) {
        this->translation = offset;
    }

    glm::mat4 getMatrix() override {
        return glm::translate(glm::mat4(1.0f), translation);
    }
private:
    glm::vec3 translation;
};

#endif