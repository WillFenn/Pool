#pragma once

#include <vec2.hpp>
#include <GameObject.h>
#include <string>
#include <Texture.h>
#include <PoolMath.h>

enum BallType { Unassigned, Striped, Solid };

class Ball : public GameObject {
public:
	Ball(glm::vec2 pos, std::string textureFilepath, bool flipTexture, int index, BallType ballType);
	Ball();
	int getIndex();
	BallType getBallType();
	glm::vec2 getVelocity();
	void setVelocity(glm::vec2 velocity);

private:
	int index;
	BallType ballType;
	glm::vec2 velocity;
};