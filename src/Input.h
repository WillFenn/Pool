#pragma once

#include <glfw3.h>
#include <vec2.hpp>

class Input {
public:
	Input(GLFWwindow* glfwwindow);
	~Input();
	double getTime();
	double getDeltaTime();
	glm::vec2 getMousePos();
	bool leftMousePressed();
	bool escKeyPressed();
private:
	GLFWwindow* glfwwindow;
	bool deltaTimeCalled;
	double prevTime;
};