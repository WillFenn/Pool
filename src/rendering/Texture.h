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
	Texture(std::string filepath, bool isCharTexture, bool flipOnLoad);
	Texture(unsigned char* buffer, int width, int height, bool isCharTexture);
	~Texture();
	void bind(unsigned int slot = 0);
	void bind() const;
	void unbind() const;
	unsigned int getSlot() const;
	void setSlot(unsigned int slot);

private:
	void GLClearErrors() const;
	bool GLLogErrors() const;

private:
	unsigned int textureID;
	unsigned int slot = 0;
	unsigned char* localBuffer;
	int width;
	int height;
	int numChannels;
};