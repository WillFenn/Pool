#include <Game.h>

Game::Game() {
	sides[0] = { { -24.0f, 13.5f - glm::sqrt(2) }, { -24.0f - glm::sqrt(2), 13.5f }, { 1 / glm::sqrt(2), 1 / glm::sqrt(2)} };
	sides[1] = { { -24.0f, 13.5f + glm::sqrt(2) }, { -24.0f + glm::sqrt(2), 13.5f }, { -(1 / glm::sqrt(2)), -(1 / glm::sqrt(2))} };
	sides[2] = { { -24.0f + glm::sqrt(2), 13.5f }, { -1.2f, 13.5f }, { 0.0f, -1.0f } };
	sides[3] = { { -1.2f, 13.5f }, { -1.0f, 14.5f }, { PoolMath::normal(glm::vec2(-1.0f, 14.5f) - glm::vec2(-1.2f, 13.5f)) } };
	sides[4] = { { 1.0f, 14.5f }, { 1.2f, 13.5f }, { PoolMath::normal(glm::vec2(1.2f, 13.5f) - glm::vec2(1.0f, 14.5f)) } };
	sides[5] = { { 1.2f, 13.5f }, { 24.0f - glm::sqrt(2), 13.5f }, { 0.0f, -1.0f } };
	sides[6] = { { 24.0f - glm::sqrt(2), 13.5f }, { 24.0f, 13.5f + glm::sqrt(2) }, { 1 / glm::sqrt(2), -(1 / glm::sqrt(2)) } };
	sides[7] = { { 24.0f + glm::sqrt(2), 13.5f }, { 24.0f, 13.5f - glm::sqrt(2) }, { -(1 / glm::sqrt(2)), 1 / glm::sqrt(2) } };
	sides[8] = { { 24.0f, 13.5f - glm::sqrt(2) }, { 24.0f, -13.5f + glm::sqrt(2) }, { -1.0f, 0.0f } };
	sides[9] = { { 24.0f, -13.5f + glm::sqrt(2) }, { 24.0f + glm::sqrt(2), -13.5f }, { -(1 / glm::sqrt(2)), -(1 / glm::sqrt(2)) } };
	sides[10] = { { 24.0f, -13.5f - glm::sqrt(2) }, { 24.0f - glm::sqrt(2), -13.5f }, { 1 / glm::sqrt(2), 1 / glm::sqrt(2) } };
	sides[11] = { { 24.0f - glm::sqrt(2), -13.5f }, { 1.2f, -13.5f }, { 0.0f, 1.0f } };
	sides[12] = { { 1.2f, -13.5f }, { 1.0f, -14.5 }, { PoolMath::normal(glm::vec2(1.0f, -14.5) - glm::vec2(1.2f, -13.5f)) } };
	sides[13] = { { -1.0f, -14.5f }, { -1.2, -13.5f }, { PoolMath::normal(glm::vec2(-1.2, -13.5f) - glm::vec2(-1.0f, -14.5f)) } };
	sides[14] = { { -1.2, -13.5f }, { -24.0f + glm::sqrt(2), -13.5 }, { 0.0f, 1.0f } };
	sides[15] = { { -24.0f + glm::sqrt(2), -13.5 }, { -24.0f, -13.5f - glm::sqrt(2) }, { PoolMath::normal(glm::vec2(-24.0f, -13.5f - glm::sqrt(2)) - glm::vec2(-24.0f + glm::sqrt(2), -13.5f)) } };
	sides[16] = { { -24.0f - glm::sqrt(2), -13.5f }, { -24.0f, -13.5f + glm::sqrt(2) }, { PoolMath::normal(glm::vec2(-24.0f, -13.5f + glm::sqrt(2)) - glm::vec2(-24.0f - glm::sqrt(2), -13.5f)) } };
	sides[17] = { { -24.0f, -13.5f + glm::sqrt(2) }, { -24.0f, 13.5f - glm::sqrt(2) }, { 1.0f, 0.0f } };

	pocketPositions[0] = { -24.0f - (1 / glm::sqrt(2)), 13.5f + (1 / glm::sqrt(2)) };
	pocketPositions[1] = { 0.0f, 13.5f + 1.0f };
	pocketPositions[2] = { 24.0f + (1 / glm::sqrt(2)), 13.5f + (1 / glm::sqrt(2)) };
	pocketPositions[3] = { 24.0f + (1 / glm::sqrt(2)), -13.5f - (1 / glm::sqrt(2)) };
	pocketPositions[4] = { 0.0f, -13.5f - 1.0f };
	pocketPositions[5] = { -24.0f - (1 / glm::sqrt(2)), -13.5f - (1 / glm::sqrt(2)) };
	
	cueBall = { 0, { 5.0f, 0.0f }, { 0.0f, 0.0f }, PoolColors::white(), Solid };

	leftClickStartPos = { std::numeric_limits<float>::max(), std::numeric_limits<float>::max() };
	
	cueStartPosition = cueBall.pos + glm::vec2(-1.0f, 0.0f) * ((10.0f / 2.0f) + 0.5f);
	
	cue = { cueStartPosition, { 10.0f, 0.2f }, 0.0f, 0.0f, new Texture("res/textures/cue.png"), false};
	
	balls.push_back({ 1, {0.0f, 0.0f}, {0.0f, 0.0f}, PoolColors::black(), Solid });
	balls.push_back({ 2, { 0.0f, 0.0f }, { 0.0f, 0.0f }, PoolColors::yellow(), Solid });
	balls.push_back({ 3, { 0.0f, 0.0f }, { 0.0f, 0.0f }, PoolColors::yellow(), Striped });
	balls.push_back({ 4, { 0.0f, 0.0f }, { 0.0f, 0.0f }, PoolColors::red(), Solid });
	balls.push_back({ 5, { 0.0f, 0.0f }, { 0.0f, 0.0f }, PoolColors::red(), Striped });
	balls.push_back({ 6, { 0.0f, 0.0f }, { 0.0f, 0.0f }, PoolColors::darkGreen(), Solid });
	balls.push_back({ 7, { 0.0f, 0.0f }, { 0.0f, 0.0f }, PoolColors::darkGreen(), Striped });
	balls.push_back({ 8, { 0.0f, 0.0f }, { 0.0f, 0.0f }, PoolColors::blue(), Solid });
	balls.push_back({ 9, { 0.0f, 0.0f }, { 0.0f, 0.0f }, PoolColors::blue(), Striped });
	balls.push_back({ 10, { 0.0f, 0.0f }, { 0.0f, 0.0f }, PoolColors::orange(), Solid });
	balls.push_back({ 11, { 0.0f, 0.0f }, { 0.0f, 0.0f }, PoolColors::orange(), Striped });
	balls.push_back({ 12, { 0.0f, 0.0f }, { 0.0f, 0.0f }, PoolColors::purple(), Solid });
	balls.push_back({ 13, { 0.0f, 0.0f }, { 0.0f, 0.0f }, PoolColors::purple(), Striped });
	balls.push_back({ 14, { 0.0f, 0.0f }, { 0.0f, 0.0f }, PoolColors::darkBrown(), Solid });
	balls.push_back({ 15, { 0.0f, 0.0f }, { 0.0f, 0.0f }, PoolColors::darkBrown(), Striped });
	
	setPositions();

	players[0] = {1, Unassigned};
	players[1] = {2, Unassigned};

	currentPlayerIndex = 0;
}

