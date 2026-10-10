// This file was mostly created by Pavel Brazda - BRA0241 (exceptions are annotated)

#include "Application.h"
#include "CustomObjects/Triangle.h"
#include "CustomObjects/TriangleSwitched.h"
#include "CustomObjects/Sun.h"
#include "CustomObjects/Earth.h"
#include "CustomObjects/Moon.h"
#include "Assets/models/sphere.h"
#include "Assets/models/tree.h"
#include "Assets/models/bush.h"
#include "Assets/models/earth.h"
#include "Assets/models/sun.h"
#include "Assets/models/moon.h"
#include "Rotation.h"
#include "Translation.h"
#include "Scale.h"

Application* Application::instance = nullptr;
Application* Application::getInstance() {
	if (instance == nullptr) {
		instance = new Application();
	}
	return instance;
}

Application::Application() : window(nullptr), activeScene(nullptr) {}

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
	Scene* triangle = new Scene();
	scenes["triangle"] = triangle;
	scenes["triangle_switched"] = new Scene();
	scenes["sphere"] = new Scene();
	scenes["forest"] = new Scene();
	scenes["solar_system"] = new Scene();

	this->setActiveScene(triangle);
}

void Application::setupShaders() {
	shaderPrograms["basic"] = new ShaderProgram("Assets/shaders/basic.vert", "Assets/shaders/basic.frag");;
	shaderPrograms["green"] = new ShaderProgram("Assets/shaders/basic.vert", "Assets/shaders/green.frag");
}

void Application::setupModels() {
	float points[] = {
		0.0f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
	   -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f
	};

	models["triangle"] = new Model(points, { 3, 3 });
	models["sphere"] = new Model(sphere, { 3, 3 });
	models["tree"] = new Model(tree, { 3, 3 });
	models["bush"] = new Model(bush, { 3, 3 });
	models["sun"] = new Model(sun, { 3, 3, 3 });
	models["earth"] = new Model(earth, { 3, 3, 3 });
	models["moon"] = new Model(moon, { 3, 3, 3 });
}

void Application::setupDrawableObjects() {
	// Triangle scene
	DrawableObject* triangle = new Triangle(models["triangle"], shaderPrograms["basic"]);
	drawableObjects["triangle"] = triangle;
	scenes["triangle"]->addObject(triangle);

	// Triangle switched scene
	DrawableObject* triangleSwitched = new TriangleSwitched(models["triangle"], shaderPrograms["basic"]); // TODO: change to some getter method to check that the model etc. exists
	drawableObjects["triangle_switched"] = triangleSwitched;
	scenes["triangle_switched"]->addObject(triangleSwitched);

	//Sphere scene
	DrawableObject* sphere = new DrawableObject(models["sphere"], shaderPrograms["basic"]);
	drawableObjects["sphere"] = sphere;
	scenes["sphere"]->addObject(sphere);

	//Forest scene
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 5; j++) {
			float tree_randomX = rand() % 200 / 100.0f - 1.0f;
			float tree_randomY = rand() % 200 / 100.0f - 1.0f;
			float tree_randomRotY = rand() % 10000 / 100.0f - 1.0f;
			float tree_randomRotZ = rand() % 1000 / 100.0f - 1.0f;
			float tree_randomScale = rand() % 100 / 1000.0f + 0.01f;

			DrawableObject* tree = new DrawableObject(models["tree"], shaderPrograms["basic"]);
			tree->transform.add(new Translation(glm::vec3(tree_randomX, tree_randomY, 0.0f)));
			tree->transform.add(new Rotation(tree_randomRotY, glm::vec3(0.0f, 1.0f, 0.0f)));
			tree->transform.add(new Rotation(tree_randomRotZ, glm::vec3(0.0f, 0.0f, 1.0f)));
			tree->transform.add(new Scale(glm::vec3(tree_randomScale, tree_randomScale, tree_randomScale)));
			drawableObjects["tree_" + std::to_string(i) + "_" + std::to_string(j)] = tree;
			scenes["forest"]->addObject(tree);


			float bush_randomX = rand() % 200 / 100.0f - 1.0f;
			float bush_randomY = rand() % 200 / 100.0f - 1.0f;
			float bush_randomRotY = rand() % 10000 / 100.0f - 1.0f;
			float bush_randomRotZ = rand() % 1000 / 100.0f - 1.0f;
			float bush_randomScale = rand() % 100 / 500.0f + 0.01f;

			DrawableObject* bush = new DrawableObject(models["bush"], shaderPrograms["basic"]);
			bush->transform.add(new Translation(glm::vec3(bush_randomX, bush_randomY, 0.0f)));
			bush->transform.add(new Rotation(bush_randomRotY, glm::vec3(0.0f, 1.0f, 0.0f)));
			bush->transform.add(new Rotation(bush_randomRotZ, glm::vec3(0.0f, 0.0f, 1.0f)));
			bush->transform.add(new Scale(glm::vec3(bush_randomScale, bush_randomScale, bush_randomScale)));
			drawableObjects["bush_" + std::to_string(i) + "_" + std::to_string(j)] = bush;
			scenes["forest"]->addObject(bush);
		}
	}

	//Solar system scene
	DrawableObject* sun = new Sun(models["sun"], shaderPrograms["basic"], -25.0f, -20.0f);
	drawableObjects["sun"] = sun;
	scenes["solar_system"]->addObject(sun);

	DrawableObject* earth = new Earth(models["earth"], shaderPrograms["basic"], (Sun*)sun, 23.5f);
	drawableObjects["earth"] = earth;
	scenes["solar_system"]->addObject(earth);

	DrawableObject* moon = new Moon(models["moon"], shaderPrograms["basic"], (Sun*)sun, (Earth*)earth);
	drawableObjects["moon"] = moon;
	scenes["solar_system"]->addObject(moon);
}


void callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	Application::getInstance()->keyCallback(window, key, scancode, action, mods);
}

void Application::setupCallbacks() {
	glfwSetKeyCallback(window, callback);
}

void Application::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GL_TRUE);
	}

	if (key == GLFW_KEY_1 && action == GLFW_PRESS) {
		setActiveScene(scenes.at("triangle"));
	}

	if (key == GLFW_KEY_2 && action == GLFW_PRESS) {
		setActiveScene(scenes.at("triangle_switched"));
	}

	if (key == GLFW_KEY_3 && action == GLFW_PRESS) {
		setActiveScene(scenes.at("sphere"));
	}

	if (key == GLFW_KEY_4 && action == GLFW_PRESS) {
		setActiveScene(scenes.at("forest"));
	}

	if (key == GLFW_KEY_5 && action == GLFW_PRESS) {
		setActiveScene(scenes.at("solar_system"));
	}
}


