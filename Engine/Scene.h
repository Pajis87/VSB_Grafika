// This file was created by Pavel Brazda - BRA0241

#ifndef SCENE_H
#define SCENE_H

#include "gl_includer.h"
#include "GameObject.h"

class Scene {
public:
	void addObject(GameObject* object) {
		objects.push_back(object);
	}

	void updateGameObjects() {
		for (GameObject* object : objects) {
			object->update();
		}	
	}

	void startGameObjects() {
		for (GameObject* object : objects) {
			object->start();
		}
	}

	void draw() {
		for (GameObject* object : objects) {
			object->draw();
		}
	}
private:
	std::vector<GameObject*> objects = {};
};

#endif