Game::~Game() {
	delete cue.texture;
}

void Game::update(Window* window, Input* input, float deltaTime) {
	std::cout << "player 1 ball type: ";		// delete
	if (players[0].ballType == Unassigned) {	//
		std::cout << "Unassigned" << std::endl;	//
	}											//
	else if (players[0].ballType == Striped) {	//
		std::cout << "Striped" << std::endl;	//
	}											//
	else if (players[0].ballType == Solid) {	//
		std::cout << "Solid" << std::endl;		//
	}											//
												//
	std::cout << "player 2 ball type: ";		//
	if (players[1].ballType == Unassigned) {	//
		std::cout << "Unassigned" << std::endl;	//
	}											//
	else if (players[1].ballType == Striped) {	//
		std::cout << "Striped" << std::endl;	//
	}											//
	else if (players[1].ballType == Solid) {	//
		std::cout << "Solid" << std::endl;		//
	}											//
	
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
		setCuePos(window, input);
	}

	checkPocketedBalls();

	if (cueBallShouldBePlaced && !ballsMovingThisFrame && !positionOutOfBounds(window, input)) {
		cueBall.pos = getMouseWorldPos(window, input);
		
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

	ballsMovedLastFrame = ballsMovingThisFrame;

	std::cout << "cue speed: " << cue.speed << std::endl;	// delete
}

bool Game::ballsAreMoving() {
	if (glm::length(cueBall.velocity) != 0.0f) {
		return true;
	}

	for (int i = 0; i < balls.size(); i++) {
		if (glm::length(balls.at(i).velocity) != 0.0f) {
			return true;
		}
	}

	return false;
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
	glm::vec2 pathPos = cueBall.pos;
	glm::vec2 pathIncrement = 0.01f * glm::normalize(cueBall.pos - cue.pos);
	glm::vec2 collisionNormal;

	while (pathPos.x > -23.5f && pathPos.x < 23.5f && pathPos.y > -13.0f && pathPos.y < 13.0f) {
		for (int i = 0; i < balls.size(); i++) {
			if (detectBallCollision(&pathPos, &balls.at(i).pos, &collisionNormal)) {
				std::cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << std::endl;	// delete
				
				*pointA = balls.at(i).pos;
				*pointB = balls.at(i).pos + 3.0f * collisionNormal;
				
				return true;
			}
		}

		pathPos += pathIncrement;
	}

	return false;
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
		balls.at(i).pos = positions.at(randIndex);
		positions.erase(positions.begin() + randIndex);
	}

	//for (int i = 0; i < positions.size(); i++) {																		// delete
	//	std::cout << "position " << i << "     x: " << positions.at(i).x << "  y: " << positions.at(i).y << std::endl;	//
	//}																													//

	//for (int i = 0; i < balls->size(); i++) {																					// delete
	//	std::cout << "ball " << i << " position     x: " << balls->at(i).pos.x << "  y: " << balls->at(i).pos.y << std::endl;	//
	//}																															//
}

