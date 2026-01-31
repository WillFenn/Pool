#pragma once

#include <vec2.hpp>

enum BallType { Unassigned, Striped, Solid };

struct Ball {
	int index;
	glm::vec2 pos;
	glm::vec2 velocity;
	glm::vec4 color;
	BallType ballType;
};