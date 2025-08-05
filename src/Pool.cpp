#include <iostream>
#include <vector>
#include <Window.h>
#include <Input.h>
#include <Ball.h>
#include <Cue.h>

int main() {
	std::cout << "starting" << std::endl;

	glm::vec4 green = { 0.0f / 255.0f, 150.0f / 255.0f, 0.0f / 255.0f, 1.0f };
	glm::vec4 brown = { 255.0f / 255.0f, 150.0f / 255.0f, 0.0f / 255.0f, 1.0f };

	Window window(green);

	Input input(window.getglfwwindow());

	std::vector<Ball> balls;
	balls.push_back({ { 0.0f, 0.0f } });
	balls.push_back({ { 2.0f, 2.0f } });

	Cue cue = { {0.0f, 0.0f}, {10.0f, 0.2f}, 0.0f, brown };

	while (!(input.escKeyPressed() || window.shouldClose())) {
		window.drawFrame(&balls, cue);
	}
}