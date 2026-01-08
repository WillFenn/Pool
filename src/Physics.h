#pragma once

#include <vector>
#include <vec2.hpp>
#include <vec3.hpp>
#include <ext/matrix_transform.hpp>
#include <Ball.h>
#include <Cue.h>

class Physics {
public:
	Physics();
	~Physics();
	void update(std::vector<Ball>* balls, Ball* cueBall, Cue* cue, float deltaTime);

private:
	bool detectBallCollision(Ball* ball1, Ball* ball2, glm::vec2* collisionNormal);
	bool detectBallSideCollision(Ball* ball, glm::vec2* collisionNormal);
	void resolveBallCollision(Ball* ball1, Ball* ball2, glm::vec2* collisionNormal);
	void resolveBallSideCollision(Ball* ball, glm::vec2* collisionNormal);
};