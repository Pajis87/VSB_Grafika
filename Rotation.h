// This file was created by Pavel Brazda - BRA0241

#ifndef ROTATION_H
#define ROTATION_H

#include "gl_includer.h"
#include "Transform.h"

class Rotation : public Transform {
public:
    Rotation(float angle, const glm::vec3& axis);
    void setAngle(float angle);
    glm::mat4 getMatrix() override;
private:
    float angleDegrees;
    glm::vec3 axis;
};

#endif