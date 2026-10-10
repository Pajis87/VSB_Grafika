#include "TriangleSwitched.h"
#include "Rotation.h"
#include "Translation.h"


TriangleSwitched::TriangleSwitched(Model* model, ShaderProgram* shaderProgram) : DrawableObject(model, shaderProgram) {
	y_rotation_transform = new Rotation(0.0f, glm::vec3(0.0f, 0.0f, 1.0f));
	transform.add(y_rotation_transform);
	transform.add(new Translation(glm::vec3(0.4f, 0.0f, 0.0f)));
}

void TriangleSwitched::update() {
	y_rotation_angle += 0.5f;
	y_rotation_transform->setAngle(y_rotation_angle);
}