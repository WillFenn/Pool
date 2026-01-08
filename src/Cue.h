#pragma once

#include <vec2.hpp>
#include <vec4.hpp>

struct Cue {
	glm::vec2 pos;
	glm::vec2 scale;
	float speed;
	float rotation;
	glm::vec4 color;
	glm::vec2 distanceFromCueBall;
};