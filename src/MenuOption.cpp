#include <MenuOption.h>

MenuOption::MenuOption(TextLabel textLabel, MenuOptionType menuOptionType, glm::vec2 pos, glm::vec2 scale) {
	this->textLabel = textLabel;
	this->menuOptionType = menuOptionType;
	this->pos = pos;
	this->scale = scale;
}

MenuOption::MenuOption() {}

TextLabel* MenuOption::getTextLabel() {
	return &textLabel;
}

MenuOptionType MenuOption::getMenuOptionType() {
	return menuOptionType;
}

glm::vec2 MenuOption::getPos() {
	return pos;
}

glm::vec2 MenuOption::getScale() {
	return scale;
}