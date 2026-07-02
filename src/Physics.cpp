#include <Physics.h>

Physics::Physics() {

}

Physics::~Physics() {

}

void Physics::update(Side sides[], std::vector<Ball>* balls, Ball* cueBall, Cue* cue, float deltaTime) {
	// stop ball if its speed is close to zero
	if ((glm::length(cueBall->getVelocity()) < 0.05f)) {
		cueBall->setVelocity({ 0.0f, 0.0f });
	}

	//for (int i = 0; i < balls->size(); i++) {
	//	if (glm::length(balls->at(i).getVelocity()) < 0.05f) {
	//		balls->at(i).setVelocity({ 0.0f, 0.0f });
	//	}
	//}

	for (Ball& ball : *balls | std::ranges::views::filter([](Ball& ball) { return ball.getActive(); })) {
		std::cout << "ball: " << ball.getIndex() << std::endl;	// delete
		if (glm::length(ball.getVelocity()) < 0.05f) {
			ball.setVelocity({ 0.0f, 0.0f });
		}
	}
	
	// apply friction
	if (glm::length(cueBall->getVelocity()) > 0) {
		glm::vec2 newVelocity = cueBall->getVelocity() - glm::normalize(cueBall->getVelocity()) * frictionAcceleration * deltaTime;

		if (glm::dot(cueBall->getVelocity(), newVelocity) > 0) {
			cueBall->setVelocity(newVelocity);
		}
		else {
			cueBall->setVelocity({ 0.0f, 0.0f });
		}
	}

	for (Ball& ball : *balls | std::ranges::views::filter([](Ball& ball) { return ball.getActive(); })) {
		if (glm::length(ball.getVelocity()) > 0) {
			glm::vec2 newVelocity = ball.getVelocity() - glm::normalize(ball.getVelocity()) * frictionAcceleration * deltaTime;

			if (glm::dot(ball.getVelocity(), newVelocity) > 0) {
				ball.setVelocity(newVelocity);
			}
			else {
				ball.setVelocity({ 0.0f, 0.0f });
			}
		}
	}
	
	// update positions and rotations
	//std::cout << "cue speed: " << cue->speed << std::endl;	// delete
	//std::cout << "cue ball speed: " << glm::length(cueBall->velocity) << std::endl;	// delete
	
	cue->setPos(cue->getPos() + glm::normalize(cueBall->getPos() - cue->getPos()) * cue->getSpeed() * deltaTime);

	for (Ball& ball : *balls | std::ranges::views::filter([](Ball& ball) { return ball.getActive(); })) {
		glm::vec2 deltaPos = ball.getVelocity() * deltaTime;
		ball.setPos(ball.getPos() + deltaPos);

		if (glm::length(deltaPos) != 0.0f) {
			ball.setRotationMat(PoolMath::addToRotationMat(ball.getRotationMat(), glm::length(deltaPos) / 0.5f, glm::cross(glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(deltaPos, 0.0f))));
		}
	}

	glm::vec2 deltaPos = cueBall->getVelocity() * deltaTime;
	cueBall->setPos(cueBall->getPos() + deltaPos);
	if (glm::length(deltaPos) != 0.0f) {
		cueBall->setRotationMat(PoolMath::addToRotationMat(cueBall->getRotationMat(), glm::length(deltaPos) / 0.5f, glm::cross(glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(deltaPos, 0.0f))));
	}

	// collision between cue and cue ball
	if (glm::distance(cue->getPos(), cueBall->getPos()) <= ((cue->getScale().x / 2) + 0.5f) && cue->getSpeed() != 0.0f) {
		cueBall->setVelocity(glm::normalize(cueBall->getPos() - cue->getPos()) * cue->getSpeed());
		cue->setSpeed(0.0f);
	}

	// collisions between balls
	glm::vec2 collisionNormal(0.0f, 0.0f);

	for (Ball& ball : *balls | std::ranges::views::filter([](Ball& ball) { return ball.getActive(); })) {
		if (detectBallCollision(cueBall, &ball, &collisionNormal)) {
			resolveBallCollision(cueBall, &ball, &collisionNormal);
		}
	}

	for (Ball& ball1 : *balls | std::ranges::views::filter([](Ball& ball) { return ball.getActive(); })) {
		for (Ball& ball2 : *balls | std::ranges::views::drop(ball1.getIndex()) | std::ranges::views::filter([](Ball& ball) { return ball.getActive(); })) {
			if (detectBallCollision(&ball1, &ball2, &collisionNormal)) {
				resolveBallCollision(&ball1, &ball2, &collisionNormal);
			}
		}
	}

	// collisions between balls and sides
	if (detectBallSideCollision(sides, cueBall, &collisionNormal)) {
		//std::cout << "collision between ball and side" << std::endl;	// delete

		resolveBallSideCollision(cueBall, &collisionNormal);
	}

	for (Ball& ball : *balls | std::ranges::views::filter([](Ball& ball) { return ball.getActive(); })) {
		if (detectBallSideCollision(sides, &ball, &collisionNormal)) {
			//std::cout << "collision between ball and side" << std::endl;	// delete

			resolveBallSideCollision(&ball, &collisionNormal);
		}
	}
}

