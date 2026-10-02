// This file was mostly created by Pavel Brazda - BRA0241 (exceptions are annotated)


#include "includer.h"
#include "Scene.h"
#include "GameObject.h"

class EasyGL {
public:
	int init(int width, int height, const char* title) {
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


	void addKeyCallback(GLFWkeyfun callback) {
		glfwSetKeyCallback(window, callback);
	}

	// umožní získat okno z venku (např. pro nastavení user pointeru nebo callbacku)
	GLFWwindow* getWindow() {
		return window;
	}


	void setActiveScene(Scene* scene) {
		this->activeScene = scene;
	}
	

	void startFrame() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void endFrame() {
		if (this->activeScene != nullptr) {
			this->activeScene->draw();
		}

		glfwSwapBuffers(window);
		glfwPollEvents();
	}


	bool running() {
		return !glfwWindowShouldClose(window);
	}
private:
	GLFWwindow* window;
	Scene* activeScene = nullptr;
};
