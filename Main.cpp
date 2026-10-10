// This file was created by Pavel Brazda - BRA0241

#include "Application.h"

int main() {
    Application* app = Application::getInstance();

	app->init(800, 800, "ZPG");
	app->setupScenes();
	app->setupShaders();
	app->setupModels();
	app->setupDrawableObjects();
	app->setupCallbacks();
    app->run();

    return 0;
}