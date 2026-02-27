#pragma once

#include <vec2.hpp>
#include <Rotation.h>

enum BallType { Unassigned, Striped, Solid };

struct Ball {
	int index;
	glm::vec2 pos;
	Rotation rotation;
	glm::vec2 velocity;
	glm::vec4 color;
	BallType ballType;
};