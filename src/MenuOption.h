#pragma once

#include <TextLabel.h>

enum MenuOptionType { None, Play, Quit };

class MenuOption {
public:
	MenuOption(TextLabel textLabel, MenuOptionType menuOptionType, glm::vec2 pos, glm::vec2 scale);
	MenuOption();
	TextLabel* getTextLabel();
	MenuOptionType getMenuOptionType();
	glm::vec2 getPos();
	glm::vec2 getScale();

private:
	TextLabel textLabel;
	MenuOptionType menuOptionType;
	glm::vec2 pos;
	glm::vec2 scale;
};