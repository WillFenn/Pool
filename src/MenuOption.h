#pragma once

#include <TextLabel.h>

enum MenuOptionType { None, Play, Quit };

class MenuOption {
public:
	MenuOption(MenuOptionType menuOptionType, glm::vec2 pos, glm::vec2 scale);
	MenuOption();
	MenuOptionType getMenuOptionType();
	glm::vec2 getPos();
	glm::vec2 getScale();

private:
	MenuOptionType menuOptionType;
	glm::vec2 pos;
	glm::vec2 scale;
};