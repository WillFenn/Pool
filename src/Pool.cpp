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

	Input input(window.getglfwwindow());

	Physics physics;

	Game game;
	
	int numFrames = 0;

	double timeToFirstFrame = input.getTime();	

	while (!(input.escKeyPressed() || window.shouldClose())) {
		numFrames++;

		std::cout << std::endl << std::endl;
		std::cout << "frame " << numFrames << std::endl << "average framerate: " << numFrames / (input.getTime() - timeToFirstFrame) << std::endl;

		double deltaTime = input.getDeltaTime();

		game.update(&window, &input, deltaTime);

		physics.update(game.getSides(), game.getBalls(), game.getCueBall(), game.getCue(), deltaTime);

		// change
		glm::vec2 trajectoryA = glm::vec2(0.0f, 0.0f);
		glm::vec2 trajectoryB = glm::vec2(0.0f, 0.0f);

		bool trajectoryShouldBeDrawn;
		if (game.ballsAreMoving()) {
			trajectoryShouldBeDrawn = false;
		}
		else {
			trajectoryShouldBeDrawn = game.trajectory(&trajectoryA, &trajectoryB);
		}
		std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!trajectoryShouldBeDrawn: " << trajectoryShouldBeDrawn << std::endl;	// delete

		// delete
		//window.drawFrame(game.getSides(), game.getPocketPositions(), game.getBalls(), game.cueBallShouldBeDrawn() ? game.getCueBall() : nullptr, game.cueShouldBeDrawn() ? game.getCue() : nullptr,
		//	trajectoryShouldBeDrawn ? &trajectoryA : nullptr, trajectoryShouldBeDrawn ? &trajectoryB : nullptr, game.getCurrentPlayer(), game.getGameDone(), game.getWinner());

		std::vector<GameObject> objects;
		objects.push_back(*game.getTable());
		objects.push_back(*game.getCueBall());
		objects.insert(objects.end(), game.getBalls()->begin(), game.getBalls()->end());
		objects.push_back(*game.getCue());

		std::vector<Line> lines;
		lines.push_back({ trajectoryA, trajectoryB });

		window.drawFrame(&objects, &lines);
	}
}