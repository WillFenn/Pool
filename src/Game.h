#pragma once

#include <vector>
#include <PoolMath.h>
#include <PoolColors.h>
#include <Window.h>
#include <Input.h>
#include <Side.h>
#include <Cue.h>
#include <Ball.h>
#include <ext/matrix_transform.hpp>

enum Player { Player1, Player2 };

class Game {
public:
	Game();
	~Game();
	void update(Window* window, Input* input, float deltaTime);
	bool ballsAreMoving();
	Side* getSides();
	glm::vec2* getPocketPositions();
	Ball* getCueBall();
	Cue* getCue();
	std::vector<Ball>* getBalls();
	Player getCurrentPlayer();

private:
	void setPositions();
	void setCuePos(Window* window, Input* input);
	void removeBallsInPockets();

private:
	Side sides[18];
	glm::vec2 pocketPositions[6];
	Ball cueBall;
	glm::vec2 cueStartPosition;
	Cue cue;
	std::vector<Ball> balls;
	Player currentPlayer;
};