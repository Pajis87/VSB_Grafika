// This file was created by Pavel Brazda - BRA0241

#include "Application.h"
#include "CustomObjects/Triangle.h"
#include "CustomObjects/TriangleSwitched.h"
#include "CustomObjects/Sun.h"
#include "CustomObjects/Earth.h"
#include "CustomObjects/Moon.h"
#include "CustomObjects/Clock.h"
#include "Assets/models/sphere.h"
#include "Assets/models/tree.h"
#include "Assets/models/bush.h"
#include "Assets/models/earth.h"
#include "Assets/models/sun.h"
#include "Assets/models/moon.h"
#include "Assets/models/login.h"
#include "Assets/models/clock.h"
#include "Rotation.h"
#include "Translation.h"
#include "Camera.h"
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

		if (forwardSpeed != 0.0) {
			cameras["main"]->moveForward(glm::vec3(0.0, 0.0, forwardSpeed));
		}
		if (rightSpeed != 0.0) {
			cameras["main"]->moveForward(glm::vec3(rightSpeed, 0.0, 0.0));
		}

		this->endFrame();
	}
}






void Application::createScenes() {
	Scene* triangle = new Scene();
	scenes["triangle"] = triangle;
	scenes["triangle_switched"] = new Scene();
	scenes["sphere"] = new Scene();
	scenes["forest"] = new Scene();
	scenes["solar_system"] = new Scene();
	scenes["login"] = new Scene();
	scenes["clock"] = new Scene();

	this->setActiveScene(triangle);
}

void Application::setupCameras() {
	cameras["main"] = new Camera();
}

void Application::setupShaders() {
	shaderPrograms["basic"] = new ShaderProgram("Assets/shaders/basic.vert", "Assets/shaders/basic.frag");
	shaderPrograms["green"] = new ShaderProgram("Assets/shaders/basic.vert", "Assets/shaders/green.frag");
	shaderPrograms["tree"] = new ShaderProgram("Assets/shaders/tree.vert", "Assets/shaders/basic.frag");
	shaderPrograms["gray"] = new ShaderProgram("Assets/shaders/basic.vert", "Assets/shaders/gray.frag");
	shaderPrograms["clock"] = new ShaderProgram("Assets/shaders/clock.vert", "Assets/shaders/basic.frag");
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
	models["login"] = new Model(login, { 3, 3 });
	models["clock"] = new Model(clockModel, { 3, 3, 3 });
}

void Application::setupDrawableObjects() {
	DrawableObject* small_login = new DrawableObject(models["login"], shaderPrograms["gray"]);
	small_login->transform.add(new Translation(glm::vec3(0.8f, -0.9f, -0.8f)));
	small_login->transform.add(new Scale(glm::vec3(0.1f, 0.1f, 0.1f)));
	drawableObjects["login"] = small_login;

	// Triangle scene
	DrawableObject* triangle = new Triangle(models["triangle"], shaderPrograms["basic"]);
	drawableObjects["triangle"] = triangle;
	scenes["triangle"]->addObject(triangle);
	scenes["triangle"]->addObject(small_login);

	// Triangle switched scene
	DrawableObject* triangleSwitched = new TriangleSwitched(models["triangle"], shaderPrograms["basic"]);
	drawableObjects["triangle_switched"] = triangleSwitched;
	scenes["triangle_switched"]->addObject(triangleSwitched);
	scenes["triangle_switched"]->addObject(small_login);

	//Sphere scene
	DrawableObject* sphere = new DrawableObject(models["sphere"], shaderPrograms["basic"]);
	drawableObjects["sphere"] = sphere;
	scenes["sphere"]->addObject(sphere);
	scenes["sphere"]->addObject(small_login);

	//Forest scene
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 5; j++) {
			float tree_randomX = rand() % 200 / 100.0f - 1.0f;
			float tree_randomY = rand() % 200 / 100.0f - 1.0f;
			float tree_randomRotY = rand() % 10000 / 100.0f - 1.0f;
			float tree_randomRotZ = rand() % 1000 / 100.0f - 1.0f;
			float tree_randomScale = rand() % 100 / 1000.0f + 0.01f;

			DrawableObject* tree = new DrawableObject(models["tree"], shaderPrograms["tree"]);
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

			DrawableObject* bush = new DrawableObject(models["bush"], shaderPrograms["green"]);
			bush->transform.add(new Translation(glm::vec3(bush_randomX, bush_randomY, 0.0f)));
			bush->transform.add(new Rotation(bush_randomRotY, glm::vec3(0.0f, 1.0f, 0.0f)));
			bush->transform.add(new Rotation(bush_randomRotZ, glm::vec3(0.0f, 0.0f, 1.0f)));
			bush->transform.add(new Scale(glm::vec3(bush_randomScale, bush_randomScale, bush_randomScale)));
			drawableObjects["bush_" + std::to_string(i) + "_" + std::to_string(j)] = bush;
			scenes["forest"]->addObject(bush);
		}
	}
	scenes["forest"]->addObject(small_login);

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
	scenes["solar_system"]->addObject(small_login);

	//Login scene
	DrawableObject* login = new DrawableObject(models["login"], shaderPrograms["gray"]);
	login->transform.add(new Scale(glm::vec3(0.5f, 0.5f, 0.5f)));
	drawableObjects["login"] = login;
	scenes["login"]->addObject(login);

	//Clock scene
	DrawableObject* clock = new Clock(models["clock"], shaderPrograms["clock"]);
	clock->transform.add(new Rotation(180, glm::vec3(0.0f, 1.0f, 0.0f)));
	clock->transform.add(new Scale(glm::vec3(-0.8f, 0.8f, 0.8f)));
	drawableObjects["clock"] = clock;
	scenes["clock"]->addObject(clock);
}

