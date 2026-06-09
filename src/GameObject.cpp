#include <GameObject.h>

GameObject::GameObject(Shape shape, glm::vec2 pos, glm::vec2 scale, glm::mat4 rotationMat, std::string textureFilepath, bool flipTexture) {
	this->shape = shape;
	this->pos = pos;
	this->scale = scale;
	this->rotationMat = rotationMat;
	this->texture = std::make_shared<Texture>(textureFilepath, flipTexture);
}

GameObject::GameObject() {}

Shape GameObject::getShape() {
	return shape;
}

glm::vec2 GameObject::getPos() {
	return pos;
}

void GameObject::setPos(glm::vec2 pos) {
	this->pos = pos;
}


glm::vec2 GameObject::getScale() {
	return scale;
}

glm::mat4 GameObject::getRotationMat() {
	return rotationMat;
}

void GameObject::setRotationMat(glm::mat4 rotationMat) {
	this->rotationMat = rotationMat;
}

Texture* GameObject::getTexture() {
	return texture.get();
}