// This file was created by Pavel Brazda - BRA0241

#ifndef SPHERE_H
#define SPHERE_H

#include "../models/sphere.h"
#include "../../Engine/GameObject.h"

class Sphere : public GameObject {
public:
	Sphere() : GameObject(sphere,
		std::vector<int>({ 3, 3 })
	) {
		this->shaderProgram = new ShaderProgram("Assets/Shaders/basic.vert", "Assets/Shaders/basic.frag");
	}
};

#endif