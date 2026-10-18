// This file was created by Pavel Brazda - BRA0241

#include "Application.h"

int main() {
    Application* app = Application::getInstance();

	app->init(1600, 900, "ZPG");
	app->createScenes();
	app->setupCameras();
	app->setupShaders();
	app->setupModels();
	app->setupDrawableObjects();
	app->setupScenes();
	app->setupCallbacks();
    app->run();

    return 0;
}