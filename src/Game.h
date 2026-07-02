#pragma once

#include <vector>
#include <limits>
#include <ranges>
#include <optional>
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

enum GameState { ShowStartMenu, PlayGame, ShowGameOver, Close };

class Game {
public:
	Game(Input* input, glm::vec2 worldScale);
	~Game();
	void update(float deltaTime);
	bool shouldClose() const;
	const Menu* getStartMenu() const;
	const Menu* getGameOverMenu() const;
	const Panel* getFrameRatePanel() const;
	void setCurrentFrameRate(int currentFrameRate);
	bool ballsAreMoving() const;
	const GameObject* getTable() const;
	Side* getSides();
	const glm::vec2* getPocketPositions() const;
	Ball* getCueBall();
	Cue* getCue();
	std::vector<Ball>* getBalls();
	bool getCueBallShouldBePlaced() const;
	const Player* getCurrentPlayer() const;
	bool cueBallShouldBeDrawn() const;
	bool cueShouldBeDrawn() const;
	std::optional<Line> trajectory() const;
	const std::vector<Panel>* getPlayerPanels() const;

private:
	void setBallPositions();
	void setCuePos();
	void checkPocketedBalls();
	bool foul() const;
	bool positionOutOfBounds() const;
	bool detectBallCollision(glm::vec2 ball1Pos, glm::vec2 ball2Pos, glm::vec2* outCollisionNormal) const;
	bool allBallsPocketed(BallType ballType) const;

private:
	Input* input;
	GameState currentState;
	Menu startMenu;
	Menu gameOverMenu;
	Panel frameRatePanel;
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
	float maxCueDistance;
	Cue cue;
	std::vector<Ball> balls;
	Player players[2];
	std::vector<Panel> playerPanels;
	float trajectoryLength;
	int currentPlayerIndex;
};