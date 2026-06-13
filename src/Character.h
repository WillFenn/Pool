#pragma once
#include <vec2.hpp>
#include <Texture.h>

enum Font { Monoton };

enum FontSize { OneSixteenth, OneEighth, OneFourth, OneHalf };

class Character {
public:
	Character(glm::ivec2 size, glm::ivec2 bearing, unsigned int advance, unsigned char* buffer);
	Character();
	glm::ivec2 getSize();
	glm::ivec2 getBearing();
	unsigned int getAdvance();
	Texture* getTexture();

private:
	glm::ivec2 size;	// Size of character in pixels
	glm::ivec2 bearing;	// Offset to top left corner of character in pixels
	unsigned int advance;	// Offset to next character
	std::shared_ptr<Texture> texture;
};