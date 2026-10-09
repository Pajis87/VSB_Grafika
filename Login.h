// This file was created by Pavel Brazda - BRA0241

#ifndef LOGIN_H
#define LOGIN_H

#include "../../Engine/GameObject.h"
#include "../models/login.h"

class Login : public GameObject {
public:
	Login() : GameObject(login,
		std::vector<int>({3, 3})
	) {
		this->shaderProgram = new ShaderProgram("Assets/Shaders/basic.vert", "Assets/Shaders/gray.frag");
	}
};

#endif