// This file was created by Pavel Brazda - BRA0241

#ifndef SCENE_H
#define SCENE_H

#include "gl_includer.h"
#include "DrawableObject.h"
#include "Camera.h"

class Scene {
public:
	Scene();
	void addObject(DrawableObject* object);
	void addCamera(Camera* object);

	Camera* getActiveCamera();
	void setActiveCamera(Camera* camera);

	void updateGameObjects();

	void startGameObjects();
	void draw();
private:
	Camera* activeCamera = nullptr;
	std::vector<DrawableObject*> objects = std::vector<DrawableObject*>();
	std::vector<Camera*> cameras = std::vector<Camera*>();
};

#endif
