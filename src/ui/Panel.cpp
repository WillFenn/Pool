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

glm::vec2 Panel::getPos() const {
	return pos;
}

glm::vec2 Panel::getTextureScale() const {
	return textureScale;
}

const Texture* Panel::getTexture() const {
	return texture.get();
}

const std::vector<TextLabel>* Panel::getTextLabels() const {
	return &textLabels;
}

void Panel::setTextLabelText(int textLabelIndex, std::string text) {
	textLabels.at(textLabelIndex).setText(text);
}

void Panel::setTextLabelColor(int textLabelIndex, glm::vec4 color) {
	textLabels.at(textLabelIndex).setColor(color);
}

bool Panel::getActive() const{
	return active;
}

void Panel::setActive(bool active) {
	this->active = active;
}