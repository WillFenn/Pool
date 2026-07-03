#pragma once

#include <TextLabel.h>

enum MenuOptionType { None, Play, Quit };

class MenuOption {
public:
	MenuOption(MenuOptionType menuOptionType, glm::vec2 pos, glm::vec2 scale);
	MenuOption();
	MenuOptionType getMenuOptionType() const;
	glm::vec2 getPos() const;
	glm::vec2 getScale() const;

private:
	MenuOptionType menuOptionType;
	glm::vec2 pos;
	glm::vec2 scale;
} ;