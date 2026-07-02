#include <Game.h>

Game::Game(Input* input, glm::vec2 worldScale) {
	this->input = input;

	currentState = GameState::ShowStartMenu;

	startMenu = Menu({ 0.0f, 0.0f }, "res/textures/balls/one_ball.png", { 30.0f, 15.0f }, false, true, input);
	TextLabel playLabel("Play", -2.5f, 0.0f, PoolColors::black(), Font::Notable, FontSize::One, "res/textures/table.png", false, { 0.0f, 0.5f }, { 5.0f, 1.0f });
	MenuOption playMenuOption(MenuOptionType::Play, { 0.0f, 0.5f }, { 5.0f, 1.0f });
	startMenu.addMenuOption(playMenuOption, playLabel);
	TextLabel quitLabel("Quit", -2.5f, -1.0f, PoolColors::black(), Font::Notable, FontSize::One, "res/textures/table.png", false, { 0.0f, -0.5f }, { 5.0f, 1.0f });
	MenuOption quitMenuOption(MenuOptionType::Quit, { 0.0f, -0.5f }, { 5.0f, 1.0f });
	startMenu.addMenuOption(quitMenuOption, quitLabel);

	gameOverMenu = Menu({ 0.0f, 0.0f }, "res/textures/balls/one_ball.png", { 30.0f, 15.0f }, false, false, input);
	TextLabel playAgainLabel("Play Again", -2.5f, 0.0f, PoolColors::black(), Font::Notable, FontSize::One, "res/textures/table.png", false, { 0.0f, 0.5f }, { 5.0f, 1.0f });
	MenuOption playAgainMenuOption(MenuOptionType::Play, { 0.0f, 0.5f }, { 5.0f, 1.0f });
	gameOverMenu.addMenuOption(playAgainMenuOption, playAgainLabel);
	gameOverMenu.addMenuOption(quitMenuOption, quitLabel);

	frameRatePanel = Panel({ -(worldScale.x / 2) + 1, (worldScale.y / 2) - 1 }, true);
	TextLabel frameRateLabel("framerate:", 0, 0, PoolColors::black(), Font::Notable, FontSize::One);
	frameRatePanel.addTextLabel(frameRateLabel);

	table = GameObject(Shape::Rectangle, glm::vec2(0.0f, 0.0f), glm::vec2(52.0f, 31.0f), glm::mat4(1.0f), "res/textures/table.png", false, false);

	sides[0] = Side({ -24.0f, 13.5f - glm::sqrt(2) }, { -24.0f - glm::sqrt(2), 13.5f }, { 1 / glm::sqrt(2), 1 / glm::sqrt(2) });
	sides[1] = Side({ -24.0f, 13.5f + glm::sqrt(2) }, { -24.0f + glm::sqrt(2), 13.5f }, { -(1 / glm::sqrt(2)), -(1 / glm::sqrt(2)) });
	sides[2] = Side({ -24.0f + glm::sqrt(2), 13.5f }, { -1.2f, 13.5f }, { 0.0f, -1.0f });
	sides[3] = Side({ -1.2f, 13.5f }, { -1.0f, 14.5f }, { PoolMath::normal(glm::vec2(-1.0f, 14.5f) - glm::vec2(-1.2f, 13.5f)) });
	sides[4] = Side({ 1.0f, 14.5f }, { 1.2f, 13.5f }, { PoolMath::normal(glm::vec2(1.2f, 13.5f) - glm::vec2(1.0f, 14.5f)) });
	sides[5] = Side({ 1.2f, 13.5f }, { 24.0f - glm::sqrt(2), 13.5f }, { 0.0f, -1.0f });
	sides[6] = Side({ 24.0f - glm::sqrt(2), 13.5f }, { 24.0f, 13.5f + glm::sqrt(2) }, { 1 / glm::sqrt(2), -(1 / glm::sqrt(2)) });
	sides[7] = Side({ 24.0f + glm::sqrt(2), 13.5f }, { 24.0f, 13.5f - glm::sqrt(2) }, { -(1 / glm::sqrt(2)), 1 / glm::sqrt(2) });
	sides[8] = Side({ 24.0f, 13.5f - glm::sqrt(2) }, { 24.0f, -13.5f + glm::sqrt(2) }, { -1.0f, 0.0f });
	sides[9] = Side({ 24.0f, -13.5f + glm::sqrt(2) }, { 24.0f + glm::sqrt(2), -13.5f }, { -(1 / glm::sqrt(2)), -(1 / glm::sqrt(2)) });
	sides[10] = Side({ 24.0f, -13.5f - glm::sqrt(2) }, { 24.0f - glm::sqrt(2), -13.5f }, { 1 / glm::sqrt(2), 1 / glm::sqrt(2) });
	sides[11] = Side({ 24.0f - glm::sqrt(2), -13.5f }, { 1.2f, -13.5f }, { 0.0f, 1.0f });
	sides[12] = Side({ 1.2f, -13.5f }, { 1.0f, -14.5 }, { PoolMath::normal(glm::vec2(1.0f, -14.5) - glm::vec2(1.2f, -13.5f)) });
	sides[13] = Side({ -1.0f, -14.5f }, { -1.2, -13.5f }, { PoolMath::normal(glm::vec2(-1.2, -13.5f) - glm::vec2(-1.0f, -14.5f)) });
	sides[14] = Side({ -1.2, -13.5f }, { -24.0f + glm::sqrt(2), -13.5 }, { 0.0f, 1.0f });
	sides[15] = Side({ -24.0f + glm::sqrt(2), -13.5 }, { -24.0f, -13.5f - glm::sqrt(2) }, { PoolMath::normal(glm::vec2(-24.0f, -13.5f - glm::sqrt(2)) - glm::vec2(-24.0f + glm::sqrt(2), -13.5f)) });
	sides[16] = Side({ -24.0f - glm::sqrt(2), -13.5f }, { -24.0f, -13.5f + glm::sqrt(2) }, { PoolMath::normal(glm::vec2(-24.0f, -13.5f + glm::sqrt(2)) - glm::vec2(-24.0f - glm::sqrt(2), -13.5f)) });
	sides[17] = Side({ -24.0f, -13.5f + glm::sqrt(2) }, { -24.0f, 13.5f - glm::sqrt(2) }, { 1.0f, 0.0f });

	pocketPositions[0] = { -24.0f - (1 / glm::sqrt(2)), 13.5f + (1 / glm::sqrt(2)) };
	pocketPositions[1] = { 0.0f, 13.5f + 1.0f };
	pocketPositions[2] = { 24.0f + (1 / glm::sqrt(2)), 13.5f + (1 / glm::sqrt(2)) };
	pocketPositions[3] = { 24.0f + (1 / glm::sqrt(2)), -13.5f - (1 / glm::sqrt(2)) };
	pocketPositions[4] = { 0.0f, -13.5f - 1.0f };
	pocketPositions[5] = { -24.0f - (1 / glm::sqrt(2)), -13.5f - (1 / glm::sqrt(2)) };
	
	cueBall = Ball({ 5.0f, 0.0f }, "res/textures/balls/cue_ball.png", false, false,  0, BallType::Unassigned);

	leftClickStartPos = { std::numeric_limits<float>::max(), std::numeric_limits<float>::max() };
	
	cueStartPosition = cueBall.getPos() + glm::vec2(-1.0f, 0.0f) * ((10.0f / 2.0f) + 0.5f);
	maxCueDistance = 30.0f;
	cue = Cue(cueStartPosition, "res/textures/cue.png", false, false);

	balls.push_back(Ball({ 0.0f, 0.0f }, "res/textures/balls/one_ball.png", false, false, 1, BallType::Solid));
	balls.push_back(Ball({ 0.0f, 0.0f }, "res/textures/balls/two_ball.png", false, false, 2, BallType::Solid));
	balls.push_back(Ball({ 0.0f, 0.0f }, "res/textures/balls/three_ball.png", false, false, 3, BallType::Solid));
	balls.push_back(Ball({ 0.0f, 0.0f }, "res/textures/balls/four_ball.png", false, false, 4, BallType::Solid));
	balls.push_back(Ball({ 0.0f, 0.0f }, "res/textures/balls/five_ball.png", false, false, 5, BallType::Solid));
	balls.push_back(Ball({ 0.0f, 0.0f }, "res/textures/balls/six_ball.png", false, false, 6, BallType::Solid));
	balls.push_back(Ball({ 0.0f, 0.0f }, "res/textures/balls/seven_ball.png", false, false, 7, BallType::Solid));
	balls.push_back(Ball({ 0.0f, 0.0f }, "res/textures/balls/eight_ball.png", false, false, 8, BallType::Solid));
	balls.push_back(Ball({ 0.0f, 0.0f }, "res/textures/balls/nine_ball.png", false, false, 9, BallType::Striped));
	balls.push_back(Ball({ 0.0f, 0.0f }, "res/textures/balls/ten_ball.png", false, false, 10, BallType::Striped));
	balls.push_back(Ball({ 0.0f, 0.0f }, "res/textures/balls/eleven_ball.png", false, false, 11, BallType::Striped));
	balls.push_back(Ball({ 0.0f, 0.0f }, "res/textures/balls/twelve_ball.png", false, false, 12, BallType::Striped));
	balls.push_back(Ball({ 0.0f, 0.0f }, "res/textures/balls/thirteen_ball.png", false, false, 13, BallType::Striped));
	balls.push_back(Ball({ 0.0f, 0.0f }, "res/textures/balls/fourteen_ball.png", false, false, 14, BallType::Striped));
	balls.push_back(Ball({ 0.0f, 0.0f }, "res/textures/balls/fifteen_ball.png", false, false, 15, BallType::Striped));
	
	setBallPositions();

	players[0] = {1, Unassigned};
	players[1] = {2, Unassigned};

	Panel player1Panel({ -21.0f, 18.0f }, "res/textures/balls/one_ball.png", { 10.0f, 5.0f }, false, false);
	TextLabel player1Label("Player 1", -5.0f, 1.5f, PoolColors::white(), Font::Notable, FontSize::One);
	player1Panel.addTextLabel(player1Label);
	playerPanels.push_back(player1Panel);
	Panel player2Panel({ 21.0f, 18.0f }, "res/textures/balls/one_ball.png", { 10.0f, 5.0f }, false, false);
	TextLabel player2Label("Player 2", -5.0f, 1.5f, PoolColors::black(), Font::Notable, FontSize::One);
	player2Panel.addTextLabel(player2Label);
	playerPanels.push_back(player2Panel);

	trajectoryLength = 3.0f;

	currentPlayerIndex = 0;
}

