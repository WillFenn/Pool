#include <Window.h>

Window::Window() {
	std::cout << "window created" << std::endl;	// delete

	if (!glfwInit()) {
		std::cout << "Failed to initialize GLFW" << std::endl << std::endl;
	}
	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwmonitor = glfwGetPrimaryMonitor();

	const GLFWvidmode* videoMode = glfwGetVideoMode(glfwmonitor);
	resolution.x = videoMode->width;
	resolution.y = videoMode->height;

	std::cout << "width: " << resolution.x << std::endl << "height: " << resolution.y << std::endl;	// delete

	worldScale = { 96.0f, 54.0f };

	windowTitle = "Pool";

	glfwwindow = glfwCreateWindow(resolution.x, resolution.y, windowTitle, glfwmonitor, NULL);

	glfwMakeContextCurrent(glfwwindow);

	if (glewInit() != GLEW_OK) {
		std::cout << "Failed to initialize GLEW" << std::endl << std::endl;
	}

	GLCALL(std::cout << glGetString(GL_VERSION) << std::endl << std::endl);

	GLCALL(glCreateVertexArrays(1, &rectvao));
	GLCALL(glBindVertexArray(rectvao));

	GLCALL(glCreateBuffers(1, &rectvbo));
	GLCALL(glBindBuffer(GL_ARRAY_BUFFER, rectvbo));

	glm::vec2 rectVertices[4] = { { -0.5f, 0.5f }, { 0.5f, 0.5f }, { 0.5f, -0.5f }, { -0.5f, -0.5f } };
	GLCALL(glBufferData(GL_ARRAY_BUFFER, sizeof(rectVertices), rectVertices, GL_STREAM_DRAW));

	GLCALL(glVertexAttribPointer(0, 2, GL_FLOAT, false, sizeof(glm::vec2), 0));
	GLCALL(glEnableVertexAttribArray(0));

	GLCALL(glCreateVertexArrays(1, &rectTexturevao));
	GLCALL(glBindVertexArray(rectTexturevao));

	GLCALL(glCreateBuffers(1, &rectTexturevbo));
	GLCALL(glBindBuffer(GL_ARRAY_BUFFER, rectTexturevbo));

	glm::vec2 rectTextureVertices[8] = { { -0.5f, 0.5f }, { 0.0f, 1.0f },
										{ 0.5f, 0.5f }, { 1.0f, 1.0f },
										{ 0.5f, -0.5f }, { 1.0f, 0.0f },
										{ -0.5f, -0.5f }, { 0.0f, 0.0f } };
	
	GLCALL(glBufferData(GL_ARRAY_BUFFER, sizeof(rectTextureVertices), rectTextureVertices, GL_STREAM_DRAW));

	GLCALL(glVertexAttribPointer(0, 2, GL_FLOAT, false, 2 * sizeof(glm::vec2), 0));
	GLCALL(glEnableVertexAttribArray(0));

	GLCALL(glVertexAttribPointer(1, 2, GL_FLOAT, false, 2 * sizeof(glm::vec2), (const void*)sizeof(glm::vec2)));
	GLCALL(glEnableVertexAttribArray(1));

	GLCALL(glCreateBuffers(1, &rectibo));
	GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rectibo));

	unsigned int rectIndices[6] = { 0, 1, 3, 1, 2, 3 };
	GLCALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(rectIndices), rectIndices, GL_STREAM_DRAW));

	GLCALL(glCreateVertexArrays(1, &linevao));
	GLCALL(glBindVertexArray(linevao));

	GLCALL(glCreateBuffers(1, &linevbo));
	GLCALL(glBindBuffer(GL_ARRAY_BUFFER, linevbo));

	GLCALL(glVertexAttribPointer(0, 2, GL_FLOAT, false, sizeof(glm::vec2), 0));
	GLCALL(glEnableVertexAttribArray(0));

	circleShader = new Shader("res/shaders/CircleRectangleLineVertex.glsl", "res/shaders/CircleFragment.glsl");
	rectangleShader = new Shader("res/shaders/CircleRectangleLineVertex.glsl", "res/shaders/LineRectangleFragment.glsl");
	rectangleTextureShader = new Shader("res/shaders/RectangleTextureVertex.glsl", "res/shaders/RectangleTextureFragment.glsl");
	lineShader = new Shader("res/shaders/CircleRectangleLineVertex.glsl", "res/shaders/LineRectangleFragment.glsl");

	texture = new Texture("res/textures/container.jpg");
	player1Texture = new Texture("res/textures/player1.png");
	player2Texture = new Texture("res/textures/player2.png");
	stripesTexture = new Texture("res/textures/stripes.png");
	solidsTexture = new Texture("res/textures/solids.png");

	glm::vec4 backgroundColor = PoolColors::gray();
	GLCALL(glClearColor(backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a));
}

Window::~Window() {
	delete circleShader;
	delete rectangleShader;
	delete rectangleTextureShader;
	delete lineShader;

	delete texture;
	delete player1Texture;
	delete player2Texture;
	delete stripesTexture;
	delete solidsTexture;

	glfwSetWindowShouldClose(glfwwindow, true);

	glfwTerminate();
}

