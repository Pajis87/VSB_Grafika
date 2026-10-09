// This file was created by Pavel Brazda - BRA0241

#ifndef EASY_GL_H
#define EASY_GL_H

#include <map>

#include "Scene.h"

class Application {
public:
	static Application* getInstance();

	int init(int width, int height, const char* title);
	void addKeyCallback(GLFWkeyfun callback);
	GLFWwindow* getWindow();
	void setActiveScene(Scene* scene);
	void startFrame();
	void endFrame();
	bool running();
	void run();

	void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

	void setupScenes();
	void setupShaders();
	void setupDrawableObjects();
	void setupCallbacks();

private:
	Application() = default;
	static Application* instance;
	GLFWwindow* window;
	Scene* activeScene;

	std::map<std::string, Scene*> scenes;
	std::vector<ShaderProgram*> shaderPrograms;
	std::vector<DrawableObject*> drawableObjects;
};

#endif