Game::~Game() {

}

void Game::update(float deltaTime) {
	if (input->escKeyPressed()) {
		std::cout << "1" << std::endl;	// delete
		currentState = GameState::Close;
	}
	else if (currentState == GameState::ShowStartMenu) {
		std::cout << "2" << std::endl;	// delete
		startMenu.update();

		if (startMenu.getSelectedOption() == MenuOptionType::Play) {
			currentState = GameState::PlayGame;

			startMenu.setActive(false);
			table.setActive(true);
			cueBall.setActive(true);
			cue.setActive(true);
			playerPanels[0].setActive(true);
			playerPanels[1].setActive(true);

			for (Ball& ball : balls) {
				ball.setActive(true);
			}
		}
		else if (startMenu.getSelectedOption() == MenuOptionType::Quit) {
			currentState = GameState::Close;
		}
	}
	else if (currentState == GameState::PlayGame) {
		std::cout << "3" << std::endl;	// delete
		bool ballsMovingThisFrame = ballsAreMoving();

		if (!ballsMovingThisFrame && ballsMovedLastFrame) {
			// beginning of turn

			if (foul()) {
				// change current player
				currentPlayerIndex = (currentPlayerIndex + 1) % 2;

				// update player panels to show current player
				playerPanels[(currentPlayerIndex + 1) % 2].getTextLabels()->front().setColor(PoolColors::black());
				playerPanels[currentPlayerIndex].getTextLabels()->front().setColor(PoolColors::white());
			}

			cueBallPocketed = false;
			stripedPocketed = false;
			solidPocketed = false;
		}

		if (ballsMovingThisFrame || cueBallShouldBePlaced) {
			cue.setActive(false);
		}
		else {
			cue.setActive(true);
		}

		if (cue.getActive()) {
			setCuePos();
		}

		checkPocketedBalls();

		if (cueBallShouldBePlaced && !ballsMovingThisFrame && !positionOutOfBounds()) {
			cueBall.setPos(input->getMouseWorldPos());

			if (input->leftMousePressed()) {
				leftMouseWasPressed = true;
			}
			else if (leftMouseWasPressed) {
				cueBallShouldBePlaced = false;
				leftMouseWasPressed = false;
			}
		} 

		if (eightBallPocketed) {
			currentState = GameState::ShowGameOver;

			int winner;

			if (allBallsPocketed(players[currentPlayerIndex].ballType)) {
				winner = currentPlayerIndex + 1;
			}
			else {
				winner = ((currentPlayerIndex + 1) % 2) + 1;
			}

			std::string winnerLabelText;

			if (winner == 1) {
				winnerLabelText = "Player 1 wins";
			}
			else if (winner == 2) {
				winnerLabelText = "Player 2 wins";
			}

			TextLabel winnerLabel(winnerLabelText, -2.5, 3.0f, PoolColors::black(), Font::Notable, FontSize::One);
			gameOverMenu.addTextLabel(winnerLabel);

			playerPanels[0].setActive(false);
			playerPanels[1].setActive(false);
			table.setActive(false);
			cueBall.setActive(false);
			cue.setActive(false);

			for (Ball& ball : balls) {
				ball.setActive(false);
			}

			gameOverMenu.setActive(true);
		}

		ballsMovedLastFrame = ballsMovingThisFrame;
	}
	else if (currentState == GameState::ShowGameOver) {
		std::cout << "4" << std::endl;	// delete
		gameOverMenu.update();

		if (gameOverMenu.getSelectedOption() == MenuOptionType::Play) {
			currentState = GameState::PlayGame;
		}
		else if (gameOverMenu.getSelectedOption() == MenuOptionType::Quit || input->escKeyPressed()) {
			currentState = GameState::Close;
		}
	}
}