void Window::drawFrame(Side sides[], glm::vec2 pocketPositions[], std::vector<Ball>* balls, Ball* cueBall, Cue* cue, glm::vec2* trajectoryA, glm::vec2* trajectoryB, Player* currentPlayer, bool gameDone, int winner) {
	//std::cout << "balls->size(): " << balls->size() << std::endl;	//delete
	
	GLCALL(glClear(GL_COLOR_BUFFER_BIT));

	// draw table
	drawRectangle(glm::vec2(0.0f, 0.0f), glm::vec2(48.0f, 27.0f), 0.0f, PoolColors::lightGreen());
	drawRectangle(glm::vec2(0.0f, 14.5f), glm::vec2(52.0f, 2.0f), 0.0f, PoolColors::darkBrown());
	drawRectangle(glm::vec2(25.0f, 0.0f), glm::vec2(2.0f, 27.0f), 0.0f, PoolColors::darkBrown());
	drawRectangle(glm::vec2(0.0f, -14.5f), glm::vec2(52.0f, 2.0f), 0.0f, PoolColors::darkBrown());
	drawRectangle(glm::vec2(-25.0f, 0.0f), glm::vec2(2.0f, 27.0f), 0.0f, PoolColors::darkBrown());
	std::cout << "table drawn" << std::endl;	// delete

	//drawRectangleTexture(glm::vec2(0.0f, 0.0f), glm::vec2(10.0f, 10.0f), 0.0f, texture);	// delete

	glm::vec4 black = { 0.0f / 255.0f, 0.0f / 255.0f, 0.0f / 255.0f, 1.0f };
	for (int i = 0; i < 18; i++) {
		drawLineSegment(sides[i].pointA, sides[i].pointB, black);
	}
	std::cout << "sides drawn" << std::endl;	// delete

	for (int i = 0; i < 6; i++) {
		drawCircle(1.0f, pocketPositions[i], black, Solid);
	}
	std::cout << "pockets drawn" << std::endl;	// delete

	// draw balls
	for (int i = 0; i < balls->size(); i++) {
		drawCircle(0.5f, balls->at(i).pos, balls->at(i).color, balls->at(i).ballType);
	}
	std::cout << "balls drawn" << std::endl;	// delete

	if (cueBall != nullptr) {
		drawCircle(0.5f, cueBall->pos, cueBall->color, cueBall->ballType);
		std::cout << "cue ball drawn" << std::endl;	// delete
	}

	// draw cue
	if (cue != nullptr) {
		drawRectangle(cue->pos, cue->scale, cue->rotation, cue->color);
		std::cout << "cue drawn" << std::endl;	// delete
		std::cout << "cue position     x: " << cue->pos.x << "   y: " << cue->pos.y << std::endl;	// delete
	}

	// draw shot trajectory
	if (trajectoryA != nullptr) {
		drawLineSegment(*trajectoryA, *trajectoryB, PoolColors::black());
	}

	if (!gameDone) {
		drawRectangleTexture(glm::vec2(-45.5f, 26.0f), glm::vec2(5.0f, 2.0f), 0.0f, currentPlayer->playerNumber == 1 ? player1Texture : player2Texture);

		if (currentPlayer->ballType != Unassigned) {
			drawRectangleTexture(glm::vec2(-45.5f, 24.0f), glm::vec2(5.0f, 2.0f), 0.0f, currentPlayer->ballType == Striped ? stripesTexture : solidsTexture);
		}
	}
	else {
		drawRectangleTexture(glm::vec2(0.0f, 0.0f), glm::vec2(48.0f, 27.0f), 0.0f, winner == 1 ? player1Texture : player2Texture);
	}

	glfwSwapBuffers(glfwwindow);
	
	glfwPollEvents();
}

void Window::drawCircle(float radius, glm::vec2 pos, glm::vec4 color, BallType ballType) {
	GLCALL(glBindVertexArray(rectvao));
	GLCALL(glBindBuffer(GL_ARRAY_BUFFER, rectvbo));
	GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rectibo));
	circleShader->bind();

	glm::mat4 projection = glm::ortho(-(worldScale.x / 2.0f), worldScale.x / 2.0f, -(worldScale.y / 2.0f), worldScale.y / 2.0f, -1.0f, 1.0f);
	glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
	glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(pos, 0.0f));
	model = glm::scale(model, glm::vec3(radius * 2, radius * 2, 1.0f));

	glm::mat4 mvp = projection * view * model;
	circleShader->setUniformMat4(mvp, "uMVP");
	circleShader->setUniformIVec2(resolution, "uResolution");
	circleShader->setUniformFloat(radius, "uRadius");
	circleShader->setUniformVec2(pos, "uPosition");
	circleShader->setUniformVec2(worldScale, "uWorldScale");
	circleShader->setUniformVec4(color, "uColor");
	circleShader->setUniformInt(ballType == Striped ? true : false, "uStriped");

	GLCALL(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0));
}

