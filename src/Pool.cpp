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

		glm::vec2 trajectoryA;
		glm::vec2 trajectoryB;

		bool trajectoryShouldBeDrawn;
		if (game.ballsAreMoving()) {
			trajectoryShouldBeDrawn = false;
		}
		else {
			trajectoryShouldBeDrawn = game.trajectory(&trajectoryA, &trajectoryB);
		}
		std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!trajectoryShouldBeDrawn: " << trajectoryShouldBeDrawn << std::endl;	// delete

		window.drawFrame(game.getSides(), game.getPocketPositions(), game.getBalls(), game.cueBallShouldBeDrawn() ? game.getCueBall() : nullptr, game.cueShouldBeDrawn() ? game.getCue() : nullptr,
			trajectoryShouldBeDrawn ? &trajectoryA : nullptr, trajectoryShouldBeDrawn ? &trajectoryB : nullptr, game.getCurrentPlayer(), game.getGameDone(), game.getWinner());
	}
}