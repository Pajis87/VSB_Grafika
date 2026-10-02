#include "MyApplication.cpp"


struct AppData {
    EasyGL* app;
    Scene* triangleScene;
    Scene* sphereScene;
    Scene* treeScene;
};


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }

    if (key == GLFW_KEY_1 && action == GLFW_PRESS) {
        AppData *data = (AppData*)glfwGetWindowUserPointer(window);
        if (!data) return;
		data->app->setActiveScene(data->triangleScene);
    }

    if (key == GLFW_KEY_2 && action == GLFW_PRESS) {
        AppData* data = (AppData*)glfwGetWindowUserPointer(window);
        if (!data) return;
        data->app->setActiveScene(data->sphereScene);
    }

    if (key == GLFW_KEY_3&& action == GLFW_PRESS) {
        AppData* data = (AppData*)glfwGetWindowUserPointer(window);
        if (!data) return;
        data->app->setActiveScene(data->treeScene);
    }
}


float cycle(float time, float period) {
	return fmod(time, period);
};

int main() {
    /*EasyGL app;
    app.init(800, 800, "ZPG");


    float points[] = {
        0.0f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
       -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f
    };

    Scene triangleScene = Scene();
	GameObject triangle = GameObject(points, { 3, 3 });
	ShaderProgram triangleShaderProgram("shaders/basic.vert", "shaders/basic.frag");
	triangle.setShaderProgram(&triangleShaderProgram);
    triangleScene.addObject(triangle);



    Scene sphereScene = Scene();
    GameObject sphere_object = GameObject(sphere, { 3, 3 });
    ShaderProgram sphereShaderProgram("shaders/basic.vert", "shaders/basic.frag");
    sphere_object.setShaderProgram(&sphereShaderProgram);
    sphereScene.addObject(sphere_object);


    Scene treeScene = Scene();
    GameObject tree_object = GameObject(tree, { 3, 3 });
    ShaderProgram treeShaderProgram("shaders/basic.vert", "shaders/basic.frag");
    tree_object.setShaderProgram(&treeShaderProgram);
    treeScene.addObject(tree_object);


	app.setActiveScene(&triangleScene);



    AppData* data = new AppData{ &app, &triangleScene, &sphereScene };
    glfwSetWindowUserPointer(app.getWindow(), data);
    app.addKeyCallback(key_callback);


    while (app.running()) {
		app.startFrame();

        
        //triangleShaderProgram.setVec3Variable("offset", cycle(glfwGetTime(), 2.0f) - 1, 0.0f, 0.0f);


        app.endFrame();
    }*/


    MyApplication* app = new MyApplication();
	app->init();
    app->setupScenes();
    app->setupGameObjects();

    app->run();

    return 0;
}