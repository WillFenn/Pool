#include <Character.h>

Character::Character(glm::ivec2 size, glm::ivec2 bearing, unsigned int advance, unsigned char* buffer) {
	this->size = size;
	this->bearing = bearing;
	this->advance = advance;
	texture = std::make_shared<Texture>(buffer, size.x, size.y, true);
}

Character::Character() {}

glm::ivec2 Character::getSize() {
	return size;
}

glm::ivec2 Character::getBearing() {
	return bearing;
}

unsigned int Character::getAdvance() {
	return advance;
}

Texture* Character::getTexture() {
	return texture.get();
}