bool Game::shouldClose() const {
	return currentState == GameState::Close;
}

const Menu* Game::getStartMenu() const {
	return &startMenu;
}

const Menu* Game::getGameOverMenu() const {
	return &gameOverMenu;
}

const Panel* Game::getFrameRatePanel() const {
	return &frameRatePanel;
}

void Game::setCurrentFrameRate(int currentFrameRate) {
	std::cout << "framerate: " + currentFrameRate << std::endl;
	frameRatePanel.getTextLabels()->front().setText(std::string("framerate: ") + std::to_string(currentFrameRate));
}

bool Game::ballsAreMoving() const {
	if (glm::length(cueBall.getVelocity()) != 0.0f) {
		return true;
	}

	for (Ball& ball : balls | std::ranges::views::filter([](Ball& ball) { return ball.getActive(); })) {
		if (glm::length(ball.getVelocity()) != 0.0f) {
			return true;
		}
	}

	return false;
}

const GameObject* Game::getTable() const {
	return &table;
}

Side* Game::getSides() {
	return sides;
}

const glm::vec2* Game::getPocketPositions() const {
	return pocketPositions;
}

Ball* Game::getCueBall() {
	return &cueBall;
}

Cue* Game::getCue() {
	return &cue;
}

std::vector<Ball>* Game::getBalls() {
	return &balls;
}

