#include <TextLabel.h>

TextLabel::TextLabel(std::string text, float xStart, float yBaseline, glm::vec4 color, Font font, FontSize fontSize, std::string textureFilepath, bool flipTexture, glm::vec2 texturePos, glm::vec2 textureScale) {
	this->text = text;
	this->xStart = xStart;
	this->yBaseline = yBaseline;
	this->color = color;
	this->font = font;
	this->fontSize = fontSize;
	texture = std::make_shared<Texture>(textureFilepath, false, flipTexture);
	this->texturePos = texturePos;
	this->textureScale = textureScale;
}

TextLabel::TextLabel(std::string text, float xStart, float yBaseline, glm::vec4 color, Font font, FontSize fontSize) {
	this->text = text;
	this->xStart = xStart;
	this->yBaseline = yBaseline;
	this->color = color;
	this->font = font;
	this->fontSize = fontSize;
	texturePos = { 0.0f, 0.0f };
	textureScale = { 0.0f, 0.0f };
}

TextLabel::TextLabel() {}

std::string TextLabel::getText() {
	return text;
}

void TextLabel::setText(std::string text) {
	this->text = text;
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

void TextLabel::setColor(glm::vec4 color) {
	this->color = color;
}

Font TextLabel::getFont() {
	return font;
}

FontSize TextLabel::getFontSize() {
	return fontSize;
}

Texture* TextLabel::getTexture() {
	return texture.get();
}

glm::vec2 TextLabel::getTexturePos() {
	return texturePos;
}

glm::vec2 TextLabel::getTextureScale() {
	return textureScale;
}