#include <Game.h>

Game::Game(Input* input) {
	this->input = input;

	startMenu = Menu({ 0.0f, 0.0f }, "res/textures/balls/one_ball.png", { 30.0f, 15.0f }, false, input);
	TextLabel playLabel("Play", -2.5f, 0.0f, PoolColors::black(), Font::Monoton, FontSize::One, "res/textures/table.png", false, { 0.0f, 0.5f }, { 5.0f, 1.0f });
	MenuOption playMenuOption(MenuOptionType::Play, { 0.0f, 0.5f }, { 5.0f, 1.0f });
	startMenu.addMenuOption(playMenuOption, playLabel);
	TextLabel quitLabel("Quit", -2.5f, -1.0f, PoolColors::black(), Font::Monoton, FontSize::One, "res/textures/table.png", false, { 0.0f, -0.5f }, { 5.0f, 1.0f });
	MenuOption quitMenuOption(MenuOptionType::Quit, { 0.0f, -0.5f }, { 5.0f, 1.0f });
	startMenu.addMenuOption(quitMenuOption, quitLabel);

	table = GameObject(Shape::Rectangle, glm::vec2(0.0f, 0.0f), glm::vec2(52.0f, 31.0f), glm::mat4(1.0f), "res/textures/table.png", false);

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
	
	// delete
	//sides[0] = { { { -24.0f, 13.5f - glm::sqrt(2) }, { -24.0f - glm::sqrt(2), 13.5f } }, { 1 / glm::sqrt(2), 1 / glm::sqrt(2)} };
	//sides[1] = { { { -24.0f, 13.5f + glm::sqrt(2) }, { -24.0f + glm::sqrt(2), 13.5f } }, { -(1 / glm::sqrt(2)), -(1 / glm::sqrt(2))} };
	//sides[2] = { { { -24.0f + glm::sqrt(2), 13.5f }, { -1.2f, 13.5f } }, { 0.0f, -1.0f } };
	//sides[3] = { { { -1.2f, 13.5f }, { -1.0f, 14.5f } }, { PoolMath::normal(glm::vec2(-1.0f, 14.5f) - glm::vec2(-1.2f, 13.5f)) } };
	//sides[4] = { { { 1.0f, 14.5f }, { 1.2f, 13.5f } }, { PoolMath::normal(glm::vec2(1.2f, 13.5f) - glm::vec2(1.0f, 14.5f)) } };
	//sides[5] = { { { 1.2f, 13.5f }, { 24.0f - glm::sqrt(2), 13.5f } }, { 0.0f, -1.0f } };
	//sides[6] = { { { 24.0f - glm::sqrt(2), 13.5f }, { 24.0f, 13.5f + glm::sqrt(2) } }, { 1 / glm::sqrt(2), -(1 / glm::sqrt(2)) } };
	//sides[7] = { { { 24.0f + glm::sqrt(2), 13.5f }, { 24.0f, 13.5f - glm::sqrt(2) } }, { -(1 / glm::sqrt(2)), 1 / glm::sqrt(2) } };
	//sides[8] = { { { 24.0f, 13.5f - glm::sqrt(2) }, { 24.0f, -13.5f + glm::sqrt(2) } }, { -1.0f, 0.0f } };
	//sides[9] = { { { 24.0f, -13.5f + glm::sqrt(2) }, { 24.0f + glm::sqrt(2), -13.5f } }, { -(1 / glm::sqrt(2)), -(1 / glm::sqrt(2)) } };
	//sides[10] = { { { 24.0f, -13.5f - glm::sqrt(2) }, { 24.0f - glm::sqrt(2), -13.5f } }, { 1 / glm::sqrt(2), 1 / glm::sqrt(2) } };
	//sides[11] = { { { 24.0f - glm::sqrt(2), -13.5f }, { 1.2f, -13.5f } }, { 0.0f, 1.0f } };
	//sides[12] = { { { 1.2f, -13.5f }, { 1.0f, -14.5 } }, { PoolMath::normal(glm::vec2(1.0f, -14.5) - glm::vec2(1.2f, -13.5f)) } };
	//sides[13] = { { { -1.0f, -14.5f }, { -1.2, -13.5f } }, { PoolMath::normal(glm::vec2(-1.2, -13.5f) - glm::vec2(-1.0f, -14.5f)) } };
	//sides[14] = { { { -1.2, -13.5f }, { -24.0f + glm::sqrt(2), -13.5 } }, { 0.0f, 1.0f } };
	//sides[15] = { { { -24.0f + glm::sqrt(2), -13.5 }, { -24.0f, -13.5f - glm::sqrt(2) } }, { PoolMath::normal(glm::vec2(-24.0f, -13.5f - glm::sqrt(2)) - glm::vec2(-24.0f + glm::sqrt(2), -13.5f)) } };
	//sides[16] = { { { -24.0f - glm::sqrt(2), -13.5f }, { -24.0f, -13.5f + glm::sqrt(2) } }, { PoolMath::normal(glm::vec2(-24.0f, -13.5f + glm::sqrt(2)) - glm::vec2(-24.0f - glm::sqrt(2), -13.5f)) } };
	//sides[17] = { { { -24.0f, -13.5f + glm::sqrt(2) }, { -24.0f, 13.5f - glm::sqrt(2) } }, { 1.0f, 0.0f } };

	pocketPositions[0] = { -24.0f - (1 / glm::sqrt(2)), 13.5f + (1 / glm::sqrt(2)) };
	pocketPositions[1] = { 0.0f, 13.5f + 1.0f };
	pocketPositions[2] = { 24.0f + (1 / glm::sqrt(2)), 13.5f + (1 / glm::sqrt(2)) };
	pocketPositions[3] = { 24.0f + (1 / glm::sqrt(2)), -13.5f - (1 / glm::sqrt(2)) };
	pocketPositions[4] = { 0.0f, -13.5f - 1.0f };
	pocketPositions[5] = { -24.0f - (1 / glm::sqrt(2)), -13.5f - (1 / glm::sqrt(2)) };
	
	cueBall = Ball({ 5.0f, 0.0f }, "res/textures/balls/cue_ball.png", false,  0, BallType::Unassigned);

	// delete
	//cueBall = { 0, { 5.0f, 0.0f }, glm::rotate(glm::mat4(1.0f), 0.0f, glm::vec3(1.0f, 0.0f, 0.0f)), {0.0f, 0.0f}, Solid, new Texture("res/textures/balls/cue_ball.png", false) };

	leftClickStartPos = { std::numeric_limits<float>::max(), std::numeric_limits<float>::max() };
	
	cueStartPosition = cueBall.getPos() + glm::vec2(-1.0f, 0.0f) * ((10.0f / 2.0f) + 0.5f);
	cue = Cue(cueStartPosition, "res/textures/cue.png", false);

	// delete
	//cue = { cueStartPosition, { 10.0f, 0.2f }, 0.0f, 0.0f, new Texture("res/textures/cue.png", true), false};

	balls.push_back(Ball({ 0.0f, 0.0f }, "res/textures/balls/one_ball.png", false, 1, BallType::Solid));
	balls.push_back(Ball({ 0.0f, 0.0f }, "res/textures/balls/two_ball.png", false, 2, BallType::Solid));
	balls.push_back(Ball({ 0.0f, 0.0f }, "res/textures/balls/three_ball.png", false, 3, BallType::Solid));
	balls.push_back(Ball({ 0.0f, 0.0f }, "res/textures/balls/four_ball.png", false, 4, BallType::Solid));
	balls.push_back(Ball({ 0.0f, 0.0f }, "res/textures/balls/five_ball.png", false, 5, BallType::Solid));
	balls.push_back(Ball({ 0.0f, 0.0f }, "res/textures/balls/six_ball.png", false, 6, BallType::Solid));
	balls.push_back(Ball({ 0.0f, 0.0f }, "res/textures/balls/seven_ball.png", false, 7, BallType::Solid));
	balls.push_back(Ball({ 0.0f, 0.0f }, "res/textures/balls/eight_ball.png", false, 8, BallType::Solid));
	balls.push_back(Ball({ 0.0f, 0.0f }, "res/textures/balls/nine_ball.png", false, 9, BallType::Striped));
	balls.push_back(Ball({ 0.0f, 0.0f }, "res/textures/balls/ten_ball.png", false, 10, BallType::Striped));
	balls.push_back(Ball({ 0.0f, 0.0f }, "res/textures/balls/eleven_ball.png", false, 11, BallType::Striped));
	balls.push_back(Ball({ 0.0f, 0.0f }, "res/textures/balls/twelve_ball.png", false, 12, BallType::Striped));
	balls.push_back(Ball({ 0.0f, 0.0f }, "res/textures/balls/thirteen_ball.png", false, 13, BallType::Striped));
	balls.push_back(Ball({ 0.0f, 0.0f }, "res/textures/balls/fourteen_ball.png", false, 14, BallType::Striped));
	balls.push_back(Ball({ 0.0f, 0.0f }, "res/textures/balls/fifteen_ball.png", false, 15, BallType::Striped));
	
	// delete
	//balls.push_back({ 1, { 0.0f, 0.0f }, initialRotation, { 0.0f, 0.0f }, Solid, new Texture("res/textures/balls/one_ball.png", false) });
	//balls.push_back({ 2, { 0.0f, 0.0f }, initialRotation, { 0.0f, 0.0f }, Solid, new Texture("res/textures/balls/two_ball.png", false) });
	//balls.push_back({ 3, { 0.0f, 0.0f }, initialRotation, { 0.0f, 0.0f }, Solid, new Texture("res/textures/balls/three_ball.png", false) });
	//balls.push_back({ 4, { 0.0f, 0.0f }, initialRotation, { 0.0f, 0.0f }, Solid, new Texture("res/textures/balls/four_ball.png", false) });
	//balls.push_back({ 5, { 0.0f, 0.0f }, initialRotation, { 0.0f, 0.0f }, Solid, new Texture("res/textures/balls/five_ball.png", false) });
	//balls.push_back({ 6, { 0.0f, 0.0f }, initialRotation, { 0.0f, 0.0f }, Solid, new Texture("res/textures/balls/six_ball.png", false) });
	//balls.push_back({ 7, { 0.0f, 0.0f }, initialRotation, { 0.0f, 0.0f }, Solid, new Texture("res/textures/balls/seven_ball.png", false) });
	//balls.push_back({ 8, { 0.0f, 0.0f }, initialRotation, { 0.0f, 0.0f }, Solid, new Texture("res/textures/balls/eight_ball.png", false) });
	//balls.push_back({ 9, { 0.0f, 0.0f }, initialRotation, { 0.0f, 0.0f }, Striped, new Texture("res/textures/balls/nine_ball.png", false) });
	//balls.push_back({ 10, { 0.0f, 0.0f }, initialRotation, { 0.0f, 0.0f }, Striped, new Texture("res/textures/balls/ten_ball.png", false) });
	//balls.push_back({ 11, { 0.0f, 0.0f }, initialRotation, { 0.0f, 0.0f }, Striped, new Texture("res/textures/balls/eleven_ball.png", false) });
	//balls.push_back({ 12, { 0.0f, 0.0f }, initialRotation, { 0.0f, 0.0f }, Striped, new Texture("res/textures/balls/twelve_ball.png", false) });
	//balls.push_back({ 13, { 0.0f, 0.0f }, initialRotation, { 0.0f, 0.0f }, Striped, new Texture("res/textures/balls/thirteen_ball.png", false) });
	//balls.push_back({ 14, { 0.0f, 0.0f }, initialRotation, { 0.0f, 0.0f }, Striped, new Texture("res/textures/balls/fourteen_ball.png", false) });
	//balls.push_back({ 15, { 0.0f, 0.0f }, initialRotation, { 0.0f, 0.0f }, Striped, new Texture("res/textures/balls/fifteen_ball.png", false) });
	
	setPositions();

	players[0] = {1, Unassigned};
	players[1] = {2, Unassigned};

	player1Panel = Panel({ -21.0f, 18.0f }, "res/textures/balls/one_ball.png", { 10.0f, 5.0f }, false);
	player1Panel.addTextLabel("Player 1", -5.0f, 1.5f, PoolColors::black(), Font::Monoton, FontSize::One);
	player2Panel = Panel({ 21.0f, 18.0f }, "res/textures/balls/one_ball.png", { 10.0f, 5.0f }, false);
	player2Panel.addTextLabel("Player 2", -5.0f, 1.5f, PoolColors::black(), Font::Monoton, FontSize::One);

	currentPlayerIndex = 0;
}

