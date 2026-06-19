#include <MenuOption.h>

MenuOption::MenuOption(MenuOptionType menuOptionType, glm::vec2 pos, glm::vec2 scale) {
	this->menuOptionType = menuOptionType;
	this->pos = pos;
	this->scale = scale;
}

MenuOption::MenuOption() {}

MenuOptionType MenuOption::getMenuOptionType() {
	return menuOptionType;
}

glm::vec2 MenuOption::getPos() {
	return pos;
}

glm::vec2 MenuOption::getScale() {
	return scale;
}