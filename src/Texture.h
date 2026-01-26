#pragma once

#define ASSERT(x) if (!(x)) __debugbreak()
#define GLCALL(x) GLClearErrors();\
	x;\
	ASSERT(GLLogErrors());

#include <iostream>
#include <string>
#include <glew.h>
#include <stb_image.h>

class Texture {
public:
	Texture(std::string filepath);
	~Texture();
	void bind(unsigned int slot = 0);
	void unbind();
	unsigned int getSlot();

private:
	void GLClearErrors();
	bool GLLogErrors();

private:
	std::string filepath;
	unsigned int textureID;
	unsigned int slot = 0;
	unsigned char* localBuffer;
	int width;
	int height;
	int numChannels;
};