// This file was created by Pavel Brazda - BRA0241

#include "Scene.h"

Scene::Scene() {
	objects = std::vector<DrawableObject*>();
}

void Scene::addObject(DrawableObject* object) {
	objects.push_back(object);
}

void Scene::addCamera(Camera* camera) {
	cameras.push_back(camera);
}

Camera* Scene::getActiveCamera() {
	if (activeCamera == nullptr) {
		printf("ERROR: No active camera");
		exit(EXIT_FAILURE);
	}
	return activeCamera;
}

void Scene::setActiveCamera(Camera* camera) {
	activeCamera = camera;
	for (DrawableObject* object : objects) {
		object->setCamera(camera);
	}
}

void Scene::updateGameObjects() {
	for (DrawableObject* object : objects) {
		object->update();
	}	
}

void Scene::startGameObjects() {
	for (DrawableObject* object : objects) {
		object->start();
	}
}

void Scene::draw() {
	for (DrawableObject* object : objects) {
		object->draw();
	}
}

