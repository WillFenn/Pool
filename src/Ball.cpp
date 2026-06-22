#include <Ball.h>

Ball::Ball(glm::vec2 pos, std::string textureFilepath, bool flipTexture, bool active, int index, BallType ballType)
: GameObject(Shape::Sphere, pos, { 1.0f, 1.0f }, PoolMath::addToRotationMat(glm::mat4(1.0f), glm::pi<float>() / 2, glm::vec3(0.0f, 1.0f, 0.0f)), textureFilepath, flipTexture, active) {
	this->index = index;
	this->ballType = ballType;
	velocity = { 0.0f, 0.0f };
}

Ball::Ball() {}

int Ball::getIndex() {
	return index;
}

BallType Ball::getBallType() {
	return ballType;
}

glm::vec2 Ball::getVelocity() {
	return velocity;
}

void Ball::setVelocity(glm::vec2 velocity) {
	this->velocity = velocity;
}