void Game::setCuePos(Window* window, Input* input) {
	std::cout << "--------------------setCuePos()--------------------" << std::endl;	// delete

	glm::vec2 mouseWorldPos = getMouseWorldPos(window, input);

	if (input->leftMousePressed()) {
		std::cout << "left mouse button is pressed" << std::endl;	// delete

		if (leftClickStartPos.x == std::numeric_limits<float>::max()) {
			leftClickStartPos = mouseWorldPos;
		}

		glm::vec2 cueDirection = glm::normalize(cue.pos - cueBall.pos);
		glm::vec2 leftClickStartToMouse = mouseWorldPos - leftClickStartPos;
		cue.pos = cueBall.pos + cueDirection * glm::clamp((((cue.scale.x / 2) + 0.5f) + PoolMath::projection(leftClickStartToMouse, cueDirection)), ((cue.scale.x / 2) + 0.5f), maxCueDistance);
		cue.wasPulledBack = true;
	}
	else {
		if (cue.wasPulledBack) {
			std::cout << "left mouse button was let go" << std::endl;	// delete

			cue.speed = 3 * (glm::distance(cueBall.pos, cue.pos) - ((cue.scale.x / 2) + 0.5f));
			cue.wasPulledBack = false;
			leftClickStartPos = { std::numeric_limits<float>::max(), std::numeric_limits<float>::max() };
		}
		else if (cue.speed == 0.0f) {
			std::cout << "11111111111111111111111111111111111111111111" << std::endl;	// delete
			glm::vec2 mouseDirection;
			if (!PoolMath::approximatelyEqual(mouseWorldPos, cueBall.pos, 0.0001f)) {
				mouseDirection = glm::normalize(mouseWorldPos - cueBall.pos);
			}
			else {
				mouseDirection = glm::vec2(-1.0f, 0.0f);
			}
			
			cue.pos = cueBall.pos - mouseDirection * ((cue.scale.x / 2.0f) + 0.5f);
			
			cue.rotation = atan(mouseDirection.y / mouseDirection.x);
			if (mouseDirection.x < 0) {
				cue.rotation += glm::pi<float>();
			}
		}
	}

	//std::cout << "mouse position: " << "(" << mouseWorldPos.x << ", " << mouseWorldPos.y << ")" << std::endl;	// delete
	std::cout << std::endl;	// delete
}

glm::vec2 Game::getMouseWorldPos(Window* window, Input* input) {
	glm::vec2 mouseWorldPos = ((input->getMousePos() - window->getResolution() / 2.0f) / (window->getResolution() / 2.0f)) * (window->getWorldScale() / 2.0f);
	mouseWorldPos.y *= -1;
	
	return mouseWorldPos;
}

void Game::checkPocketedBalls() {
	// check object balls
	for (int j = 0; j < 6; j++) {
		for (int i = 0; i < balls.size(); i++) {
			if (glm::distance(pocketPositions[j], balls.at(i).pos) < 1.0f) {
				// check the ball type of the pocketed ball
				if (balls.at(i).ballType == Striped) {
					stripedPocketed = true;
				}
				else {
					solidPocketed = true;
				}

				// check if pocketed ball is eight ball
				if (i == 0) {
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
				}

				balls.erase(balls.begin() + i);
			}
		}

		// check cue ball
		if (glm::distance(pocketPositions[j], cueBall.pos) < 1.0f) {
			cueBall.velocity = glm::vec2(0.0f, 0.0f);
			cueBallPocketed = true;
			cueBallShouldBePlaced = true;
		}
	}
}

bool Game::foul() {
	if (cueBallPocketed) {
		std::cout << "====================================================================================================================================================================================================================================" << std::endl;	// delete
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

bool Game::positionOutOfBounds(Window* window, Input* input) {
	glm::vec2 mouseWorldPos = getMouseWorldPos(window, input);

	for (int i = 0; i < balls.size(); i++) {
		if (glm::distance(balls.at(i).pos, mouseWorldPos) < 1.0f) {
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

bool Game::detectBallCollision(glm::vec2* ball1Pos, glm::vec2* ball2Pos, glm::vec2* outCollisionNormal) {
	if (glm::length(*ball1Pos - *ball2Pos) <= 1.0f) {
		*outCollisionNormal = glm::normalize(*ball2Pos - *ball1Pos);

		return true;
	}

	return false;
}

bool Game:: allBallsPocketed(BallType ballType) {
	for (int i = 0; i < balls.size(); i++) {
		if (balls.at(i).ballType == ballType) {
			return false;
		}
	}

	return true;
}

bool Game::getGameDone() {
	return gameDone;
}

int Game::getWinner() {
	return winner;
}