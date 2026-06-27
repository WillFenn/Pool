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
	void setText(std::string text);
	float getxStart();
	float getyBaseline();
	glm::vec4 getColor();
	void setColor(glm::vec4 color);
	Font getFont();
	FontSize getFontSize();
	Texture* getTexture();
	glm::vec2 getTexturePos();
	glm::vec2 getTextureScale();

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