bool Game::getCueBallShouldBePlaced() const {
	return cueBallShouldBePlaced;
}

const Player* Game::getCurrentPlayer() const {
	return &players[currentPlayerIndex];
}

bool Game::cueBallShouldBeDrawn() const {
	return !cueBallShouldBePlaced || !ballsAreMoving();
}

bool Game::cueShouldBeDrawn() const {
	return !ballsAreMoving() && !cueBallShouldBePlaced;
}

std::optional<Line> Game::trajectory() const {
	if (ballsAreMoving()) {
		return std::optional<Line>();
	}

	glm::vec2 cueBallPathStart = cueBall.getPos();
	glm::vec2 cueBallPath = glm::normalize(cueBallPathStart - cue.getPos());
	glm::vec2 cueBallPathEnd = cueBallPathStart + 60.0f * cueBallPath;

	glm::vec2 collidingBallPos(std::numeric_limits<float>::max(), std::numeric_limits<float>::max());
	glm::vec2 closestPointToBall;

	for (Ball& ball : balls | std::ranges::views::filter([](Ball& ball) { return ball.getActive(); })) {
		glm::vec2 closestPoint;
		float pathBallDistance = PoolMath::pointLineSegmentDistance(ball.getPos(), cueBallPathStart, cueBallPathEnd, &closestPoint);
		
		if (pathBallDistance <= 1.0f && glm::distance(cueBall.getPos(), ball.getPos()) < glm::distance(cueBall.getPos(), collidingBallPos)) {
			collidingBallPos = ball.getPos();
			closestPointToBall = closestPoint;
		}
	}

	if (collidingBallPos != glm::vec2(std::numeric_limits<float>::max(), std::numeric_limits<float>::max())) {
		glm::vec2 cueBallCollisionPos = closestPointToBall - (float)glm::sqrt(1.0f - glm::pow(glm::distance(collidingBallPos, closestPointToBall), 2)) * cueBallPath;
		glm::vec2 cueBallToBall = collidingBallPos - cueBallCollisionPos;

		Line line(collidingBallPos, collidingBallPos + trajectoryLength * cueBallToBall);
		return std::optional<Line>(line);
	}
	else {
		return std::optional<Line>();
	}
}

