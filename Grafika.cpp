// This file was created by Pavel Brazda - BRA0241

#include "MyApplication.cpp"

int main() {
    MyApplication* app = new MyApplication();

	app->init();
    app->setupScenes();
    app->setupGameObjects();

    app->run();

    return 0;
}