#pragma once

#include <memory>
#include <vector>
#include <vec2.hpp>
#include <Texture.h>
#include <TextLabel.h>

class Panel {
public:
	Panel(glm::vec2 pos, glm::vec2 scale, std::string textureFilepath, bool flipTexture);
	Panel(glm::vec2 pos, glm::vec2 scale);
	Panel();
	void addTextLabel(std::string text, float xStart, float yBaseline, glm::vec4 color, Font font, FontSize fontSize);
	glm::vec2 getPos();
	glm::vec2 getScale();
	Texture* getTexture();
	std::vector<TextLabel>* getTextLabels();

private:
	glm::vec2 pos;
	glm::vec2 scale;
	std::shared_ptr<Texture> texture;
	std::vector<TextLabel> textLabels;
};