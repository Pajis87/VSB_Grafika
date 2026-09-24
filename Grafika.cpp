#include "EasyGL.h"
#include "models/gift.h"

int main() {
    EasyGL app;
    app.init(800, 600, "ZPG");

    GLuint shaderProgram = app.createShaders("shaders/shifted.vert", "shaders/red.frag");
	RenderMesh model = app.createModel(gift, { 3, 3 });

    while (app.running()) {
		app.startFrame();

		glUseProgram(shaderProgram);
        glBindVertexArray(model.vao);
        glDrawArrays(GL_TRIANGLES, 0, sizeof(gift) / 6);

        app.endFrame();
    }

    exit(EXIT_SUCCESS);
}