#include <MenuOption.h>

MenuOption::MenuOption(MenuOptionType menuOptionType, glm::vec2 pos, glm::vec2 scale) {
	this->menuOptionType = menuOptionType;
	this->pos = pos;
	this->scale = scale;
}

MenuOption::MenuOption() {}

MenuOptionType MenuOption::getMenuOptionType() const {
	return menuOptionType;
}

glm::vec2 MenuOption::getPos() const {
	return pos;
}

glm::vec2 MenuOption::getScale() const {
	return scale;
}