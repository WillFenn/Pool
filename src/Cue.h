#pragma once

#include <Object2D.h>
#include <Texture.h>

struct Cue : public Object2D {
public:
	Cue(glm::vec2 pos, Texture* texture) {
		shape = Shape::Rectangle;
		this->pos = pos;
		scale = { 10.0f, 0.2f };
		this->texture = texture;
		speed = 0.0f;
		rotation = 0.0f;
		wasPulledBack = false;
	}
	Cue() {}

	float speed;
	float rotation;
	bool wasPulledBack;
};