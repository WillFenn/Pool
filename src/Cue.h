#pragma once

#include <vec2.hpp>
#include <vec4.hpp>
#include <Texture.h>

struct Cue {
	glm::vec2 pos;
	glm::vec2 scale;
	float speed;
	float rotation;
	Texture* texture;
	bool wasPulledBack;
};