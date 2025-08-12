#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <Window.h>
#include <Input.h>
#include <Ball.h>
#include <Cue.h>

void setPositions(std::vector<Ball>* balls) {
	glm::vec2 frontPos = { 5.0f, 0.0f };
	float gapLength = 0.05;
	std::vector<glm::vec2> positions;

	for (int i = 0; i < 5; i++) {
		glm::vec2 columnStart = frontPos + (float)i * glm::vec2(1.0f + gapLength, 0.5f + gapLength / 2);
		for (int j = 0; j < i + 1; j++) {
			positions.push_back(columnStart + (float)j * glm::vec2(0.0f, -1.0f - gapLength));
		}
	}

	srand(time(0));

	for (int i = 0; i < balls->size(); i++) {
		balls->at(i).pos = positions.at(rand() % balls->size());
	}

	for (int i = 0; i < positions.size(); i++) {																		// delete
		std::cout << "position " << i << "     x: " << positions.at(i).x << "  y: " << positions.at(i).y << std::endl;	//
	}																													//

	for (int i = 0; i < balls->size(); i++) {																					// delete
		std::cout << "ball " << i << " position     x: " << balls->at(i).pos.x << "  y: " << balls->at(i).pos.y << std::endl;	//
	}																															//
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
	balls.push_back({ { 0.0f, 0.0f }, black, false });
	balls.push_back({ { 0.0f, 0.0f }, black, false });
	balls.push_back({ { 0.0f, 0.0f }, black, false });
	balls.push_back({ { 0.0f, 0.0f }, black, false });
	balls.push_back({ { 0.0f, 0.0f }, black, false });
	balls.push_back({ { 0.0f, 0.0f }, black, false });
	balls.push_back({ { 0.0f, 0.0f }, black, false });
	balls.push_back({ { 0.0f, 0.0f }, black, false });
	balls.push_back({ { 0.0f, 0.0f }, black, false });
	balls.push_back({ { 0.0f, 0.0f }, black, false });
	balls.push_back({ { 0.0f, 0.0f }, black, false });
	balls.push_back({ { 0.0f, 0.0f }, black, false });
	balls.push_back({ { 0.0f, 0.0f }, black, false });
	balls.push_back({ { 0.0f, 0.0f }, black, false });
	balls.push_back({ { 0.0f, 0.0f }, black, false });

	setPositions(&balls);

	Ball cueBall = { {0.0f, 0.0f}, white, false };

	Cue cue = { {0.0f, 0.0f}, {10.0f, 0.2f}, 0.0f, brown };

	while (!(input.escKeyPressed() || window.shouldClose())) {
		window.drawFrame(&balls, cue);
	}
}