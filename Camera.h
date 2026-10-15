// This file was created by Pavel Brazda - BRA0241

#ifndef CAMERA_H
#define CAMERA_H

#include "gl_includer.h"
#include "CompositeTransform.h"

class Camera {
public:
	glm::vec3 position = glm::vec3(0.0f, 0.0f, 2.0f);
	glm::vec3 target = glm::vec3(0.0f, 0.0f, -1.0f);;
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);;
	glm::mat4 getViewMatrix();
	glm::mat4 getProjectionMatrix();
private:

};

#endif