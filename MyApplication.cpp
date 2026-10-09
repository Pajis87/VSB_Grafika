// This file was created by Pavel Brazda - BRA0241
/*
#ifndef MY_APPLICATION_H
#define MY_APPLICATION_H

#include <map>

#include "Engine/EasyGL.h"
#include "Engine/Scene.h"
#include "Assets/GameObjects/Triangle.h"
#include "Assets/GameObjects/Sphere.h"
#include "Assets/GameObjects/Tree.h"
#include "Assets/GameObjects/Bush.h"
#include "Assets/GameObjects/Login.h"


struct AppData {
	EasyGL* engine;
	std::map<std::string, Scene*>* scenes;
};

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GL_TRUE);
	}

	if (key == GLFW_KEY_1 && action == GLFW_PRESS) {
		AppData* data = (AppData*)glfwGetWindowUserPointer(window);
		if (!data) return;
		data->engine->setActiveScene(data->scenes->at("triangle"));
	}

	if (key == GLFW_KEY_2 && action == GLFW_PRESS) {
		AppData* data = (AppData*)glfwGetWindowUserPointer(window);
		if (!data) return;
		data->engine->setActiveScene(data->scenes->at("sphere"));
	}

	if (key == GLFW_KEY_3 && action == GLFW_PRESS) {
		AppData* data = (AppData*)glfwGetWindowUserPointer(window);
		if (!data) return;
		data->engine->setActiveScene(data->scenes->at("tree"));
	}

	if (key == GLFW_KEY_4 && action == GLFW_PRESS) {
		AppData* data = (AppData*)glfwGetWindowUserPointer(window);
		if (!data) return;
		data->engine->setActiveScene(data->scenes->at("login"));
	}
}


class MyApplication {
public:
	void init() {
		engine = EasyGL();
		engine.init(800, 800, "ZPG");

		AppData* data = new AppData{ &engine, &scenes };
		glfwSetWindowUserPointer(engine.getWindow(), data);
		engine.addKeyCallback(key_callback);
	}

	void setupScenes() {
		scenes.insert({ "triangle", new Scene() });
		scenes.insert({ "sphere", new Scene() });
		scenes.insert({ "tree", new Scene() });
		scenes.insert({ "login", new Scene() });

		engine.setActiveScene(scenes.at("triangle"));
	}

	void setupGameObjects() {
		scenes.at("triangle")->addObject(new Triangle());
		scenes.at("sphere")->addObject(new Sphere());

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 5; j++) {
				Tree* tree = new Tree();
				tree->position = Vector3(i * 0.2f - 0.9f, j * 0.4f - 0.9f, 0.0f);
				tree->scale = Vector3(0.1f, 0.1f, 0.1f);
				scenes.at("tree")->addObject(tree);

				Bush* bush = new Bush();
				bush->position = Vector3(i * 0.2f - 0.85f, j * 0.4f - 0.95f, -0.5f);
				bush->scale = Vector3(0.1f, 0.1f, 0.1f);
				scenes.at("tree")->addObject(bush);
			}
		}


		Login* bigLogin = new Login();
		bigLogin->scale = Vector3(0.5f, 0.5f, 1.0f);
		scenes.at("login")->addObject(bigLogin);


		Login* rightBottomLogin = new Login();
		rightBottomLogin->position = Vector3(0.7f, -0.8f, -0.8f);
		rightBottomLogin->scale = Vector3(0.15f, 0.15f, 0.15f);

		scenes.at("triangle")->addObject(rightBottomLogin);
		scenes.at("sphere")->addObject(rightBottomLogin);
		scenes.at("tree")->addObject(rightBottomLogin);
	}

	void run() {
		while (engine.running()) {
			engine.startFrame();
			engine.endFrame();
		}
	}
private:
	EasyGL engine;
	std::map<std::string, Scene*> scenes;
};

#endif*/