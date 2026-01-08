#include <Physics.h>

void Physics::update(std::vector<Ball>* balls, Ball* cueBall, Cue* cue, float deltaTime) {
	// update positions
	cue->pos += glm::normalize(cueBall->pos - cue->pos) * cue->speed * deltaTime;

	cueBall->pos += cueBall->velocity * deltaTime;
	
	for (int i = 0; i < balls->size(); i++) {
		balls->at(i).pos += balls->at(i).velocity * deltaTime;
	}
	
	// collision between cue and cue ball
	if (glm::distance(cue->pos, cueBall->pos) <= ((cue->scale.x / 2) + 0.5f)) {
		cue->speed = 0.0f;
		cueBall->velocity = glm::normalize(cueBall->pos - cue->pos) * cue->speed;
	}

	// collision between balls
	glm::vec2 collisionNormal(0.0f, 0.0f);

	for (int i = 0; i < balls->size(); i++) {
		if (detectBallCollision(cueBall, &balls->at(i), &collisionNormal)) {
			resolveBallCollision(cueBall, &balls->at(i), &collisionNormal);
		}
	}

	for (int i = 0; i < balls->size(); i++) {
		for (int j = i + 1; j < balls->size(); j++) {
			if (detectBallCollision(&balls->at(i), &balls->at(j), &collisionNormal)) {
				resolveBallCollision(&balls->at(i), &balls->at(j), &collisionNormal);
			}
		}
	}

	// collision between balls and sides
	if (detectBallSideCollision(cueBall, &collisionNormal)) {
		resolveBallSideCollision(cueBall, &collisionNormal);
	}

	for (int i = 0; i < balls->size(); i++) {
		if (detectBallSideCollision(&balls->at(i), &collisionNormal)) {
			resolveBallSideCollision(&balls->at(i), &collisionNormal);
		}
	}
}

bool Physics::detectBallCollision(Ball* ball1, Ball* ball2, glm::vec2* outCollisionNormal) {
	if (glm::length(ball1->pos - ball2->pos) <= 1.0f) {
		*outCollisionNormal = glm::normalize(ball2->pos - ball1->pos);

		return true;
	}
}

bool Physics::detectBallSideCollision(Ball* ball, glm::vec2* outCollisionNormal) {
	if (ball->pos.x - 0.5f <= -24.0f) {
		*outCollisionNormal = glm::vec2(-1.0f, 0.0f);
		
		return true;
	}

	if (ball->pos.x + 0.5f >= 24.0f) {
		*outCollisionNormal = glm::vec2(1.0f, 0.0f);

		return true;
	}

	if (ball->pos.y + 0.5f >= 13.5f) {
		*outCollisionNormal = glm::vec2(0.0f, 1.0f);

		return true;
	}

	if (ball->pos.y - 0.5f <= -13.5f) {
		*outCollisionNormal = glm::vec2(0.0f, -1.0f);

		return true;
	}

	return false;
}

void Physics::resolveBallCollision(Ball* ball1, Ball* ball2, glm::vec2* collisionNormal) {
	float elasticity = 0.5f;

	glm::vec2 relativeVelocity = ball1->velocity - ball2->velocity;
	float impulseMagnitude = -((1 + elasticity) * glm::dot(relativeVelocity, *collisionNormal)) / 2;
	
	ball1->velocity -= impulseMagnitude * *collisionNormal;
	ball2->velocity += impulseMagnitude * *collisionNormal;
}

void Physics::resolveBallSideCollision(Ball* ball, glm::vec2* collisionNormal) {
	float elasticity = 0.5f;

	float impulseMagnitude = -((1 + elasticity) * glm::dot(ball->velocity, *collisionNormal));

	ball->velocity -= impulseMagnitude * *collisionNormal;
}