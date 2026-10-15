// This file was created by Pavel Brazda - BRA0241

#ifndef SCALE_H
#define SCALE_H

#include "gl_includer.h"
#include "Transform.h"

class Scale : public Transform {
public:
    Scale(const glm::vec3& factors);
    void setFactors(const glm::vec3& factors);
    glm::mat4 getMatrix() override;
private:
    glm::vec3 factors;
};

#endif