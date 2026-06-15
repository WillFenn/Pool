#include <Panel.h>

Panel::Panel(glm::vec2 pos, glm::vec2 scale, std::string textureFilepath, bool flipTexture) {
	this->pos = pos;
	this->scale = scale;
	texture = std::make_shared<Texture>(textureFilepath, false, flipTexture);
}

Panel::Panel(glm::vec2 pos, glm::vec2 scale) {
	this->pos = pos;
	this->scale = scale;
}

Panel::Panel() {}

void Panel::addTextLabel(std::string text, float xStart, float yBaseline, glm::vec4 color, Font font, FontSize fontSize) {
	textLabels.push_back(TextLabel(text, xStart, yBaseline, color, font, fontSize));
}

glm::vec2 Panel::getPos() {
	return pos;
}

glm::vec2 Panel::getScale() {
	return scale;
}

Texture* Panel::getTexture() {
	return texture.get();
}

std::vector<TextLabel>* Panel::getTextLabels() {
	return &textLabels;
}