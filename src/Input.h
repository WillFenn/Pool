#pragma once

#include <glfw3.h>
#include <vec2.hpp>

class Input {
public:
	Input(GLFWwindow* glfwwindow);
	~Input();
	glm::vec2 getMousePos();
	bool escKeyPressed();
private:
	GLFWwindow* glfwwindow;
};