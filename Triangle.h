// This file was created by Pavel Brazda - BRA0241

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "../../Engine/GameObject.h"

class Triangle : public GameObject {
public:
	Triangle() : GameObject(
		std::span<const float>({
			0.0f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
			0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f
		}),
		std::vector<int>({3, 3})
	) {
		this->shaderProgram = new ShaderProgram("Assets/Shaders/basic.vert", "Assets/Shaders/basic.frag");
	}

	void update() override {
		this->rotation.y += 0.025f;
	}
};

#endif