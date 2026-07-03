#pragma once

#include <memory>
#include <vec2.hpp>
#include <mat4x4.hpp>
#include <string>
#include <Texture.h>

enum Shape { Rectangle, Sphere };

class GameObject {
public:
	GameObject(Shape shape, glm::vec2 pos, glm::vec2 scale, glm::mat4 rotationMat, std::string textureFilepath, bool flipTexture, bool active);
	GameObject();
	Shape getShape() const;
	glm::vec2 getPos() const;
	void setPos(glm::vec2 pos);
	glm::vec2 getScale() const;
	glm::mat4 getRotationMat() const;
	void setRotationMat(glm::mat4 rotationMat);
	const Texture* getTexture() const;
	bool getActive() const;
	void setActive(bool active);

private:
	Shape shape;
	glm::vec2 pos;
	glm::vec2 scale;
	glm::mat4 rotationMat;
	std::shared_ptr<Texture> texture;
	bool active;
};