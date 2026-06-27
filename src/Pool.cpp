#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <vec2.hpp>
#include <PoolMath.h>
#include <PoolColors.h>
#include <Window.h>
#include <Input.h>
#include <Game.h>
#include <GameObject.h>
#include <Side.h>
#include <Ball.h>
#include <Cue.h>
#include <Physics.h>

int main() {
	Window window;

	Input input(window.getglfwwindow(), window.getResolution(), window.getWorldScale());

	Physics physics;

	Game game(&input, window.getWorldScale());

	int framesThisSecond = 0;
	double timeOfLastFrameRate = input.getTime();

	while (!(game.shouldClose() || window.shouldClose())) {
		framesThisSecond++;
		
		double currentTime = input.getTime();
		if (currentTime - timeOfLastFrameRate >= 1.0) {
			timeOfLastFrameRate = currentTime;
			game.setCurrentFrameRate(framesThisSecond);
			framesThisSecond = 0;
		}

		double deltaTime = input.getDeltaTime();

		game.update(deltaTime);

		physics.update(game.getSides(), game.getBalls(), game.getCueBall(), game.getCue(), deltaTime);

		// change
		glm::vec2 trajectoryA = { 0.0f, 0.0f };
		glm::vec2 trajectoryB = { 0.0f, 0.0f };

		bool trajectoryShouldBeDrawn;
		if (game.ballsAreMoving()) {
			trajectoryShouldBeDrawn = false;
		}
		else {
			trajectoryShouldBeDrawn = game.trajectory(&trajectoryA, &trajectoryB);
		}

		std::vector<GameObject> objects;
		objects.push_back(*game.getTable());
		objects.push_back(*game.getCueBall());
		objects.insert(objects.end(), game.getBalls()->begin(), game.getBalls()->end());
		objects.push_back(*game.getCue());

		std::vector<Line> lines;
		lines.push_back({ trajectoryA, trajectoryB });

		std::vector<Panel> panels;
		panels.push_back(*game.getFrameRatePanel());
		panels.push_back(*game.getStartMenu());
		panels.push_back(*game.getGameOverMenu());
		panels.insert(panels.end(), game.getPlayerPanels()->begin(), game.getPlayerPanels()->end());

		window.drawFrame(&objects, &lines, &panels);
	}
}