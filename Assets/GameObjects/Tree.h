// This file was created by Pavel Brazda - BRA0241

#ifndef TREE_H
#define TREE_H

#include "../../Engine/GameObject.h"
#include "../models/mytree.h"

class Tree : public GameObject {
public:
	Tree() : GameObject(mytree,
		std::vector<int>({3, 3})
	) {
		this->shaderProgram = new ShaderProgram("Assets/Shaders/basic.vert", "Assets/Shaders/basic.frag");
	}
};

#endif