#include <Physics.h>

Physics::Physics() {

}

Physics::~Physics() {

}

void Physics::update(Side sides[], std::vector<Ball>* balls, Ball* cueBall, Cue* cue, float deltaTime) {
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
	//std::cout << "cue speed: " << cue->speed << std::endl;	// delete
	//std::cout << "cue ball speed: " << glm::length(cueBall->velocity) << std::endl;	// delete

	cue->pos += glm::normalize(cueBall->pos - cue->pos) * cue->speed * deltaTime;

	cueBall->pos += cueBall->velocity * deltaTime;
	
	for (int i = 0; i < balls->size(); i++) {
		balls->at(i).pos += balls->at(i).velocity * deltaTime;
	}
	
	// collision between cue and cue ball
	if (glm::distance(cue->pos, cueBall->pos) <= ((cue->scale.x / 2) + 0.5f) && cue->speed != 0.0f) {
		//std::cout << "collision between cue and cue ball" << std::endl;	// delete

		cueBall->velocity = glm::normalize(cueBall->pos - cue->pos) * cue->speed;
		cue->speed = 0.0f;
	}

	// collisions between balls
	glm::vec2 collisionNormal(0.0f, 0.0f);

	for (int i = 0; i < balls->size(); i++) {
		if (detectBallCollision(cueBall, &balls->at(i), &collisionNormal)) {
			//std::cout << "collision between ball and cue ball" << std::endl;	// delete
			//std::cout << "ball speed before collision: " << glm::length(balls->at(i).velocity) << "     cue ball speed before collision: " << glm::length(cueBall->velocity) << std::endl;	// delete

			resolveBallCollision(cueBall, &balls->at(i), &collisionNormal);

			//std::cout << "ball speed after collision: " << glm::length(balls->at(i).velocity) << "     cue ball speed after collision: " << glm::length(cueBall->velocity) << std::endl;	// delete
		}
	}

	for (int i = 0; i < balls->size(); i++) {
		for (int j = i + 1; j < balls->size(); j++) {
			if (detectBallCollision(&balls->at(i), &balls->at(j), &collisionNormal)) {
				//std::cout << "collision between balls" << std::endl;	// delete
				//std::cout << "ball1 speed before collision: " << glm::length(balls->at(i).velocity) << "     ball2 speed before collision: " << glm::length(balls->at(j).velocity) << std::endl;	// delete

				resolveBallCollision(&balls->at(i), &balls->at(j), &collisionNormal);

				//std::cout << "ball1 speed after collision: " << glm::length(balls->at(i).velocity) << "     ball2 speed after collision: " << glm::length(balls->at(j).velocity) << std::endl;	// delete
			}
		}
	}

	// collisions between balls and sides
	if (detectBallSideCollision(sides, cueBall, &collisionNormal)) {
		//std::cout << "collision between ball and side" << std::endl;	// delete

		resolveBallSideCollision(cueBall, &collisionNormal);
	}

	for (int i = 0; i < balls->size(); i++) {
		if (detectBallSideCollision(sides, &balls->at(i), &collisionNormal)) {
			//std::cout << "collision between ball and side" << std::endl;	// delete

			resolveBallSideCollision(&balls->at(i), &collisionNormal);
		}
	}
}

float pointLineSegmentDistance(glm::vec2* p, glm::vec2* a, glm::vec2* b) {
	glm::vec2 closestPoint;
	glm::vec2 ab = *b - *a;
	glm::vec2 ap = *p - *a;
	float normalizedProj = dot(ab, ap) / (ab.x * ab.x + ab.y * ab.y);

	if (normalizedProj <= 0) {
		closestPoint = *a;
	}
	else if (normalizedProj >= 1) {
		closestPoint = *b;
	}
	else {
		closestPoint = *a + ab * normalizedProj;
	}

	return distance(*p, closestPoint);
}

bool Physics::ballsAreSeparating(Ball* ball1, Ball* ball2) {
	float newDistance = glm::distance(ball1->pos, ball2->pos);

	if (newDistance > ballDistances[ball1->index][ball2->index]) {
		ballDistances[ball1->index][ball2->index] = newDistance;

		return true;
	}

	ballDistances[ball1->index][ball2->index] = newDistance;

	return false;
}

bool Physics::detectBallCollision(Ball* ball1, Ball* ball2, glm::vec2* outCollisionNormal) {
	if ((glm::length(ball1->pos - ball2->pos) <= 1.0f) && (glm::length(ball1->velocity - ball2->velocity) != 0.0f) && (!ballsAreSeparating(ball1, ball2))) {
		*outCollisionNormal = glm::normalize(ball2->pos - ball1->pos);

		return true;
	}

	return false;
}

bool Physics::detectBallSideCollision(Side sides[], Ball* ball, glm::vec2* outCollisionNormal) {
	for (int i = 0; i < 18; i++) {
		if ((pointLineSegmentDistance(&ball->pos, &sides[i].pointA, &sides[i].pointB) <= 0.5f) && (glm::dot(ball->velocity, sides[i].normal) < 0.0f)) {
			*outCollisionNormal = sides[i].normal;
			
			return true;
		}
	}

	return false;
}

void Physics::resolveBallCollision(Ball* ball1, Ball* ball2, glm::vec2* collisionNormal) {
	//std::cout << "collision normal x: " << collisionNormal->x << "     collision normal y: " << collisionNormal->y << std::endl;	// delete
	//std::cout << "collision normal magnitude: " << glm::length(*collisionNormal) << std::endl;	// delete
	
	float elasticity = 0.8f;

	glm::vec2 relativeVelocity = ball2->velocity - ball1->velocity;
	float impulseMagnitude = -((1 + elasticity) * glm::dot(relativeVelocity, *collisionNormal)) / 2;

	//std::cout << "impulse magnitude: " << impulseMagnitude << std::endl;	// delete
	
	ball1->velocity -= impulseMagnitude * *collisionNormal;
	ball2->velocity += impulseMagnitude * *collisionNormal;
}

void Physics::resolveBallSideCollision(Ball* ball, glm::vec2* collisionNormal) {
	float elasticity = 0.8f;

	glm::vec2 relativeVelocity = -ball->velocity;
	float impulseMagnitude = -((1 + elasticity) * glm::dot(relativeVelocity, *collisionNormal));

	ball->velocity -= impulseMagnitude * *collisionNormal;
}