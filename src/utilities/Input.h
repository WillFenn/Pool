#pragma once

#include <glfw3.h>
#include <vec2.hpp>

class Input {
public:
	Input(GLFWwindow* glfwwindow, glm::vec2 resolution, glm::vec2 worldScale);
	~Input();
	double getTime() const;
	double getDeltaTime();
	glm::vec2 getMousePos() const;
	glm::vec2 getMouseWorldPos() const;
	bool leftMousePressed() const;
	bool leftMouseReleased() const;
	bool escKeyPressed() const;

private:
	GLFWwindow* glfwwindow;
	glm::vec2 resolution;
	glm::vec2 worldScale;
	bool deltaTimeCalled;
	double prevTime;
};