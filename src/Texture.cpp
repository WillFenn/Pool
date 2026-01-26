#include <Texture.h>

Texture::Texture(std::string filepath) {
	this->filepath = filepath;
	localBuffer = nullptr;
	width = 0;
	height = 0;
	numChannels = 0;

	stbi_set_flip_vertically_on_load(1);

	localBuffer = stbi_load(filepath.c_str(), &width, &height, &numChannels, 4);

	GLCALL(glGenTextures(1, &textureID));
	GLCALL(glBindTexture(GL_TEXTURE_2D, textureID));

	GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
	GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));

	GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
	GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

	GLCALL(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, localBuffer));
	GLCALL(glBindTexture(GL_TEXTURE_2D, 0));

	stbi_image_free(localBuffer);
}

Texture::~Texture() {
	GLCALL(glDeleteTextures(1, &textureID));
}

void Texture::bind(unsigned int slot) {
	this->slot = slot;
	GLCALL(glActiveTexture(GL_TEXTURE0 + slot));
	GLCALL(glBindTexture(GL_TEXTURE_2D, textureID));
}

void Texture::unbind() {
	GLCALL(glBindTexture(GL_TEXTURE_2D, 0));
}

unsigned int Texture::getSlot() {
	return slot;
}

void Texture::GLClearErrors() {
	while (glGetError() != GL_NO_ERROR);
}

bool Texture::GLLogErrors() {
	bool noErrors = true;

	while (GLenum error = glGetError()) {
		noErrors = false;

		switch (error) {
		case GL_INVALID_ENUM:
			std::cout << "OpenGL Error: GL_INVALID_ENUM" << std::endl << std::endl;
			break;
		case GL_INVALID_VALUE:
			std::cout << "OpenGL Error: GL_INVALID_VALUE" << std::endl << std::endl;
			break;
		case GL_INVALID_OPERATION:
			std::cout << "OpenGL Error: GL_INVALID_OPERATION" << std::endl << std::endl;
			break;
		case GL_STACK_OVERFLOW:
			std::cout << "OpenGL Error: GL_STACK_OVERFLOW" << std::endl << std::endl;
			break;
		case GL_STACK_UNDERFLOW:
			std::cout << "OpenGL Error: GL_STACK_UNDERFLOW" << std::endl << std::endl;
			break;
		case GL_OUT_OF_MEMORY:
			std::cout << "OpenGL Error: GL_OUT_OF_MEMORY" << std::endl << std::endl;
			break;
		case GL_INVALID_FRAMEBUFFER_OPERATION:
			std::cout << "OpenGL Error: GL_INVALID_FRAMEBUFFER_OPERATION" << std::endl << std::endl;
			break;
		case GL_CONTEXT_LOST:
			std::cout << "OpenGL Error: GL_CONTEXT_LOST" << std::endl << std::endl;
			break;
		case GL_TABLE_TOO_LARGE:
			std::cout << "OpenGL Error: GL_TABLE_TOO_LARGE" << std::endl << std::endl;
			break;
		}
	}

	return noErrors;
}