Game::~Game() {

}

void Game::update(Window* window, float deltaTime) {
	startMenu.update();

	bool ballsMovingThisFrame = ballsAreMoving();

	if (!ballsMovingThisFrame && ballsMovedLastFrame) {
		// beginning of turn
		std::cout << "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" << std::endl;	// delete
		
		if (foul()) {
			// change current player
			currentPlayerIndex = (currentPlayerIndex + 1) % 2;
		}
		
		cueBallPocketed = false;
		stripedPocketed = false;
		solidPocketed = false;
	}
	
	//std::cout << "ballsAreMoving(): " << ballsAreMoving() << std::endl;	// delete
	//std::cout << "cueBallShouldBePlaced: " << cueBallShouldBePlaced << std::endl;	// delete
	if (!ballsMovingThisFrame && !cueBallShouldBePlaced) {
		setCuePos(window);
	}

	checkPocketedBalls();

	if (cueBallShouldBePlaced && !ballsMovingThisFrame && !positionOutOfBounds(window)) {
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
		gameDone = true;

		if (allBallsPocketed(players[currentPlayerIndex].ballType)) {
			winner = currentPlayerIndex + 1;
		}
		else {
			winner = ((currentPlayerIndex + 1) % 2) + 1;
		}
	}

	updatePlayerPanels();

	ballsMovedLastFrame = ballsMovingThisFrame;
}