const std::vector<Panel>* Game::getPlayerPanels() const {
	return &playerPanels;
}

void Game::setBallPositions() {
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

	for (Ball& ball : balls) {
		int randIndex = rand() % positions.size();
		ball.setPos(positions.at(randIndex));
		positions.erase(positions.begin() + randIndex);
	}
}

void Game::setCuePos() {
	glm::vec2 mouseWorldPos = input->getMouseWorldPos();

	if (input->leftMousePressed()) {
		if (leftClickStartPos.x == std::numeric_limits<float>::max()) {
			leftClickStartPos = mouseWorldPos;
		}

		glm::vec2 cueDirection = glm::normalize(cue.getPos() - cueBall.getPos());
		glm::vec2 leftClickStartToMouse = mouseWorldPos - leftClickStartPos;
		cue.setPos(cueBall.getPos() + cueDirection * glm::clamp((((cue.getScale().x / 2) + 0.5f) + PoolMath::projection(leftClickStartToMouse, cueDirection)), ((cue.getScale().x / 2) + 0.5f), maxCueDistance));
		cue.setWasPulledBack(true);
	}
	else {
		if (cue.getWasPulledBack()) {
			cue.setSpeed(3 * (glm::distance(cueBall.getPos(), cue.getPos()) - ((cue.getScale().x / 2) + 0.5f)));
			cue.setWasPulledBack(false);
			leftClickStartPos = { std::numeric_limits<float>::max(), std::numeric_limits<float>::max() };
		}
		else if (cue.getSpeed() == 0.0f) {
			glm::vec2 mouseDirection;
			if (!PoolMath::approximatelyEqual(mouseWorldPos, cueBall.getPos(), 0.0001f)) {
				mouseDirection = glm::normalize(mouseWorldPos - cueBall.getPos());
			}
			else {
				mouseDirection = glm::vec2(-1.0f, 0.0f);
			}
			
			cue.setPos(cueBall.getPos() - mouseDirection * ((cue.getScale().x / 2.0f) + 0.5f));
			
			float rotation = atan(mouseDirection.y / mouseDirection.x);
			cue.setRotationMat(PoolMath::addToRotationMat(glm::mat4(1.0f), rotation, glm::vec3(0.0f, 0.0f, -1.0f)));

			if (mouseDirection.x < 0) {
				cue.setRotationMat(PoolMath::addToRotationMat(cue.getRotationMat(), glm::pi<float>(), glm::vec3(0.0f, 0.0f, 1.0f)));
			}
		}
	}

	//std::cout << "mouse position: " << "(" << mouseWorldPos.x << ", " << mouseWorldPos.y << ")" << std::endl;	// delete
	std::cout << std::endl;	// delete
}

