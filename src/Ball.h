#pragma once

#include <vec2.hpp>
#include <Texture.h>

enum BallType { Unassigned, Striped, Solid };

struct Ball {
	int index;
	glm::vec2 pos;
	glm::mat4 rotationMat;
	glm::vec2 velocity;
	BallType ballType;
	Texture* texture;
};