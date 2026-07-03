#pragma once

#include <memory>
#include <vector>
#include <vec2.hpp>
#include <Texture.h>
#include <TextLabel.h>

class Panel {
public:
	Panel(glm::vec2 pos, std::string textureFilepath, glm::vec2 textureScale, bool flipTexture, bool active);
	Panel(glm::vec2 pos, bool active);
	Panel();
	void addTextLabel(TextLabel textLabel);
	glm::vec2 getPos() const;
	glm::vec2 getTextureScale() const;
	const Texture* getTexture() const;
	const std::vector<TextLabel>* getTextLabels() const;
	void setTextLabelText(int textLabelIndex, std::string text);
	void setTextLabelColor(int textLabelIndex, glm::vec4 color);
	bool getActive() const;
	void setActive(bool active);

protected:
	std::vector<TextLabel> textLabels;
	glm::vec2 pos;

private:
	std::shared_ptr<Texture> texture;
	glm::vec2 textureScale;
	bool active;
};