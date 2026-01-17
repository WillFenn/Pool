#include <Physics.h>

Physics::Physics() {

}

Physics::~Physics() {

}

void Physics::update(std::vector<Ball>* balls, Ball* cueBall, Cue* cue, float deltaTime) {
	// stop ball if its speed is close to zero
	if ((glm::length(cueBall->velocity) < 0.05f)) {
		cueBall->velocity = { 0.0f, 0.0f };
	}

	for (int i = 0; i < balls->size(); i++) {
		if (glm::length(balls->at(i).velocity) < 0.05f) {
			balls->at(i).velocity = { 0.0f, 0.0f };
		}
	}
	
	// apply friction
	if (glm::length(cueBall->velocity) > 0) {
		glm::vec2 newVelocity = cueBall->velocity - glm::normalize(cueBall->velocity) * frictionAcceleration * deltaTime;

		if (glm::dot(cueBall->velocity, newVelocity) > 0) {
			cueBall->velocity = newVelocity;
		}
		else {
			cueBall->velocity = { 0.0f, 0.0f };
		}
	}

	for (int i = 0; i < balls->size(); i++) {
		if (glm::length(balls->at(i).velocity) > 0) {
			glm::vec2 newVelocity = balls->at(i).velocity - glm::normalize(balls->at(i).velocity) * frictionAcceleration * deltaTime;

			if (glm::dot(balls->at(i).velocity, newVelocity) > 0) {
				balls->at(i).velocity = newVelocity;
			}
			else {
				balls->at(i).velocity = { 0.0f, 0.0f };
			}
		}
	}
	
	// update positions
	std::cout << "cue speed: " << cue->speed << std::endl;	// delete
	std::cout << "cue ball speed: " << glm::length(cueBall->velocity) << std::endl;	// delete

	cue->pos += glm::normalize(cueBall->pos - cue->pos) * cue->speed * deltaTime;

	cueBall->pos += cueBall->velocity * deltaTime;
	
	for (int i = 0; i < balls->size(); i++) {
		balls->at(i).pos += balls->at(i).velocity * deltaTime;
	}
	
	// collision between cue and cue ball
	if (glm::distance(cue->pos, cueBall->pos) <= ((cue->scale.x / 2) + 0.5f) && cue->speed != 0.0f) {
		std::cout << "collision between cue and cue ball" << std::endl;	// delete

		cueBall->velocity = glm::normalize(cueBall->pos - cue->pos) * cue->speed;
		cue->speed = 0.0f;
	}

	// collisions between balls
	glm::vec2 collisionNormal(0.0f, 0.0f);

	for (int i = 0; i < balls->size(); i++) {
		if (detectBallCollision(cueBall, &balls->at(i), &collisionNormal)) {
			std::cout << "collision between ball and cue ball" << std::endl;	// delete
			std::cout << "ball speed before collision: " << glm::length(balls->at(i).velocity) << "     cue ball speed before collision: " << glm::length(cueBall->velocity) << std::endl;	// delete

			resolveBallCollision(cueBall, &balls->at(i), &collisionNormal);

			std::cout << "ball speed after collision: " << glm::length(balls->at(i).velocity) << "     cue ball speed after collision: " << glm::length(cueBall->velocity) << std::endl;	// delete
		}
	}

	for (int i = 0; i < balls->size(); i++) {
		for (int j = i + 1; j < balls->size(); j++) {
			if (detectBallCollision(&balls->at(i), &balls->at(j), &collisionNormal)) {
				std::cout << "collision between balls" << std::endl;	// delete
				std::cout << "ball1 speed before collision: " << glm::length(balls->at(i).velocity) << "     ball2 speed before collision: " << glm::length(balls->at(j).velocity) << std::endl;	// delete

				resolveBallCollision(&balls->at(i), &balls->at(j), &collisionNormal);

				std::cout << "ball1 speed after collision: " << glm::length(balls->at(i).velocity) << "     ball2 speed after collision: " << glm::length(balls->at(j).velocity) << std::endl;	// delete
			}
		}
	}

	// collisions between balls and sides
	std::vector<glm::vec2> collisionNormals;

	if (detectBallSideCollision(cueBall, &collisionNormals)) {
		std::cout << "collision between ball and side" << std::endl;	// delete

		resolveBallSideCollision(cueBall, &collisionNormals);

		collisionNormals.clear();
	}

	for (int i = 0; i < balls->size(); i++) {
		if (detectBallSideCollision(&balls->at(i), &collisionNormals)) {
			std::cout << "collision between ball and side" << std::endl;	// delete

			resolveBallSideCollision(&balls->at(i), &collisionNormals);

			collisionNormals.clear();
		}
	}
}

bool Physics::detectBallCollision(Ball* ball1, Ball* ball2, glm::vec2* outCollisionNormal) {
	if (glm::length(ball1->pos - ball2->pos) <= 1.0f && glm::length(ball1->velocity - ball2->velocity) != 0.0f) {
		*outCollisionNormal = glm::normalize(ball2->pos - ball1->pos);

		return true;
	}

	return false;
}

bool Physics::detectBallSideCollision(Ball* ball, std::vector<glm::vec2>* outCollisionNormals) {
	if (ball->pos.x - 0.5f <= -24.0f) {
		outCollisionNormals->push_back(glm::vec2(-1.0f, 0.0f));
	}

	if (ball->pos.x + 0.5f >= 24.0f) {
		outCollisionNormals->push_back(glm::vec2(1.0f, 0.0f));
	}

	if (ball->pos.y + 0.5f >= 13.5f) {
		outCollisionNormals->push_back(glm::vec2(0.0f, 1.0f));
	}

	if (ball->pos.y - 0.5f <= -13.5f) {
		outCollisionNormals->push_back(glm::vec2(0.0f, -1.0f));
	}

	return outCollisionNormals->size() != 0;
}

void Physics::resolveBallCollision(Ball* ball1, Ball* ball2, glm::vec2* collisionNormal) {
	std::cout << "collision normal x: " << collisionNormal->x << "     collision normal y: " << collisionNormal->y << std::endl;	// delete
	std::cout << "collision normal magnitude: " << glm::length(*collisionNormal) << std::endl;	// delete
	
	float elasticity = 0.8f;

	glm::vec2 relativeVelocity = ball2->velocity - ball1->velocity;
	float impulseMagnitude = -((1 + elasticity) * glm::dot(relativeVelocity, *collisionNormal)) / 2;

	std::cout << "impulse magnitude: " << impulseMagnitude << std::endl;	// delete
	
	ball1->velocity -= impulseMagnitude * *collisionNormal;
	ball2->velocity += impulseMagnitude * *collisionNormal;
}

void Physics::resolveBallSideCollision(Ball* ball, std::vector<glm::vec2>* collisionNormals) {
	float elasticity = 0.8f;

	for (int i = 0; i < collisionNormals->size(); i++) {
		glm::vec2 relativeVelocity = -ball->velocity;
		float impulseMagnitude = -((1 + elasticity) * glm::dot(relativeVelocity, collisionNormals->at(i)));

		ball->velocity -= impulseMagnitude * collisionNormals->at(i);
	}
}