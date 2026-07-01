#include <GameObject.h>

GameObject::GameObject(Shape shape, glm::vec2 pos, glm::vec2 scale, glm::mat4 rotationMat, std::string textureFilepath, bool flipTexture, bool active) {
	this->shape = shape;
	this->pos = pos;
	this->scale = scale;
	this->rotationMat = rotationMat;
	texture = std::make_shared<Texture>(textureFilepath, false, flipTexture);
	this->active = active;
}

GameObject::GameObject() {}

Shape GameObject::getShape() const {
	return shape;
}

glm::vec2 GameObject::getPos() const {
	return pos;
}

void GameObject::setPos(glm::vec2 pos) {
	this->pos = pos;
}


glm::vec2 GameObject::getScale() const {
	return scale;
}

glm::mat4 GameObject::getRotationMat() const {
	return rotationMat;
}

void GameObject::setRotationMat(glm::mat4 rotationMat) {
	this->rotationMat = rotationMat;
}

const Texture* GameObject::getTexture() const {
	return texture.get();
}

bool GameObject::getActive() const {
	return active;
}

void GameObject::setActive(bool active) {
	this->active = active;
}