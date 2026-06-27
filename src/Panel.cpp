#include <Panel.h>

Panel::Panel(glm::vec2 pos, std::string textureFilepath, glm::vec2 textureScale, bool flipTexture, bool active) {
	this->pos = pos;
	texture = std::make_shared<Texture>(textureFilepath, false, flipTexture);
	this->textureScale = textureScale;
	this->active = active;
}

Panel::Panel(glm::vec2 pos, bool active) {
	this->pos = pos;
	this->active = active;
}

Panel::Panel() {}

void Panel::addTextLabel(TextLabel textLabel) {
	textLabels.push_back(textLabel);
}

glm::vec2 Panel::getPos() {
	return pos;
}

glm::vec2 Panel::getTextureScale() {
	return textureScale;
}

Texture* Panel::getTexture() {
	return texture.get();
}

std::vector<TextLabel>* Panel::getTextLabels() {
	return &textLabels;
}

bool Panel::getActive() {
	return active;
}

void Panel::setActive(bool active) {
	this->active = active;
}