#pragma once

#include <string>
#include <vec2.hpp>
#include <Panel.h>
#include <Input.h>
#include <MenuOption.h>

class Menu : public Panel {
public:
	Menu(glm::vec2 pos, std::string textureFilepath, glm::vec2 textureScale, bool flipTexture, Input* input);
	Menu(glm::vec2, Input* input);
	Menu();
	void Update();
	MenuOptionType optionSelected();

private:
	std::vector<MenuOption> menuOptions;
	Input* input;
	MenuOptionType highlightedOption;
	MenuOptionType selectedOption;
};