bool Physics::ballsAreSeparating(Ball* ball1, Ball* ball2) {
	float newDistance = glm::distance(ball1->getPos(), ball2->getPos());

	if (newDistance > ballDistances[ball1->getIndex()][ball2->getIndex()]) {
		ballDistances[ball1->getIndex()][ball2->getIndex()] = newDistance;

		return true;
	}

	ballDistances[ball1->getIndex()][ball2->getIndex()] = newDistance;

	return false;
}

bool Physics::detectBallCollision(Ball* ball1, Ball* ball2, glm::vec2* outCollisionNormal) {
	if ((glm::length(ball1->getPos() - ball2->getPos()) <= 1.0f) && (glm::length(ball1->getVelocity() - ball2->getVelocity()) != 0.0f) && (!ballsAreSeparating(ball1, ball2))) {
		*outCollisionNormal = glm::normalize(ball2->getPos() - ball1->getPos());

		return true;
	}

	return false;
}

bool Physics::detectBallSideCollision(Side sides[], Ball* ball, glm::vec2* outCollisionNormal) const {
	for (int i = 0; i < 18; i++) {
		if ((PoolMath::pointLineSegmentDistance(ball->getPos(), sides[i].a, sides[i].b) <= 0.5f) && (glm::dot(ball->getVelocity(), sides[i].normal) < 0.0f)) {
			*outCollisionNormal = sides[i].normal;
			
			return true;
		}
	}

	return false;
}

void Physics::resolveBallCollision(Ball* ball1, Ball* ball2, glm::vec2* outCollisionNormal) const {
	//std::cout << "collision normal x: " << collisionNormal->x << "     collision normal y: " << collisionNormal->y << std::endl;	// delete
	//std::cout << "collision normal magnitude: " << glm::length(*collisionNormal) << std::endl;	// delete
	
	float elasticity = 0.8f;

	glm::vec2 relativeVelocity = ball2->getVelocity() - ball1->getVelocity();
	float impulseMagnitude = -((1 + elasticity) * glm::dot(relativeVelocity, *outCollisionNormal)) / 2;

	//std::cout << "impulse magnitude: " << impulseMagnitude << std::endl;	// delete
	
	ball1->setVelocity(ball1->getVelocity() - impulseMagnitude * *outCollisionNormal);
	ball2->setVelocity(ball2->getVelocity() + impulseMagnitude * *outCollisionNormal);
}

void Physics::resolveBallSideCollision(Ball* ball, glm::vec2* outCollisionNormal) const {
	float elasticity = 0.8f;

	glm::vec2 relativeVelocity = -ball->getVelocity();
	float impulseMagnitude = -((1 + elasticity) * glm::dot(relativeVelocity, *outCollisionNormal));

	ball->setVelocity(ball->getVelocity() - impulseMagnitude * *outCollisionNormal);
}