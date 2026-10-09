// This file was created by Pavel Brazda - BRA0241

#include "Application.h"

int main() {
    Application* app = new Application();

	app->init(800, 800, "ZPG");
	app->setupScenes();
	app->setupShaders();
	app->setupDrawableObjects();
    app->run();

    return 0;
}