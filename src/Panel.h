#pragma once

#include <memory>
#include <vector>
#include <vec2.hpp>
#include <Texture.h>
#include <TextLabel.h>

class Panel {
public:
	Panel(glm::vec2 pos, std::string textureFilepath, glm::vec2 textureScale, bool flipTexture);
	Panel(glm::vec2 pos);
	Panel();
	void addTextLabel(std::string text, float xStart, float yBaseline, glm::vec4 color, Font font, FontSize fontSize);
	glm::vec2 getPos();
	glm::vec2 getTextureScale();
	Texture* getTexture();
	std::vector<TextLabel>* getTextLabels();

protected:
	std::vector<TextLabel> textLabels;
	glm::vec2 pos;

private:
	std::shared_ptr<Texture> texture;
	glm::vec2 textureScale;
};