// This file was created by Pavel Brazda - BRA0241

#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include "gl_includer.h"

class Transform {
public:
	virtual glm::mat4 getMatrix() = 0;
};

#endif