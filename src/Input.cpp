#include <Input.h>

Input::Input(GLFWwindow* glfwwindow) {
	this->glfwwindow = glfwwindow;
}

Input::~Input() {

}

glm::vec2 Input::getMousePos() {
	double xPos, yPos;
	glfwGetCursorPos(glfwwindow, &xPos, &yPos);

	return glm::vec2(xPos, yPos);
}

bool Input::leftMousePressed() {
	int state = glfwGetMouseButton(glfwwindow, GLFW_MOUSE_BUTTON_LEFT);
	return state == GLFW_PRESS;
}

bool Input::escKeyPressed() {
	return glfwGetKey(glfwwindow, GLFW_KEY_ESCAPE) == GLFW_PRESS;
}