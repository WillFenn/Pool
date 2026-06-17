#include <Panel.h>

Panel::Panel(glm::vec2 pos, std::string textureFilepath, glm::vec2 textureScale, bool flipTexture) {
	this->pos = pos;
	texture = std::make_shared<Texture>(textureFilepath, false, flipTexture);
	this->textureScale = textureScale;
}

Panel::Panel(glm::vec2 pos) {
	this->pos = pos;
}

Panel::Panel() {}

void Panel::addTextLabel(std::string text, float xStart, float yBaseline, glm::vec4 color, Font font, FontSize fontSize) {
	textLabels.push_back(TextLabel(text, xStart, yBaseline, color, font, fontSize));
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