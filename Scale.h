// This file was created by Pavel Brazda - BRA0241

#ifndef SCALE_H
#define SCALE_H

#include "gl_includer.h"
#include "Transform.h"

class Scale : public Transform {
public:
    Scale(const glm::vec3& factors) {
        this->factors = factors;
    }

    void setFactors(const glm::vec3& factors) {
        this->factors = factors;
    }

    glm::mat4 getMatrix() override {
        return glm::scale(glm::mat4(1.0f), factors);
    }
private:
    glm::vec3 factors;
};

#endif