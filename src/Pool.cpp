#include <iostream>
#include <vector>
#include <Window.h>
#include <Input.h>
#include <Ball.h>
#include <Cue.h>

void setBalls(std::vector<Ball> balls) {
	balls.push_back({ { 0.0f, 0.0f }, green, false });
	balls.push_back({ { 2.0f, 2.0f }, green, false });

}

int main() {
	std::cout << "starting" << std::endl;

	glm::vec4 white = { 255.0f / 255.0f, 255.0f / 255.0f, 255.0f / 255.0f, 1.0f };
	glm::vec4 black = { 0.0f / 255.0f, 0.0f / 255.0f, 0.0f / 255.0f, 1.0f };
	glm::vec4 yellow = { 255.0f / 255.0f, 255.0f / 255.0f, 0.0f / 255.0f, 1.0f };
	glm::vec4 red = { 255.0f / 255.0f, 0.0f / 255.0f, 0.0f / 255.0f, 1.0f };
	glm::vec4 green = { 0.0f / 255.0f, 150.0f / 255.0f, 0.0f / 255.0f, 1.0f };
	glm::vec4 blue = { 0.0f / 255.0f, 0.0f / 255.0f, 255.0f / 255.0f, 1.0f };
	glm::vec4 orange = { 255.0f / 255.0f, 128.0f / 255.0f, 0.0f / 255.0f, 1.0f };
	glm::vec4 purple = { 48.0f / 255.0f, 25.0f / 255.0f, 52.0f / 255.0f, 1.0f };
	glm::vec4 brown = { 255.0f / 255.0f, 150.0f / 255.0f, 0.0f / 255.0f, 1.0f };
	glm::vec4 maroon = { 128.0f / 255.0f, 0.0f / 255.0f, 0.0f / 255.0f, 1.0f };

	Window window(green);

	Input input(window.getglfwwindow());

	std::vector<Ball> balls;
	balls.push_back({ { 0.0f, 0.0f }, green, false});
	balls.push_back({ { 2.0f, 2.0f }, green, false });

	Ball cueBall = { {0.0f, 0.0f}, white, false };

	Cue cue = { {0.0f, 0.0f}, {10.0f, 0.2f}, 0.0f, brown };

	while (!(input.escKeyPressed() || window.shouldClose())) {
		window.drawFrame(&balls, cue);
	}
}