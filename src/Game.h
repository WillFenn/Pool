#pragma once

#include <vector>
#include <limits>
#include <PoolMath.h>
#include <PoolColors.h>
#include <Window.h>
#include <Input.h>
#include <Player.h>
#include <Side.h>
#include <Cue.h>
#include <Ball.h>
#include <ext/matrix_transform.hpp>

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
	bool getCueBallShouldBePlaced();
	Player* getCurrentPlayer();
	bool cueBallShouldBeDrawn();
	bool cueShouldBeDrawn();
	bool trajectory(glm::vec2* pointA, glm::vec2* pointB);
	bool getGameDone();
	int getWinner();

private:
	void setPositions();
	void setCuePos(Window* window, Input* input);
	glm::vec2 getMouseWorldPos(Window* window, Input* input);
	void checkPocketedBalls();
	bool foul();
	bool positionOutOfBounds(Window* window, Input* input);
	bool detectBallCollision(glm::vec2* ball1Pos, glm::vec2* ball2Pos, glm::vec2* outCollisionNormal);
	bool allBallsPocketed(BallType ballType);

private:
	Side sides[18];
	glm::vec2 pocketPositions[6];
	Ball cueBall;
	bool eightBallPocketed = false;
	bool cueBallPocketed = false;
	bool stripedPocketed = false;
	bool solidPocketed = false;
	bool cueBallShouldBePlaced = false;
	bool leftMouseWasPressed = false;
	bool ballsMovedLastFrame = false;
	glm::vec2 leftClickStartPos;
	glm::vec2 cueStartPosition;
	float maxCueDistance = 30.0f;
	Cue cue;
	std::vector<Ball> balls;
	Player players[2];
	int currentPlayerIndex;
	bool gameDone = false;
	int winner;
};