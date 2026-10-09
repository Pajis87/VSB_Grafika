// This file was created by Pavel Brazda - BRA0241

#ifndef MODEL_H
#define MODEL_H

#include "gl_includer.h"

class Model {
public:
	Model(std::span<const float> vertexData, std::vector<int> attributeSizes);
	void setStride(int stride);
	void draw();

protected:
	static int modelIndex;
	GLuint vao;
	GLuint vbo;
	std::span<const float> vertexData;
	int stride;
};

#endif