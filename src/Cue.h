#pragma once

#include <GameObject.h>
#include <Texture.h>

struct Cue : public GameObject {
public:
	Cue(glm::vec2 pos, Texture* texture) {
		shape = Shape::Rectangle;
		this->pos = pos;
		scale = { 10.0f, 0.2f };
		this->texture = texture;
		speed = 0.0f;

		// delete
		//rotationMat = PoolMath::addToRotationMat(glm::mat4(1.0f), glm::pi<float>() / 2, glm::vec3(0.0f, 1.0f, 0.0f));

		rotationMat = glm::mat4(1.0f);
		wasPulledBack = false;
	}
	Cue() {}

	float speed;
	bool wasPulledBack;
};