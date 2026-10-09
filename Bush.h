// This file was created by Pavel Brazda - BRA0241

#ifndef BUSH_H
#define BUSH_H

#include "../../Engine/GameObject.h"
#include "../models/mybush.h"

class Bush : public GameObject {
public:
	Bush() : GameObject(bush,
		std::vector<int>({3, 3})
	) {
		this->shaderProgram = new ShaderProgram("Assets/Shaders/basic.vert", "Assets/Shaders/basic.frag");
	}
};

#endif