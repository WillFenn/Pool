#include <Menu.h>

Menu::Menu(glm::vec2 pos, std::string textureFilepath, glm::vec2 textureScale, bool flipTexture, Input* input)
: Panel(pos, textureFilepath, textureScale, flipTexture) {
	this->input = input;
	highlightedOption = MenuOptionType::None;
	selectedOption = MenuOptionType::None;
}

Menu::Menu(glm::vec2 pos, Input* input)
: Panel(pos) {
	this->input = input;
	highlightedOption = MenuOptionType::None;
	selectedOption = MenuOptionType::None;
}

Menu::Menu() {}

void Menu::addMenuOption(MenuOption menuOption) {
	menuOptions.push_back(menuOption);
}

void Menu::Update() {
	glm::vec2 mouseWorldPos = input->getMouseWorldPos();

	for (MenuOption menuOption : menuOptions) {
		if (mouseWorldPos.x >= menuOption.getPos().x - menuOption.getScale().x / 2 && mouseWorldPos.x <= menuOption.getPos().x + menuOption.getScale().x / 2
			&& mouseWorldPos.y >= menuOption.getPos().y - menuOption.getScale().y / 2 && mouseWorldPos.y <= menuOption.getPos().y + menuOption.getScale().y / 2) {
			highlightedOption = menuOption.getMenuOptionType();

			if (input->leftMouseReleased()) {
				selectedOption = highlightedOption;
			}

			return;
		}
	}

	highlightedOption = MenuOptionType::None;
}

MenuOptionType Menu::optionSelected() {
	return selectedOption;
}