void Game::checkPocketedBalls() {
	// check object balls
	for (int j = 0; j < 6; j++) {
		for (int i = 0; i < balls.size(); i++) {
			if (balls.at(i).getActive() && glm::distance(pocketPositions[j], balls.at(i).getPos()) < 1.0f) {
				// check the ball type of the pocketed ball
				if (balls.at(i).getBallType() == Striped) {
					stripedPocketed = true;
				}
				else {
					solidPocketed = true;
				}

				// check if pocketed ball is eight ball
				if (balls.at(i).getIndex() == 8) {
					eightBallPocketed = true;
				}
				
				// assign a ball type to each player
				if (players[currentPlayerIndex].ballType == Unassigned) {
					if (stripedPocketed) {
						players[currentPlayerIndex].ballType = Striped;
						players[(currentPlayerIndex + 1) % 2].ballType = Solid;
					}
					else {
						players[currentPlayerIndex].ballType = Solid;
						players[(currentPlayerIndex + 1) % 2].ballType = Striped;
					}

					TextLabel player1BallTypeLabel(players[0].ballType == Striped ? "Stripes" : "Solids", -5.0f, 0.5f, PoolColors::black(), Font::Notable, FontSize::One);
					playerPanels[0].addTextLabel(player1BallTypeLabel);
					TextLabel player2BallTypeLabel(players[1].ballType == Solid ? "Solids" : "Stripes", -5.0f, 0.5f, PoolColors::black(), Font::Notable, FontSize::One);
					playerPanels[1].addTextLabel(player2BallTypeLabel);
				}

				balls.at(i).setActive(false);
			}
		}

		// check cue ball
		if (glm::distance(pocketPositions[j], cueBall.getPos()) < 1.0f) {
			cueBall.setVelocity(glm::vec2(0.0f, 0.0f));
			cueBallPocketed = true;
			cueBallShouldBePlaced = true;
		}
	}
}

bool Game::foul() {
	if (cueBallPocketed) {
		return true;
	}

	if (players[currentPlayerIndex].ballType == Striped && !stripedPocketed) {
		return true;
	}

	if (players[currentPlayerIndex].ballType == Solid && !solidPocketed) {
		return true;
	}

	if (players[currentPlayerIndex].ballType == Unassigned && !solidPocketed && !stripedPocketed) {
		return true;
	}

	return false;
}

bool Game::positionOutOfBounds() const {
	glm::vec2 mouseWorldPos = input->getMouseWorldPos();

	for (Ball& ball : balls | std::ranges::views::filter([](Ball& ball) { return ball.getActive(); })) {
		if (glm::distance(ball.getPos(), mouseWorldPos) < 1.0f) {
			return true;
		}
	}

	for (int i = 0; i < 6; i++) {
		if (glm::distance(pocketPositions[i], mouseWorldPos) < 1.5f) {
			return true;
		}
	}

	if (mouseWorldPos.x < -23.5f || mouseWorldPos.x > 23.5f || mouseWorldPos.y < -13.0f || mouseWorldPos.y > 13.0f) {
		return true;
	}

	return false;
}

bool Game::detectBallCollision(glm::vec2 ball1Pos, glm::vec2 ball2Pos, glm::vec2* outCollisionNormal) const {
	if (glm::length(ball1Pos - ball2Pos) <= 1.0f) {
		*outCollisionNormal = glm::normalize(ball2Pos - ball1Pos);

		return true;
	}

	return false;
}

bool Game::allBallsPocketed(BallType ballType) const {
	for (Ball& ball : balls | std::ranges::views::filter([](Ball& ball) { return ball.getActive(); })) {
		if (ball.getBallType() == ballType) {
			return false;
		}
	}

	return true;
}