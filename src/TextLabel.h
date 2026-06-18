#pragma once

#include <string>
#include <memory>
#include <vec2.hpp>
#include <vec4.hpp>
#include <Font.h>
#include <FontSize.h>
#include <Texture.h>

class TextLabel {
public:
	TextLabel(std::string text, float xStart, float yBaseline, glm::vec4 color, Font font, FontSize fontSize, std::string textureFilepath, bool flipTexture, glm::vec2 texturePos, glm::vec2 textureScale);
	TextLabel(std::string text, float xStart, float yBaseline, glm::vec4 color, Font font, FontSize fontSize);
	TextLabel();
	std::string getText();
	float getxStart();
	float getyBaseline();
	glm::vec4 getColor();
	Font getFont();
	FontSize getFontSize();
	glm::vec2 getScale();

private:
	std::string text;
	float xStart;
	float yBaseline;
	glm::vec4 color;
	Font font;
	FontSize fontSize;
	std::shared_ptr<Texture> texture;
	glm::vec2 texturePos;
	glm::vec2 textureScale;
};