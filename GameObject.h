#include "includer.h"
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

class GameObject {
public:
	GLuint vao;
	GLuint vbo;
	GLuint shaderProgram;
	std::span<const float> vertexData;
	int stride;


	GameObject(std::span<const float> vertexData, std::vector<int> attributeSizes) {
		this->vao = GameObject::objectIndex;
		this->vbo = GameObject::objectIndex;
		this->vertexData = vertexData;
		GameObject::objectIndex++;

		glGenBuffers(1, &this->vbo);
		glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
		glBufferData(GL_ARRAY_BUFFER, vertexData.size_bytes(), vertexData.data(), GL_STATIC_DRAW);

		glGenVertexArrays(1, &this->vao);
		glBindVertexArray(this->vao);


		int totalComponents = 0;
		for (int size : attributeSizes) {
			totalComponents += size;
		}
		const int stride = totalComponents * sizeof(float);
		this->setStride(stride);


		int byteOffset = 0;
		for (GLuint i = 0; i < static_cast<GLuint>(attributeSizes.size()); ++i) {
			glEnableVertexAttribArray(i);
			glVertexAttribPointer(
				i,
				attributeSizes[i],
				GL_FLOAT,
				GL_FALSE,
				stride,
				(GLvoid*)byteOffset
			);
			byteOffset += attributeSizes[i] * sizeof(float);
		}
		glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
	}
	void setShaderProgram(GLuint shaderProgram) {
		this->shaderProgram = shaderProgram;
	}
	void setStride(int stride) {
		this->stride = stride;
	}
	void draw() {
		glUseProgram(shaderProgram);
		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, vertexData.size_bytes() / stride);
	}
private:
	static int objectIndex;
};

int GameObject::objectIndex = 0;



#endif