void Window::drawRectangle(glm::vec2 pos, glm::vec2 scale, float rotation, glm::vec4 color) {
	GLCALL(glBindVertexArray(rectvao));
	GLCALL(glBindBuffer(GL_ARRAY_BUFFER, rectvbo));
	GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rectibo));
	rectangleShader->bind();

	glm::mat4 projection = glm::ortho(-(worldScale.x / 2.0f), worldScale.x / 2.0f, -(worldScale.y / 2.0f), worldScale.y / 2.0f, -1.0f, 1.0f);
	glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
	glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(pos, 0.0f));
	model = glm::rotate(model, rotation, glm::vec3(0, 0, 1));
	model = glm::scale(model, glm::vec3(scale.x, scale.y, 1.0f));

	glm::mat4 mvp = projection * view * model;
	rectangleShader->setUniformMat4(mvp, "uMVP");
	rectangleShader->setUniformVec4(color, "uColor");

	GLCALL(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0));
}

void Window::drawRectangleTexture(glm::vec2 pos, glm::vec2 scale, float rotation, Texture* texture) {
	GLCALL(glBindVertexArray(rectTexturevao));
	GLCALL(glBindBuffer(GL_ARRAY_BUFFER, rectTexturevbo));
	GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rectibo));
	rectangleTextureShader->bind();
	texture->bind();
	
	glm::mat4 projection = glm::ortho(-(worldScale.x / 2.0f), worldScale.x / 2.0f, -(worldScale.y / 2.0f), worldScale.y / 2.0f, -1.0f, 1.0f);
	glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
	glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(pos, 0.0f));
	model = glm::rotate(model, rotation, glm::vec3(0, 0, 1));
	model = glm::scale(model, glm::vec3(scale.x, scale.y, 1.0f));

	glm::mat4 mvp = projection * view * model;
	rectangleTextureShader->setUniformMat4(mvp, "uMVP");
	rectangleTextureShader->setUniformInt(texture->getSlot(), "uTexture");

	GLCALL(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0));
}

void Window::drawLineSegment(glm::vec2 pointA, glm::vec2 pointB, glm::vec4 color) {
	glm::vec2 lineVertices[2] = { pointA, pointB };

	GLCALL(glBindVertexArray(linevao));
	GLCALL(glBindBuffer(GL_ARRAY_BUFFER, linevbo));
	GLCALL(glBufferData(GL_ARRAY_BUFFER, sizeof(lineVertices), lineVertices, GL_STREAM_DRAW));
	lineShader->bind();

	glm::mat4 projection = glm::ortho(-(worldScale.x / 2.0f), worldScale.x / 2.0f, -(worldScale.y / 2.0f), worldScale.y / 2.0f, -1.0f, 1.0f);
	glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));

	glm::mat4 mvp = projection * view;
	rectangleShader->setUniformMat4(mvp, "uMVP");
	lineShader->setUniformVec4(color, "uColor");

	GLCALL(glDrawArrays(GL_LINES, 0, 2));
}

bool Window::shouldClose() {
	return glfwWindowShouldClose(glfwwindow);
}

GLFWwindow* Window::getglfwwindow() {
	return glfwwindow;
}

glm::vec2 Window::getResolution() {
	return resolution;
}

glm::vec2 Window::getWorldScale() {
	return worldScale;
}

void Window::GLClearErrors() {
	while (glGetError() != GL_NO_ERROR);
}

bool Window::GLLogErrors() {
	bool noErrors = true;

	while (GLenum error = glGetError()) {
		noErrors = false;

		switch (error) {
		case GL_INVALID_ENUM:
			std::cout << "OpenGL Error: GL_INVALID_ENUM" << std::endl << std::endl;
			break;
		case GL_INVALID_VALUE:
			std::cout << "OpenGL Error: GL_INVALID_VALUE" << std::endl << std::endl;
			break;
		case GL_INVALID_OPERATION:
			std::cout << "OpenGL Error: GL_INVALID_OPERATION" << std::endl << std::endl;
			break;
		case GL_STACK_OVERFLOW:
			std::cout << "OpenGL Error: GL_STACK_OVERFLOW" << std::endl << std::endl;
			break;
		case GL_STACK_UNDERFLOW:
			std::cout << "OpenGL Error: GL_STACK_UNDERFLOW" << std::endl << std::endl;
			break;
		case GL_OUT_OF_MEMORY:
			std::cout << "OpenGL Error: GL_OUT_OF_MEMORY" << std::endl << std::endl;
			break;
		case GL_INVALID_FRAMEBUFFER_OPERATION:
			std::cout << "OpenGL Error: GL_INVALID_FRAMEBUFFER_OPERATION" << std::endl << std::endl;
			break;
		case GL_CONTEXT_LOST:
			std::cout << "OpenGL Error: GL_CONTEXT_LOST" << std::endl << std::endl;
			break;
		case GL_TABLE_TOO_LARGE:
			std::cout << "OpenGL Error: GL_TABLE_TOO_LARGE" << std::endl << std::endl;
			break;
		}
	}

	return noErrors;
}