#include "EasyGL.h"
#include "models/gift.h"
#include "models/mytree.h"

int main() {
    EasyGL app;
    app.init(800, 600, "ZPG");

    GLuint shaderProgram1 = app.createShaders("shaders/basic.vert", "shaders/basic.frag");
    RenderMesh tree = app.createModel(mytree, { 3, 3 });
	tree.setShaderProgram(shaderProgram1);

    GLuint shaderProgram2 = app.createShaders("shaders/shifted.vert", "shaders/red.frag");
    GLuint shaderProgram3 = app.createShaders("shaders/shifted2.vert", "shaders/green.frag");

    RenderMesh gift_model1 = app.createModel(gift, { 3, 3 });
    gift_model1.setShaderProgram(shaderProgram2);


    while (app.running()) {
		app.startFrame();


        tree.draw();

        gift_model1.setShaderProgram(shaderProgram2);
		gift_model1.draw();

        gift_model1.setShaderProgram(shaderProgram3);
        gift_model1.draw();


        app.endFrame();
    }

    exit(EXIT_SUCCESS);
}