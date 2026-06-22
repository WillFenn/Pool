#pragma once

#include <vector>
#include <limits>
#include <PoolMath.h>
#include <PoolColors.h>
#include <Menu.h>
#include <GameObject.h>
#include <Panel.h>
#include <Texture.h>
#include <Window.h>
#include <Input.h>
#include <Player.h>
#include <Side.h>
#include <Cue.h>
#include <Ball.h>
#include <ext/matrix_transform.hpp>

enum GameState { ShowStartMenu, PlayGame, ShowGameOver, Quit };

class Game {
public:
	Game(Input* input);
	~Game();
	void update(Window* window, float deltaTime);
	bool shouldClose();
	Menu* getStartMenu();
	bool ballsAreMoving();
	GameObject* getTable();
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
	Panel* getPlayer1Panel();
	Panel* getPlayer2Panel();

private:
	void setPositions();
	void setCuePos(Window* window);
	void checkPocketedBalls();
	bool foul();
	bool positionOutOfBounds(Window* window);
	bool detectBallCollision(glm::vec2 ball1Pos, glm::vec2 ball2Pos, glm::vec2* outCollisionNormal);
	bool allBallsPocketed(BallType ballType);
	void updatePlayerPanels();

private:
	Input* input;
	GameState currentState;
	Menu startMenu;
	Menu gameOverMenu;
	GameObject table;
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
	Panel player1Panel;
	Panel player2Panel;
	int currentPlayerIndex;
};