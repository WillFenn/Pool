#include <Cue.h>

Cue::Cue(glm::vec2 pos, std::string textureFilepath, bool flipTexture) {
	shape = Shape::Rectangle;
	this->pos = pos;
	scale = { 10.0f, 0.2f };
	texture = std::make_shared<Texture>(textureFilepath, flipTexture);
	speed = 0.0f;
	rotationMat = glm::mat4(1.0f);
	wasPulledBack = false;
}

Cue::Cue() {}

Cue::Cue(const Cue& other) {
	shape = other.shape;
	pos = other.pos;
	scale = other.scale;
	rotationMat = other.rotationMat;
	texture = other.texture;
	speed = other.speed;
	wasPulledBack = other.wasPulledBack;
}