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
#include <PoolColors.h>
#include <Shader.h>
#include <Texture.h>
#include <Player.h>
#include <Side.h>
#include <Ball.h>
#include <Cue.h>

class Window {
public:
	Window();
	~Window();
	void drawFrame(Side sides[], glm::vec2 pocketPositions[], std::vector<Ball>* balls, Ball* cueBall, Cue* cue, Player currentPlayer);
	GLFWwindow* getglfwwindow();
	glm::vec2 getResolution();
	glm::vec2 getWorldScale();
	bool shouldClose();

private:
	void drawCircle(float radius, glm::vec2 pos, glm::vec4 color, BallType ballType);
	void drawRectangle(glm::vec2 pos, glm::vec2 scale, float rotation, glm::vec4 color);
	void drawRectangleTexture(glm::vec2 pos, glm::vec2 scale, float rotation, Texture* texture);
	void drawLineSegment(glm::vec2 pointA, glm::vec2 pointB, glm::vec4 color);
	void GLClearErrors();
	bool GLLogErrors();

private:
	GLFWmonitor* glfwmonitor;
	GLFWwindow* glfwwindow;
	const char* windowTitle;
	glm::vec2 resolution;
	glm::vec2 worldScale;
	unsigned int rectvao;
	unsigned int rectvbo;
	unsigned int rectTexturevao;
	unsigned int rectTexturevbo;
	unsigned int rectibo;
	unsigned int linevao;
	unsigned int linevbo;
	Shader* circleShader;
	Shader* rectangleShader;
	Shader* lineShader;
	Shader* rectangleTextureShader;
	Texture* texture;
	Texture* player1Texture;
	Texture* player2Texture;
};