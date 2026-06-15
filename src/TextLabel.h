#pragma once

#include <string>
#include <Font.h>
#include <FontSize.h>
#include <vec2.hpp>
#include <vec4.hpp>

class TextLabel {
public:
	TextLabel(std::string text, float xStart, float yBaseline, glm::vec4 color, Font font, FontSize fontSize);
	std::string getText();
	float getxStart();
	float getyBaseline();
	glm::vec4 getColor();
	Font getFont();
	FontSize getFontSize();

private:
	std::string text;
	float xStart;
	float yBaseline;
	glm::vec4 color;
	Font font;
	FontSize fontSize;
};