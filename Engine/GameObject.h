// This file was created by Pavel Brazda - BRA0241

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "Vector3.h"
#include "ShaderProgram.h"

class GameObject {
public:
	Vector3 position;
	Vector3 rotation;
	
	void setShaderProgram(ShaderProgram *shaderProgram) {
		this->shaderProgram = shaderProgram;
	}
	void setStride(int stride) {
		this->stride = stride;
	}
	void draw() {
		this->shaderProgram->setVec3Variable("offset", position.x, position.y, position.z);

		glUseProgram(shaderProgram->getShaderProgram());
		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, vertexData.size_bytes() / stride);
	}

	virtual void update() {
		
	}

protected:
	GameObject(std::span<const float> vertexData, std::vector<int> attributeSizes) {
		this->vao = GameObject::objectIndex;
		this->vbo = GameObject::objectIndex;
		this->vertexData = vertexData;
		this->position = Vector3(0.0f, 0.0f, 0.0f);
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

	static int objectIndex;
	GLuint vao;
	GLuint vbo;
	ShaderProgram *shaderProgram;
	std::span<const float> vertexData;
	int stride;
};

int GameObject::objectIndex = 0;

#endif