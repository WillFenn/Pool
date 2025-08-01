#include <iostream>
#include <vector>
#include <Window.h>
#include <Input.h>
#include <Ball.h>

int main() {
	std::cout << "starting" << std::endl;
	Window window;

	Input input(window.getglfwwindow());

	std::vector<Ball> balls;
	balls.push_back({ { 0.0f, 0.0f } });
	balls.push_back({ { 2.0f, 2.0f } });

	while (!input.escKeyPressed()) {
		window.drawFrame(&balls);
	}
}