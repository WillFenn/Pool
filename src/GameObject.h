#pragma once

#include <vec2.hpp>
#include <Texture.h>

enum Shape { Rectangle, Sphere };

class GameObject {
public:
	GameObject(Shape shape, glm::vec2 pos, glm::vec2 scale, glm::mat4 rotationMat, Texture* texture) {
		this->shape = shape;
		this->pos = pos;
		this->scale = scale;
		this->rotationMat = rotationMat;
		this->texture = texture;
	}
	GameObject() {};

	~GameObject() {
		delete texture;
	}

	Shape shape;
	glm::vec2 pos;
	glm::vec2 scale;
	glm::mat4 rotationMat;
	Texture* texture;
};