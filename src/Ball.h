#pragma once

#include <vec2.hpp>
#include <GameObject.h>
#include <Texture.h>

enum BallType { Unassigned, Striped, Solid };

class Ball : public GameObject {
public:
	Ball(glm::vec2 pos, Texture* texture, int index, BallType ballType) {
		shape = Shape::Sphere;
		this->pos = pos;
		scale = { 1.0f, 1.0f };
		this->texture = texture;
		this->index = index;
		this->ballType = ballType;
		velocity = { 0.0f, 0.0f };
		rotationMat = PoolMath::addToRotationMat(glm::mat4(1.0f), glm::pi<float>() / 2, glm::vec3(0.0f, 1.0f, 0.0f));
	}
	Ball() {}

	int index;
	BallType ballType;
	glm::vec2 velocity;
};