#pragma once

#include <TextLabel.h>

enum MenuOptionType { None, Play, Quit };

class MenuOption : public TextLabel {
public:
	MenuOption(std::string text, float xStart, float yBaseline, glm::vec4 color, Font font, FontSize fontSize, std::string textureFilepath, bool flipTexture, glm::vec2 scale, MenuOptionType menuOptionType);
	MenuOption(std::string text, float xStart, float yBaseline, glm::vec4 color, Font font, FontSize fontSize, glm::vec2 scale, MenuOptionType menuOptionType);
	MenuOption();

private:
	MenuOptionType menuOptionType;
};