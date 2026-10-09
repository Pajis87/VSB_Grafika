// This file was created by Pavel Brazda - BRA0241

#include "Model.h"

Model::Model(std::span<const float> vertexData, std::vector<int> attributeSizes) {
	this->vao = Model::modelIndex;
	this->vbo = Model::modelIndex;
	this->vertexData = vertexData;
	Model::modelIndex++;

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


void Model::setStride(int stride) {
	this->stride = stride;
}

void Model::draw() {
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, vertexData.size_bytes() / stride);
}

int Model::modelIndex = 0;