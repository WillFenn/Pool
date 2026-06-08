#include <GameObject.h>

GameObject::GameObject(Shape shape, glm::vec2 pos, glm::vec2 scale, glm::mat4 rotationMat, std::string textureFilepath, bool flipTexture) {
	this->shape = shape;
	this->pos = pos;
	this->scale = scale;
	this->rotationMat = rotationMat;
	this->texture = std::make_shared<Texture>(textureFilepath, flipTexture);
}

GameObject::GameObject() {};

GameObject::GameObject(const GameObject& other) {
	shape = other.shape;
	pos = other.pos;
	scale = other.scale;
	rotationMat = other.rotationMat;
	texture = other.texture;
}