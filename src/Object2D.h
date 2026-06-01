#pragma once

#include <vec2.hpp>
#include <Texture.h>

enum Shape { Rectangle, Circle };

class Object2D {
public:
	~Object2D() {
		delete texture;
	}

	Shape shape;
	glm::vec2 pos;
	glm::vec2 scale;
	Texture* texture;
};