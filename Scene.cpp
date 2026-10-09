// This file was created by Pavel Brazda - BRA0241

#include "Scene.h"

Scene::Scene() {
	objects = std::vector<DrawableObject*>();
}

void Scene::addObject(DrawableObject* object) {
	objects.push_back(object);
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

