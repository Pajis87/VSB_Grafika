// This file was created by Pavel Brazda - BRA0241

#include "Application.h"

int main() {
    Application* app = new Application();

	app->init(800, 600, "ZPG");

    app->run();

    return 0;
}