#pragma once

#include <glfw3.h>
#include <vec2.hpp>

class Input {
public:
	Input(GLFWwindow* glfwwindow, glm::vec2 resolution, glm::vec2 worldScale);
	~Input();
	double getTime();
	double getDeltaTime();
	glm::vec2 getMousePos();
	glm::vec2 getMouseWorldPos();
	bool leftMousePressed();
	bool leftMouseReleased();
	bool escKeyPressed();

private:
	GLFWwindow* glfwwindow;
	glm::vec2 resolution;
	glm::vec2 worldScale;
	bool deltaTimeCalled;
	double prevTime;
};