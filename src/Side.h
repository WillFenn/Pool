#pragma once

#include <vec2.hpp>
#include <Line.h>

class Side : public Line {
public:
	Side(glm::vec2 a, glm::vec2 b, glm::vec2 normal) {
		this->a = a;
		this->b = b;
		this->normal = normal;
	}
	Side() {}

	glm::vec2 normal;
};