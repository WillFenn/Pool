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
	std::string getText() const;
	void setText(std::string text);
	float getxStart() const;
	float getyBaseline() const;
	glm::vec4 getColor() const;
	void setColor(glm::vec4 color);
	Font getFont() const;
	FontSize getFontSize() const;
	const Texture* getTexture() const;
	glm::vec2 getTexturePos() const;
	glm::vec2 getTextureScale() const;

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