#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <Window.h>
#include <Input.h>
#include <Ball.h>
#include <Cue.h>

float projection(glm::vec2 a, glm::vec2 b) {
	return glm::dot(a, b) / glm::length(b);
}

void setPositions(std::vector<Ball>* balls) {
	glm::vec2 frontPos = { 7.0f, 0.0f };
	float gapLength = 0.05;
	std::vector<glm::vec2> positions;

	for (int i = 0; i < 5; i++) {
		glm::vec2 columnStart = frontPos + (float)i * glm::vec2(1.0f + gapLength, 0.5f + gapLength / 2);
		for (int j = 0; j < i + 1; j++) {
			positions.push_back(columnStart + (float)j * glm::vec2(0.0f, -1.0f - gapLength));
		}
	}

	srand(time(0));

	std::cout << "balls->size(): " << balls->size() << std::endl;	// delete

	for (int i = 0; i < balls->size(); i++) {
		int randIndex = rand() % positions.size();
		balls->at(i).pos = positions.at(randIndex);
		positions.erase(positions.begin() + randIndex);
	}

	for (int i = 0; i < positions.size(); i++) {																		// delete
		std::cout << "position " << i << "     x: " << positions.at(i).x << "  y: " << positions.at(i).y << std::endl;	//
	}																													//

	for (int i = 0; i < balls->size(); i++) {																					// delete
		std::cout << "ball " << i << " position     x: " << balls->at(i).pos.x << "  y: " << balls->at(i).pos.y << std::endl;	//
	}																															//
}

void setCuePos(Window* window, Input* input, Cue* cue, Ball cueBall) {
	glm::vec2 mouseWorldPos = ((input->getMousePos() - window->getResolution() / 2.0f) / (window->getResolution() / 2.0f)) * (window->getWorldScale() / 2.0f);
	mouseWorldPos.y *= -1;
	
	if (input->leftMousePressed()) {
		glm::vec2 cueDirection = glm::normalize(cue->pos - cueBall.pos);
		glm::vec2 cueBallToMouse = mouseWorldPos - cueBall.pos;
		cue->pos = cueBall.pos + cueDirection * projection(cueBallToMouse, cueDirection);
	}
	else{
		glm::vec2 mouseDirection = glm::normalize(mouseWorldPos - cueBall.pos);
		cue->pos = cueBall.pos + mouseDirection * ((cue->scale.x / 2.0f) + 0.5f + cue->distanceFromCueBall);
		cue->rotation = glm::atan(mouseDirection.y / mouseDirection.x);
	}

	std::cout << "mouse position: " << "(" << mouseWorldPos.x << ", " << mouseWorldPos.y << ")" << std::endl;	// delete
}

int main() {
	std::cout << "starting" << std::endl;	// delete

	glm::vec4 white = { 255.0f / 255.0f, 255.0f / 255.0f, 255.0f / 255.0f, 1.0f };
	glm::vec4 black = { 0.0f / 255.0f, 0.0f / 255.0f, 0.0f / 255.0f, 1.0f };
	glm::vec4 yellow = { 255.0f / 255.0f, 255.0f / 255.0f, 0.0f / 255.0f, 1.0f };
	glm::vec4 red = { 255.0f / 255.0f, 0.0f / 255.0f, 0.0f / 255.0f, 1.0f };
	glm::vec4 lightGreen = { 0.0f / 255.0f, 150.0f / 255.0f, 0.0f / 255.0f, 1.0f };
	glm::vec4 darkGreen = { 0.0f / 255.0f, 80.0f / 255.0f, 0.0f / 255.0f, 1.0f };
	glm::vec4 blue = { 0.0f / 255.0f, 0.0f / 255.0f, 255.0f / 255.0f, 1.0f };
	glm::vec4 orange = { 255.0f / 255.0f, 128.0f / 255.0f, 0.0f / 255.0f, 1.0f };
	glm::vec4 purple = { 48.0f / 255.0f, 25.0f / 255.0f, 52.0f / 255.0f, 1.0f };
	glm::vec4 lightBrown = { 200.0f / 255.0f, 150.0f / 255.0f, 0.0f / 255.0f, 1.0f };
	glm::vec4 darkBrown = { 150.0f / 255.0f, 80.0f / 255.0f, 0.0f / 255.0f, 1.0f };

	glm::vec2 worldScale = { 48.0f, 27.0f };

	Window window(worldScale, lightGreen);

	Input input(window.getglfwwindow());

	std::vector<Ball> balls;
	balls.push_back({ { 0.0f, 0.0f }, black, false });
	balls.push_back({ { 0.0f, 0.0f }, yellow, false });
	balls.push_back({ { 0.0f, 0.0f }, yellow, true });
	balls.push_back({ { 0.0f, 0.0f }, red, false });
	balls.push_back({ { 0.0f, 0.0f }, red, true });
	balls.push_back({ { 0.0f, 0.0f }, darkGreen, false });
	balls.push_back({ { 0.0f, 0.0f }, darkGreen, true });
	balls.push_back({ { 0.0f, 0.0f }, blue, false });
	balls.push_back({ { 0.0f, 0.0f }, blue, true });
	balls.push_back({ { 0.0f, 0.0f }, orange, false });
	balls.push_back({ { 0.0f, 0.0f }, orange, true });
	balls.push_back({ { 0.0f, 0.0f }, purple, false });
	balls.push_back({ { 0.0f, 0.0f }, purple, true });
	balls.push_back({ { 0.0f, 0.0f }, darkBrown, false });
	balls.push_back({ { 0.0f, 0.0f }, darkBrown, true });

	setPositions(&balls);

	Ball cueBall = { {5.0f, 0.0f}, white, false };

	Cue cue = { {0.0f, 0.0f}, {10.0f, 0.2f}, 0.0f, lightBrown, {0.0f, 0.0f} };

	while (!(input.escKeyPressed() || window.shouldClose())) {
		window.drawFrame(&balls, cueBall, cue);
		
		setCuePos(&window, &input, &cue, cueBall);
	}
}