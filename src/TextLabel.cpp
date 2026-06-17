#include <TextLabel.h>

TextLabel::TextLabel(std::string text, float xStart, float yBaseline, glm::vec4 color, Font font, FontSize fontSize, std::string textureFilepath, bool flipTexture, glm::vec2 scale) {
	this->text = text;
	this->xStart = xStart;
	this->yBaseline = yBaseline;
	this->color = color;
	this->font = font;
	this->fontSize = fontSize;
	std::make_shared<Texture>(textureFilepath, false, flipTexture);
	this->scale = scale;
}

TextLabel::TextLabel(std::string text, float xStart, float yBaseline, glm::vec4 color, Font font, FontSize fontSize, glm::vec2 scale = { 0.0f, 0.0f }) {
	this->text = text;
	this->xStart = xStart;
	this->yBaseline = yBaseline;
	this->color = color;
	this->font = font;
	this->fontSize = fontSize;
	this->scale = scale;
}

std::string TextLabel::getText() {
	return text;
}

float TextLabel::getxStart() {
	return xStart;
}

float TextLabel::getyBaseline() {
	return yBaseline;
}

glm::vec4 TextLabel::getColor() {
	return color;
}

Font TextLabel::getFont() {
	return font;
}

FontSize TextLabel::getFontSize() {
	return fontSize;
}

glm::vec2 TextLabel::getScale() {
	return scale;
}