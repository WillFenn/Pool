#include <TextLabel.h>

TextLabel::TextLabel(std::string text, float xStart, float yBaseline, glm::vec4 color, Font font, FontSize fontSize) {
	this->text = text;
	this->xStart = xStart;
	this->yBaseline = yBaseline;
	this->color = color;
	this->font = font;
	this->fontSize = fontSize;
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