#include <Shader.h>

Shader::Shader(const char* vsFilepath, const char* fsFilepath) {
	std::cout << "vsFilepath: " << vsFilepath << std::endl;	//delete
	std::string vsSourceString = readFile(vsFilepath);
	std::cout << "vsSourceString:" << vsSourceString << std::endl;	//delete
	const char* vsSource = vsSourceString.c_str();
	std::cout << "vertex shader:\n" << vsSource << std::endl;	//delete
	std::string fsSourceString = readFile(fsFilepath);
	const char* fsSource = fsSourceString.c_str();
	std::cout << "fragment shader:\n" << fsSource << std::endl;	//delete

	compileShader(vsSource, GL_VERTEX_SHADER, &vsID);
	compileShader(fsSource, GL_FRAGMENT_SHADER, &fsID);

	programID = glCreateProgram();
	GLCALL(glAttachShader(programID, vsID));
	GLCALL(glAttachShader(programID, fsID));
	GLCALL(glLinkProgram(programID));

	GLCALL(glDetachShader(programID, vsID));
	GLCALL(glDetachShader(programID, fsID));
	GLCALL(glDeleteShader(vsID));
	GLCALL(glDeleteShader(fsID));
}

Shader::~Shader() {
	GLCALL(glDeleteProgram(programID));
}

void Shader::compileShader(const char* source, unsigned int shaderType, unsigned int* ID) {
	GLCALL(*ID = glCreateShader(shaderType));
	GLCALL(glShaderSource(*ID, 1, &source, 0));
	GLCALL(glCompileShader(*ID));
	int isCompiled;
	GLCALL(glGetShaderiv(*ID, GL_COMPILE_STATUS, &isCompiled));
	if (isCompiled == GL_FALSE) {
		int length;
		GLCALL(glGetShaderiv(*ID, GL_INFO_LOG_LENGTH, &length));
		char* message = (char*)alloca(length * sizeof(char));
		GLCALL(glGetShaderInfoLog(*ID, length, &length, message));
		std::cout << "Failed to compile " << (shaderType == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader" << std::endl;
		std::cout << message << std::endl;
		GLCALL(glDeleteShader(*ID));
	}
}

void Shader::bind() {
	GLCALL(glUseProgram(programID));
}

void Shader::unbind() {
	GLCALL(glUseProgram(0));
}

std::string Shader::readFile(const char* filepath) {
	std::ifstream stream(filepath);
	std::string text;
	std::string line;

	while (getline(stream, line))
	{
		text += line + '\n';
	}

	return text;
}

void Shader::setUniformInt(int value, const char* name) {
	GLCALL(int location = glGetUniformLocation(programID, name));

	GLCALL(glUniform1i(location, value));
}

void Shader::setUniformFloat(float value, const char* name) {
	GLCALL(int location = glGetUniformLocation(programID, name));

	GLCALL(glUniform1f(location, value));
}

void Shader::setUniformVec2(glm::vec2 vec2, const char* name) {
	GLCALL(int location = glGetUniformLocation(programID, name));

	GLCALL(glUniform2f(location, vec2[0], vec2[1]));
}

void Shader::setUniformIVec2(glm::ivec2 ivec2, const char* name) {
	GLCALL(int location = glGetUniformLocation(programID, name));

	GLCALL(glUniform2i(location, ivec2[0], ivec2[1]));
}

void Shader::setUniformVec4(glm::vec4 vec4, const char* name) {
	GLCALL(int location = glGetUniformLocation(programID, name));

	GLCALL(glUniform4f(location, vec4[0], vec4[1], vec4[2], vec4[3]));
}

void Shader::setUniformMat4(glm::mat4 mat4, const char* name) {
	GLCALL(int location = glGetUniformLocation(programID, name));

	GLCALL(glUniformMatrix4fv(location, 1, false, &mat4[0][0]));
}

void Shader::GLClearErrors() {
	while (glGetError() != GL_NO_ERROR);
}

bool Shader::GLLogErrors() {
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