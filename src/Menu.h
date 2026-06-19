#pragma once

#include <string>
#include <vec2.hpp>
#include <PoolColors.h>
#include <Panel.h>
#include <Input.h>
#include <MenuOption.h>

class Menu : public Panel {
public:
	Menu(glm::vec2 pos, std::string textureFilepath, glm::vec2 textureScale, bool flipTexture, Input* input);
	Menu(glm::vec2 pos, Input* input);
	Menu();
	void addMenuOption(MenuOption menuOption, TextLabel textLabel);
	void update();
	MenuOptionType getSelectedOption();

private:
	std::vector<MenuOption> menuOptions;
	Input* input;
	MenuOptionType highlightedOption;
	MenuOptionType selectedOption;
};