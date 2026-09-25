#include "EasyGL.h"
#include "models/gift.h"
#include "models/mytree.h"
#include "models/sphere.h"

int main() {
    EasyGL app;
    app.init(800, 800, "ZPG");


    // Square
    /*float points[] = {
        -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
        0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f,

		-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
        -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
    };

    GLuint shaderProgram = app.createShaders("shaders/basic.vert", "shaders/basic.frag");
	RenderMesh square = app.createModel(points, { 3, 3 });
	square.setShaderProgram(shaderProgram);*/


    // Sphere
    /*GLuint shaderProgram = app.createShaders("shaders/basic.vert", "shaders/basic.frag");
    RenderMesh sphere_model = app.createModel(sphere, { 3, 3 });
    sphere_model.setShaderProgram(shaderProgram);*/


	// Tree and Gift scene
    GLuint shaderProgram1 = app.createShaders("shaders/tree.vert", "shaders/basic.frag");
    RenderMesh tree = app.createModel(mytree, { 3, 3 });
	tree.setShaderProgram(shaderProgram1);

    GLuint shaderProgram2 = app.createShaders("shaders/shifted.vert", "shaders/red.frag");
    GLuint shaderProgram3 = app.createShaders("shaders/shifted2.vert", "shaders/blue.frag");

    RenderMesh gift_model1 = app.createModel(gift, { 3, 3 });
    gift_model1.setShaderProgram(shaderProgram2);


    while (app.running()) {
		app.startFrame();

		//square.draw();
        //sphere_model.draw();

        tree.draw();

        gift_model1.setShaderProgram(shaderProgram2);
		gift_model1.draw();

        gift_model1.setShaderProgram(shaderProgram3);
        gift_model1.draw();


        app.endFrame();
    }

    exit(EXIT_SUCCESS);
}