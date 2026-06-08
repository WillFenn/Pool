#pragma once

#include <vec2.hpp>
#include <mat4x4.hpp>
#include <string>
#include <Texture.h>

enum Shape { Rectangle, Sphere };

class GameObject {
public:
	GameObject(Shape shape, glm::vec2 pos, glm::vec2 scale, glm::mat4 rotationMat, std::string textureFilepath, bool flipTexture);
	GameObject();
	GameObject(const GameObject& other);

	Shape shape;
	glm::vec2 pos;
	glm::vec2 scale;
	glm::mat4 rotationMat;
	std::shared_ptr<Texture> texture;
};