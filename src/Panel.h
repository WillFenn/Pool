#pragma once

#include <memory>
#include <vector>
#include <vec2.hpp>
#include <Texture.h>
#include <TextLabel.h>

class Panel {
public:
	Panel(glm::vec2 pos, std::string textureFilepath, glm::vec2 textureScale, bool flipTexture, bool active);
	Panel(glm::vec2 pos);
	Panel();
	void addTextLabel(TextLabel textLabel);
	glm::vec2 getPos();
	glm::vec2 getTextureScale();
	Texture* getTexture();
	std::vector<TextLabel>* getTextLabels();
	bool getActive();
	void setActive(bool active);

protected:
	std::vector<TextLabel> textLabels;
	glm::vec2 pos;

private:
	std::shared_ptr<Texture> texture;
	glm::vec2 textureScale;
	bool active;
};