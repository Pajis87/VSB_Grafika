// This file was mostly created by Pavel Brazda - BRA0241 (exceptions are annotated)

#include "Application.h"
#include "Triangle.h"
#include "Assets/models/mytree.h"



int Application::init(int width, int height, const char* title) {
	// ==== THIS CODE WAS TAKEN FROM MARTIN NEMEC AT LMS.VSB.CZ AND EDITED vvv
	// Initialize GLFW
	if (!glfwInit())
		exit(EXIT_FAILURE);

	//Initialization of a specific version
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	//glfwWindowHint(GLFW_OPENGL_PROFILE,
	//GLFW_OPENGL_CORE_PROFILE);


	window = glfwCreateWindow(width, height, title, NULL, NULL);
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	// Initialize GLAD and load OpenGL function pointers
	if (!gladLoadGL((GLADloadfunc)glfwGetProcAddress)) {
		printf("GLAD initialization failed\n");
		return -1;
	}

	// Get version info
	printf("OpenGL Version: %s\n", glGetString(GL_VERSION));
	printf("Vendor %s\n", glGetString(GL_VENDOR));
	printf("Renderer %s\n", glGetString(GL_RENDERER));
	printf("GLSL %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
	int major, minor, revision;
	glfwGetVersion(&major, &minor, &revision);
	printf("Using GLFW %i.%i.%i\n", major, minor, revision);
	// ==== THIS CODE WAS TAKEN FROM MARTIN NEMEC AT LMS.VSB.CZ AND EDITED ^^^



	glEnable(GL_DEPTH_TEST);

	return 0;
}


void Application::addKeyCallback(GLFWkeyfun callback) {
	glfwSetKeyCallback(window, callback);
}

GLFWwindow* Application::getWindow() {
	return window;
}


void Application::setActiveScene(Scene* scene) {
	this->activeScene = scene;
	this->activeScene->startGameObjects();
}

void Application::startFrame() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Application::endFrame() {
	if (this->activeScene != nullptr) {
		this->activeScene->updateGameObjects();

		this->activeScene->draw();
	}

	glfwSwapBuffers(window);
	glfwPollEvents();
}


bool Application::running() {
	return !glfwWindowShouldClose(window);
}


void Application::run() {
	while (this->running()) {
		this->startFrame();
		this->endFrame();
	}
}









void Application::setupScenes() {
	Scene* scene = new Scene();
	scenes["triangle"] = scene;

	this->setActiveScene(scene);
}
void Application::setupShaders() {
	ShaderProgram* shaderProgram = new ShaderProgram("Assets/shaders/basic.vert", "Assets/shaders/basic.frag");
	shaderPrograms.push_back(shaderProgram);
}
void Application::setupDrawableObjects() {
	DrawableObject* drawableObject = new Triangle(shaderPrograms[0]);
	drawableObjects.push_back(drawableObject);

	if (this->activeScene != nullptr) {
		this->activeScene->addObject(drawableObject);
	}
}