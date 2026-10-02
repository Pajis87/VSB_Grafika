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

	GLuint createShaders(const char* vertexShaderFile, const char* fragmentShaderFile) {
		GLuint vertexShader = createShaderFromFile(GL_VERTEX_SHADER, vertexShaderFile);
		GLuint fragmentShader = createShaderFromFile(GL_FRAGMENT_SHADER, fragmentShaderFile);

		GLuint shaderProgram = glCreateProgram();
		glAttachShader(shaderProgram, fragmentShader);
		glAttachShader(shaderProgram, vertexShader);
		glLinkProgram(shaderProgram);

		return shaderProgram;
	}


	void startFrame() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void endFrame() {
		glfwSwapBuffers(window);
		glfwPollEvents();
	}


	bool running() {
		return !glfwWindowShouldClose(window);
	}
private:
	GLFWwindow* window;
	GLuint objectIndex = 0;


	// ==== THIS CODE WAS TAKEN FROM MARTIN NEMEC AT LMS.VSB.CZ vvv
	GLuint createShaderFromFile(GLenum shaderType, const char* shaderFile) {
		// Creates an empty shader
		GLuint shaderID = glCreateShader(shaderType);

		if (shaderID == 0) {
			std::cout << "Unable to create shader" << std::endl;
			exit(EXIT_FAILURE);
		}

		//Loading the contents of a file into a variable
		std::ifstream file(shaderFile);
		if (!file.is_open()) {
			std::cout << "Unable to open file " << shaderFile << std::endl;
			glDeleteShader(shaderID);
			exit(-1);
		}
		std::string shaderCode((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

		// Set the shader source code
		const char* source = shaderCode.c_str();
		glShaderSource(shaderID, 1, &source, nullptr);

		// Compile the shader source code
		glCompileShader(shaderID);

		// Check specialization/compilation status
		GLint success;
		glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
		if (!success) {
			char infoLog[1024];
			glGetShaderInfoLog(shaderID, sizeof(infoLog), nullptr, infoLog);
			std::cout
				<< "Shader failed:\n"
				<< infoLog << std::endl;
			glDeleteShader(shaderID);
			exit(1);
		}
		return shaderID;
	}
	// ==== THIS CODE WAS TAKEN FROM MARTIN NEMEC AT LMS.VSB.CZ ^^^
};
