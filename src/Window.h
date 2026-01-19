#pragma once

#define GLEW_STATIC
#define ASSERT(x) if (!(x)) __debugbreak()
#define GLCALL(x) GLClearErrors();\
	x;\
	ASSERT(GLLogErrors());

#include <iostream>
#include <vector>
#include <glew.h>
#include <glfw3.h>
#include <vec2.hpp>
#include <vec3.hpp>
#include <mat4x4.hpp>
#include <ext/matrix_clip_space.hpp>
#include <ext/matrix_transform.hpp>
#include <Shader.h>
#include <Ball.h>
#include <Cue.h>

class Window {
public:
	Window(glm::vec2 worldScale, glm::vec4 backgroundColor);
	~Window();
	void drawFrame(glm::vec2 pocketPositions[], std::vector<Ball>* balls, Ball cueBall, Cue cue);
	GLFWwindow* getglfwwindow();
	glm::vec2 getResolution();
	glm::vec2 getWorldScale();
	bool shouldClose();
private:
	void drawCircle(float radius, glm::vec2 pos, glm::vec4 color, bool striped);
	void drawRectangle(glm::vec2 pos, glm::vec2 scale, float rotation, glm::vec4 color);
	void GLClearErrors();
	bool GLLogErrors();
	GLFWmonitor* glfwmonitor;
	GLFWwindow* glfwwindow;
	const char* windowTitle;
	glm::vec2 resolution;
	glm::vec2 worldScale;
	unsigned int rectvao;
	unsigned int rectvbo;
	unsigned int rectibo;
	Shader* circleShader;
	Shader* rectangleShader;
};