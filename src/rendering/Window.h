#pragma once

#define GLEW_STATIC
#define ASSERT(x) if (!(x)) __debugbreak()
#define GLCALL(x) GLClearErrors();\
	x;\
	ASSERT(GLLogErrors());

#include <iostream>
#include <vector>
#include <map>
#include <ranges>
#include <string>
#include <glew.h>
#include <glfw3.h>
#include <ft2build.h>
#include FT_FREETYPE_H
#include <vec2.hpp>
#include <vec3.hpp>
#include <mat4x4.hpp>
#include <ext/matrix_clip_space.hpp>
#include <ext/matrix_transform.hpp>
#include <PoolColors.h>
#include <PoolMath.h>	// delete
#include <Character.h>
#include <GameObject.h>
#include <Line.h>
#include <Panel.h>
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
	void drawFrame(std::vector<GameObject>* objects, std::vector<Line>* lines, std::vector<Panel>* panels) const;
	GLFWwindow* getglfwwindow() const;
	glm::vec2 getResolution() const;
	glm::vec2 getWorldScale() const;
	bool shouldClose() const;

private:
	void drawCircle(float radius, glm::vec2 pos, glm::vec4 color, BallType ballType) const;
	void drawSphereTexture(float radius, glm::vec2 pos, glm::mat4 rotationMat, const Texture* texture) const;
	void drawRectangle(glm::vec2 pos, glm::vec2 scale, float rotation, glm::vec4 color) const;
	void drawRectangleTexture(glm::vec2 pos, glm::vec2 scale, glm::mat4 rotationMat, const Texture* texture) const;
	void drawLine(glm::vec2 a, glm::vec2 b) const;
	void drawText(float xStart, float yBaseline, Font font, FontSize fontSize, glm::vec4 color, std::string text) const;
	void GLClearErrors() const;
	bool GLLogErrors() const;

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
	Shader* sphereTextureShader;
	Shader* rectangleShader;
	Shader* rectangleTextureShader;
	Shader* lineShader;
	Shader* characterShader;
	Texture* reflectionsTexture;
	glm::vec2 reflectionsScale;
	FT_Library freetype;
	FT_Face face;
	std::map<char, Character> monotonCharacters[5];
	std::map<char, Character> notableCharacters[5];
};