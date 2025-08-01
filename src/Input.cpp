#include <Input.h>

Input::Input(GLFWwindow* glfwwindow) {
	this->glfwwindow = glfwwindow;
}

Input::~Input() {

}

bool Input::escKeyPressed() {
	return glfwGetKey(glfwwindow, GLFW_KEY_ESCAPE) == GLFW_PRESS;
}