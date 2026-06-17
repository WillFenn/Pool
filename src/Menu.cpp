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

void Menu::Update() {
	glm::vec2 mouseWorldPos = input->getMouseWorldPos();

	for (MenuOption menuOption : menuOptions) {
		if (mouseWorldPos.x >= menuOption.pos)
	}
}

MenuOptionType Menu::optionSelected() {

}