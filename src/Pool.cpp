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
		std::cout << "game and physics updated" << std::endl;	// delete
		window.drawFrame(game.getSides(), game.getPocketPositions(), game.getBalls(), game.getCueBall(), game.ballsAreMoving() ? nullptr : game.getCue());
	}
}