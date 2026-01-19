#pragma once

#include <vec2.hpp>

struct Ball {
	int index;
	glm::vec2 pos;
	glm::vec2 velocity;
	glm::vec4 color;
	bool striped;
};