#include <Menu.h>

Menu::Menu(glm::vec2 pos, std::string textureFilepath, glm::vec2 textureScale, bool flipTexture, bool active, Input* input)
: Panel(pos, textureFilepath, textureScale, flipTexture, active) {
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

void Menu::addMenuOption(MenuOption menuOption, TextLabel textLabel) {
	menuOptions.push_back(menuOption);
	textLabels.push_back(textLabel);
}

void Menu::update() {
	bool optionSelected = false;

	glm::vec2 mouseWorldPos = input->getMouseWorldPos();

	for (int i = 0; i < menuOptions.size(); i++) {
		if (mouseWorldPos.x >= pos.x + menuOptions.at(i).getPos().x - menuOptions.at(i).getScale().x / 2 && mouseWorldPos.x <= pos.x + menuOptions.at(i).getPos().x + menuOptions.at(i).getScale().x / 2
			&& mouseWorldPos.y >= pos.y + menuOptions.at(i).getPos().y - menuOptions.at(i).getScale().y / 2 && mouseWorldPos.y <= pos.y + menuOptions.at(i).getPos().y + menuOptions.at(i).getScale().y / 2) {
			highlightedOption = menuOptions.at(i).getMenuOptionType();
			textLabels.at(i).setColor(PoolColors::white());

			if (input->leftMouseReleased()) {
				selectedOption = highlightedOption;
			}

			
		}
		else {
			textLabels.at(i).setColor(PoolColors::black());
		}
	}

	if (!optionSelected) {
		highlightedOption = MenuOptionType::None;
	}
}

MenuOptionType Menu::getSelectedOption() {
	return selectedOption;
}