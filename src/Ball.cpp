#include <Ball.h>

Ball::Ball(glm::vec2 pos, std::string textureFilepath, bool flipTexture, int index, BallType ballType) {
	shape = Shape::Sphere;
	this->pos = pos;
	scale = { 1.0f, 1.0f };
	texture = std::make_shared<Texture>(textureFilepath, flipTexture);
	this->index = index;
	this->ballType = ballType;
	velocity = { 0.0f, 0.0f };
	rotationMat = PoolMath::addToRotationMat(glm::mat4(1.0f), glm::pi<float>() / 2, glm::vec3(0.0f, 1.0f, 0.0f));
}

Ball::Ball() {}

Ball::Ball(const Ball& other) {
	shape = other.shape;
	pos = other.pos;
	scale = other.scale;
	rotationMat = other.rotationMat;
	texture = other.texture;
	index = other.index;
	ballType = other.ballType;
	velocity = other.velocity;
}