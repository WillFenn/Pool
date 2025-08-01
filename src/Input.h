#pragma once

#include <glfw3.h>

class Input {
public:
	Input(GLFWwindow* glfwwindow);
	~Input();
	bool escKeyPressed();
private:
	GLFWwindow* glfwwindow;
};