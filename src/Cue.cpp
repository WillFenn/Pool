#include <Cue.h>

Cue::Cue(glm::vec2 pos, std::string textureFilepath, bool flipTexture, bool active)
: GameObject(Shape::Rectangle, pos, { 10.0f, 0.2f }, glm::mat4(1.0f), textureFilepath, flipTexture, active) {
	speed = 0.0f;
	wasPulledBack = false;
}

Cue::Cue() {}

float Cue::getSpeed() {
	return speed;
}

void Cue::setSpeed(float speed) {
	this->speed = speed;
}

bool Cue::getWasPulledBack() {
	return wasPulledBack;
}

void Cue::setWasPulledBack(bool wasPulledBack) {
	this->wasPulledBack = wasPulledBack;
}