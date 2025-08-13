#include <Window.h>

Window::Window(glm::vec4 backgroundColor) {
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

	cameraScale = { 32.0f, 18.0f };

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

	GLCALL(glCreateBuffers(1, &rectibo));
	GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rectibo));

	unsigned int rectIndices[6] = { 0, 1, 3, 1, 2, 3 };
	GLCALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(rectIndices), rectIndices, GL_STREAM_DRAW));

	circleShader = new Shader("res/Vertex.glsl", "res/CircleFragment.glsl");
	rectangleShader = new Shader("res/Vertex.glsl", "res/RectangleFragment.glsl");

	GLCALL(glClearColor(backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a));
}

Window::~Window() {
	delete circleShader;
	delete rectangleShader;

	glfwSetWindowShouldClose(glfwwindow, true);

	glfwTerminate();
}

void Window::drawFrame(std::vector<Ball>* balls, Ball cueBall, Cue cue) {
	std::cout << "balls->size(): " << balls->size() << std::endl;	//delete
	
	GLCALL(glClear(GL_COLOR_BUFFER_BIT));

	for (int i = 0; i < balls->size(); i++) {
		drawCircle(balls->at(i).pos, balls->at(i).color, balls->at(i).striped);
	}

	drawCircle(cueBall.pos, cueBall.color, cueBall.striped);

	drawRectangle(cue.pos, cue.scale, cue.rotation, cue.color);

	glfwSwapBuffers(glfwwindow);
	
	glfwPollEvents();
}

void Window::drawCircle(glm::vec2 pos, glm::vec4 color, bool striped) {
	std::cout << "drawing circle" << std::endl;	//delete

	GLCALL(glBindBuffer(GL_ARRAY_BUFFER, rectvbo));
	GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rectibo));
	circleShader->bind();

	glm::mat4 projection = glm::ortho(-(cameraScale.x / 2.0f), cameraScale.x / 2.0f, -(cameraScale.y / 2.0f), cameraScale.y / 2.0f, -1.0f, 1.0f);
	glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
	glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(pos, 0.0f));

	glm::mat4 mvp = projection * view * model;
	circleShader->setUniformMat4(mvp, "uMVP");
	circleShader->setUniformIVec2(resolution, "uResolution");
	circleShader->setUniformVec2(pos, "uPosition");
	circleShader->setUniformVec2(cameraScale, "uCameraScale");
	circleShader->setUniformVec4(color, "uColor");
	circleShader->setUniformInt(striped, "uStriped");

	GLCALL(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0));
}

void Window::drawRectangle(glm::vec2 pos, glm::vec2 scale, float rotation, glm::vec4 color) {
	std::cout << "drawing square" << std::endl;	//delete

	GLCALL(glBindBuffer(GL_ARRAY_BUFFER, rectvbo));
	GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rectibo));
	rectangleShader->bind();

	glm::mat4 projection = glm::ortho(-(cameraScale.x / 2.0f), cameraScale.x / 2.0f, -(cameraScale.y / 2.0f), cameraScale.y / 2.0f, -1.0f, 1.0f);
	glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
	glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(pos, 0.0f));
	model = glm::rotate(model, rotation, glm::vec3(0, 0, 1));
	model = glm::scale(model, glm::vec3(scale.x, scale.y, 1.0f));

	glm::mat4 mvp = projection * view * model;
	rectangleShader->setUniformMat4(mvp, "uMVP");
	rectangleShader->setUniformVec4(color, "uColor");

	GLCALL(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0));
}

bool Window::shouldClose() {
	return glfwWindowShouldClose(glfwwindow);
}

GLFWwindow* Window::getglfwwindow() {
	return glfwwindow;
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