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
	sides[15] = { { -24.0f + glm::sqrt(2), -13.5 }, { -24.0f, -13.5f - glm::sqrt(2) }, { PoolMath::normal(glm::vec2(-24.0f, -13.5f - glm::sqrt(2)) - glm::vec2(-24.0f + glm::sqrt(2), -13.5)) } };
	sides[16] = { { -24.0f - glm::sqrt(2), -13.5f }, { -24.0f, -13.5f + glm::sqrt(2) }, { PoolMath::normal(glm::vec2(-24.0f, -13.5f + glm::sqrt(2)) - glm::vec2(-24.0f - glm::sqrt(2), -13.5f)) } };
	sides[17] = { { -24.0f, -13.5f + glm::sqrt(2) }, { -24.0f, 13.5f - glm::sqrt(2) }, { 1.0f, 0.0f } };

	pocketPositions[0] = { -24.0f - (1 / glm::sqrt(2)), 13.5f + (1 / glm::sqrt(2)) };
	pocketPositions[1] = { 0.0f, 13.5f + 1.0f };
	pocketPositions[2] = { 24.0f + (1 / glm::sqrt(2)), 13.5f + (1 / glm::sqrt(2)) };
	pocketPositions[3] = { 24.0f + (1 / glm::sqrt(2)), -13.5f - (1 / glm::sqrt(2)) };
	pocketPositions[4] = { 0.0f, -13.5f - 1.0f };
	pocketPositions[5] = { -24.0f - (1 / glm::sqrt(2)), -13.5f - (1 / glm::sqrt(2)) };
	
	cueBall = { 0, { 5.0f, 0.0f }, { 0.0f, 0.0f }, PoolColors::white(), false};
	
	cueStartPosition = cueBall.pos + glm::vec2(-1.0f, 0.0f) * ((10.0f / 2.0f) + 0.5f);
	
	cue = { cueStartPosition, { 10.0f, 0.2f }, 0.0f, 0.0f, PoolColors::lightBrown(), false};
	
	balls.push_back({ 1, {0.0f, 0.0f}, {0.0f, 0.0f}, PoolColors::black(), false });
	balls.push_back({ 2, { 0.0f, 0.0f }, { 0.0f, 0.0f }, PoolColors::yellow(), false });
	balls.push_back({ 3, { 0.0f, 0.0f }, { 0.0f, 0.0f }, PoolColors::yellow(), true });
	balls.push_back({ 4, { 0.0f, 0.0f }, { 0.0f, 0.0f }, PoolColors::red(), false });
	balls.push_back({ 5, { 0.0f, 0.0f }, { 0.0f, 0.0f }, PoolColors::red(), true });
	balls.push_back({ 6, { 0.0f, 0.0f }, { 0.0f, 0.0f }, PoolColors::darkGreen(), false });
	balls.push_back({ 7, { 0.0f, 0.0f }, { 0.0f, 0.0f }, PoolColors::darkGreen(), true });
	balls.push_back({ 8, { 0.0f, 0.0f }, { 0.0f, 0.0f }, PoolColors::blue(), false });
	balls.push_back({ 9, { 0.0f, 0.0f }, { 0.0f, 0.0f }, PoolColors::blue(), true });
	balls.push_back({ 10, { 0.0f, 0.0f }, { 0.0f, 0.0f }, PoolColors::orange(), false });
	balls.push_back({ 11, { 0.0f, 0.0f }, { 0.0f, 0.0f }, PoolColors::orange(), true });
	balls.push_back({ 12, { 0.0f, 0.0f }, { 0.0f, 0.0f }, PoolColors::purple(), false });
	balls.push_back({ 13, { 0.0f, 0.0f }, { 0.0f, 0.0f }, PoolColors::purple(), true });
	balls.push_back({ 14, { 0.0f, 0.0f }, { 0.0f, 0.0f }, PoolColors::darkBrown(), false });
	balls.push_back({ 15, { 0.0f, 0.0f }, { 0.0f, 0.0f }, PoolColors::darkBrown(), true });
	
	setPositions();

	//currentPlayer = Player1;
}

Game::~Game() {

}

void Game::update(Window* window, Input* input, float deltaTime) {
	setCuePos(window, input);

	removeBallsInPockets();
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

//Player Game::getCurrentPlayer() {
//	return currentPlayer;
//}

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
	glm::vec2 mouseWorldPos = ((input->getMousePos() - window->getResolution() / 2.0f) / (window->getResolution() / 2.0f)) * (window->getWorldScale() / 2.0f);
	mouseWorldPos.y *= -1;

	if (input->leftMousePressed()) {
		//std::cout << "left mouse button is pressed" << std::endl;	// delete

		glm::vec2 cueDirection = glm::normalize(cue.pos - cueBall.pos);
		glm::vec2 cueBallToMouse = mouseWorldPos - cueBall.pos;
		cue.pos = cueBall.pos + cueDirection * PoolMath::max(PoolMath::projection(cueBallToMouse, cueDirection), (cue.scale.x / 2) + 0.5f);
		cue.wasPulledBack = true;
	}
	else {
		if (cue.wasPulledBack) {
			//std::cout << "left mouse button was let go" << std::endl;	// delete

			cue.speed = 3 * (glm::distance(cueBall.pos, cue.pos) - ((cue.scale.x / 2) + 0.5f));
			cue.wasPulledBack = false;
		}
		else {
			//std::cout << "11111111111111111111111111111111111111111111" << std::endl;	// delete
			glm::vec2 mouseDirection = glm::normalize(mouseWorldPos - cueBall.pos);
			cue.pos = cueBall.pos + mouseDirection * ((cue.scale.x / 2.0f) + 0.5f);
			cue.rotation = atan(mouseDirection.y / mouseDirection.x);
		}
	}

	//std::cout << "mouse position: " << "(" << mouseWorldPos.x << ", " << mouseWorldPos.y << ")" << std::endl;	// delete
}

void Game::removeBallsInPockets() {
	for (int i = 0; i < balls.size(); i++) {
		for (int j = 0; j < 6; j++) {
			if (glm::distance(pocketPositions[j], balls.at(i).pos) < 1.5f) {
				balls.erase(balls.begin() + i);
			}
		}
	}
}