// This file was created by Pavel Brazda - BRA0241

#ifndef SCENE_H
#define SCENE_H

#include "gl_includer.h"
#include "DrawableObject.h"

class Scene {
public:
	Scene();
	void addObject(DrawableObject* object);

	void updateGameObjects();

	void startGameObjects();
	void draw();
private:
	std::vector<DrawableObject*> objects;
};

#endif