Menu* Game::getStartMenu() {
	return &startMenu;
}

bool Game::ballsAreMoving() {
	if (glm::length(cueBall.getVelocity()) != 0.0f) {
		return true;
	}

	for (int i = 0; i < balls.size(); i++) {
		if (glm::length(balls.at(i).getVelocity()) != 0.0f) {
			return true;
		}
	}

	return false;
}

GameObject* Game::getTable() {
	return &table;
}

Side* Game::getSides() {
	return sides;
}

glm::vec2* Game::getPocketPositions() {
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

bool Game::getCueBallShouldBePlaced() {
	return cueBallShouldBePlaced;
}

Player* Game::getCurrentPlayer() {
	return &players[currentPlayerIndex];
}

bool Game::cueBallShouldBeDrawn() {
	return !cueBallShouldBePlaced || !ballsAreMoving();
}

bool Game::cueShouldBeDrawn() {
	return !ballsAreMoving() && !cueBallShouldBePlaced;
}

bool Game::trajectory(glm::vec2* pointA, glm::vec2* pointB) {
	glm::vec2 pathPos = cueBall.getPos();
	glm::vec2 pathIncrement = 0.01f * glm::normalize(cueBall.getPos() - cue.getPos());
	glm::vec2 collisionNormal;

	while (pathPos.x > -23.5f && pathPos.x < 23.5f && pathPos.y > -13.0f && pathPos.y < 13.0f) {
		for (int i = 0; i < balls.size(); i++) {
			if (detectBallCollision(pathPos, balls.at(i).getPos(), &collisionNormal)) {
				*pointA = balls.at(i).getPos();
				*pointB = balls.at(i).getPos() + 3.0f * collisionNormal;
				
				return true;
			}
		}

		pathPos += pathIncrement;
	}

	return false;
}

Panel* Game::getPlayer1Panel() {
	return &player1Panel;
}

Panel* Game::getPlayer2Panel() {
	return &player2Panel;
}

void Game::setPositions() {
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

	std::cout << "balls->size(): " << balls.size() << std::endl;	// delete

	for (int i = 0; i < balls.size(); i++) {
		int randIndex = rand() % positions.size();
		balls.at(i).setPos(positions.at(randIndex));
		positions.erase(positions.begin() + randIndex);
	}

	//for (int i = 0; i < positions.size(); i++) {																		// delete
	//	std::cout << "position " << i << "     x: " << positions.at(i).x << "  y: " << positions.at(i).y << std::endl;	//
	//}																													//

	//for (int i = 0; i < balls->size(); i++) {																					// delete
	//	std::cout << "ball " << i << " position     x: " << balls->at(i).pos.x << "  y: " << balls->at(i).pos.y << std::endl;	//
	//}																															//
}

void Game::setCuePos(Window* window) {
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
			if (glm::distance(pocketPositions[j], balls.at(i).getPos()) < 1.0f) {
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

					player1Panel.addTextLabel(players[0].ballType == Striped ? "Stripes" : "Solids", -5.0f, 3.0f, PoolColors::black(), Font::Monoton, FontSize::One);
					player2Panel.addTextLabel(players[1].ballType == Solid ? "Solids" : "Stripes", -5.0f, 3.0f, PoolColors::black(), Font::Monoton, FontSize::One);
				}

				balls.erase(balls.begin() + i);
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
		std::cout << "foul() 111111111111111111111111111111111111111111111111111111111111111111111111111111111111" << std::endl;	// delete
		return true;
	}

	if (players[currentPlayerIndex].ballType == Striped && !stripedPocketed) {
		std::cout << "foul() 222222222222222222222222222222222222222222222222222222222222222222222222222222222222" << std::endl;	// delete
		return true;
	}

	if (players[currentPlayerIndex].ballType == Solid && !solidPocketed) {
		std::cout << "foul() 333333333333333333333333333333333333333333333333333333333333333333333333333333333333" << std::endl;	// delete
		return true;
	}

	if (players[currentPlayerIndex].ballType == Unassigned && !solidPocketed && !stripedPocketed) {
		std::cout << "foul() 444444444444444444444444444444444444444444444444444444444444444444444444444444444444" << std::endl;	// delete
		return true;
	}

	return false;
}

bool Game::positionOutOfBounds(Window* window) {
	glm::vec2 mouseWorldPos = input->getMouseWorldPos();

	for (int i = 0; i < balls.size(); i++) {
		if (glm::distance(balls.at(i).getPos(), mouseWorldPos) < 1.0f) {
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

bool Game::detectBallCollision(glm::vec2 ball1Pos, glm::vec2 ball2Pos, glm::vec2* outCollisionNormal) {
	if (glm::length(ball1Pos - ball2Pos) <= 1.0f) {
		*outCollisionNormal = glm::normalize(ball2Pos - ball1Pos);

		return true;
	}

	return false;
}

bool Game::allBallsPocketed(BallType ballType) {
	for (int i = 0; i < balls.size(); i++) {
		if (balls.at(i).getBallType() == ballType) {
			return false;
		}
	}

	return true;
}

void Game::updatePlayerPanels() {

}

bool Game::getGameDone() {
	return gameDone;
}

int Game::getWinner() {
	return winner;
}