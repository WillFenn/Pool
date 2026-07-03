#pragma once

#define ASSERT(x) if (!(x)) __debugbreak()
#define GLCALL(x) GLClearErrors();\
	x;\
	ASSERT(GLLogErrors());

#include <iostream>
#include <string>
#include <fstream>
#include <glew.h>
#include <glfw3.h>
#include <vec4.hpp>
#include <mat4x4.hpp>

class Shader {
public:
	Shader(const char* vsFilepath, const char* fsFilepath);
	~Shader();
	void compileShader(const char* source, unsigned int shaderType, unsigned int* ID) const;
	void bind() const;
	void unbind() const;
	std::string readFile(const char* filepath) const;
	void setUniformInt(int value, const char* name) const;
	void setUniformFloat(float value, const char* name) const;
	void setUniformVec2(glm::vec2 vec2, const char* name) const;
	void setUniformIVec2(glm::ivec2 ivec2, const char* name) const;
	void setUniformVec3(glm::vec3 vec3, const char* name) const;
	void setUniformVec4(glm::vec4 vec4, const char* name) const;
	void setUniformMat4(glm::mat4 mat4, const char* name) const;
	void GLClearErrors() const;
	bool GLLogErrors() const;

private:
	unsigned int vsID;
	unsigned int fsID;
	unsigned int programID;
};