void Application::setupScenes() {
	scenes["triangle"]->setActiveCamera(cameras["main"]);
	scenes["triangle_switched"]->setActiveCamera(cameras["main"]);
	scenes["sphere"]->setActiveCamera(cameras["main"]);
	scenes["forest"]->setActiveCamera(cameras["main"]);
	scenes["solar_system"]->setActiveCamera(cameras["main"]);
	scenes["login"]->setActiveCamera(cameras["main"]);
	scenes["clock"]->setActiveCamera(cameras["main"]);
}



void keyCallbackCaller(GLFWwindow* window, int key, int scancode, int action, int mods) {
	Application::getInstance()->keyCallback(window, key, scancode, action, mods);
}

void mouseButtonCallbackCaller(GLFWwindow* window, int button, int action, int mods) {
	Application::getInstance()->mouseButtonCallback(window, button, action, mods);
}

void cursorPositionCallbackCaller(GLFWwindow* window, double xpos, double ypos) {
	Application::getInstance()->cursorPositionCallback(window, xpos, ypos);
}



void Application::setupCallbacks() {
	glfwSetKeyCallback(window, keyCallbackCaller);
	glfwSetMouseButtonCallback(window, mouseButtonCallbackCaller);
	glfwSetCursorPosCallback(window, cursorPositionCallbackCaller);
}



void Application::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
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

	if (key == GLFW_KEY_6 && action == GLFW_PRESS) {
		setActiveScene(scenes.at("login"));
	}

	if (key == GLFW_KEY_7 && action == GLFW_PRESS) {
		setActiveScene(scenes.at("clock"));
	}

	if (key == GLFW_KEY_W && action == GLFW_PRESS) {
		forwardSpeed += 0.05f;
	}
	if (key == GLFW_KEY_S && action == GLFW_PRESS) {
		forwardSpeed -= 0.05f;
	}
	if (key == GLFW_KEY_D && action == GLFW_PRESS) {
		rightSpeed += 0.05f;
	}
	if (key == GLFW_KEY_A && action == GLFW_PRESS) {
		rightSpeed -= 0.05f;
	}

	if (key == GLFW_KEY_W && action == GLFW_RELEASE) {
		forwardSpeed -= 0.05f;
	}
	if (key == GLFW_KEY_S && action == GLFW_RELEASE) {
		forwardSpeed += 0.05f;
	}
	if (key == GLFW_KEY_D && action == GLFW_RELEASE) {
		rightSpeed -= 0.05f;
	}
	if (key == GLFW_KEY_A && action == GLFW_RELEASE) {
		rightSpeed += 0.05f;
	}
}

void Application::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {
		rightMouseButtonDown = true;
	}
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE) {
		rightMouseButtonDown = false;
	}
}

void Application::cursorPositionCallback(GLFWwindow* window, double xpos, double ypos) {
	float offsetX = lastCursorX - xpos;
	float offsetY = lastCursorY - ypos;

	if (rightMouseButtonDown) {
		cameras["main"]->addRotationOffset(glm::vec3(-offsetY * 0.1f, offsetX * 0.1f, 0.0f));
	}

	lastCursorX = xpos;
	lastCursorY = ypos;
}


