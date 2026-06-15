#pragma once

#include <memory>
#include <vec2.hpp>
#include <mat4x4.hpp>
#include <string>
#include <Texture.h>

enum Shape { Rectangle, Sphere };

class GameObject {
public:
	GameObject(Shape shape, glm::vec2 pos, glm::vec2 scale, glm::mat4 rotationMat, std::string textureFilepath, bool flipTexture);
	GameObject();
	Shape getShape();
	glm::vec2 getPos();
	void setPos(glm::vec2 pos);
	glm::vec2 getScale();
	glm::mat4 getRotationMat();
	void setRotationMat(glm::mat4 rotationMat);
	Texture* getTexture();

private:
	Shape shape;
	glm::vec2 pos;
	glm::vec2 scale;
	glm::mat4 rotationMat;
	std::shared_ptr<Texture> texture;
};