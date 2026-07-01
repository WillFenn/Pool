#include <Input.h>

Input::Input(GLFWwindow* glfwwindow, glm::vec2 resolution, glm::vec2 worldScale) {
	this->glfwwindow = glfwwindow;
	this->resolution = resolution;
	this->worldScale = worldScale;
	deltaTimeCalled = false;
}

Input::~Input() {

}

double Input::getTime() const {
	return glfwGetTime();
}

double Input::getDeltaTime() {
	if (!deltaTimeCalled) {
		deltaTimeCalled = true;

		prevTime = glfwGetTime();

		return 0.0f;
	}

	double currentTime = glfwGetTime();

	double deltaTime = currentTime - prevTime;

	prevTime = currentTime;

	return deltaTime;
}

glm::vec2 Input::getMousePos() const {
	double xPos, yPos;
	glfwGetCursorPos(glfwwindow, &xPos, &yPos);

	return glm::vec2(xPos, yPos);
}

glm::vec2 Input::getMouseWorldPos() const {
	glm::vec2 mouseWorldPos = ((getMousePos() - resolution / 2.0f) / (resolution / 2.0f)) * (worldScale / 2.0f);
	mouseWorldPos.y *= -1;

	return mouseWorldPos;
}

bool Input::leftMousePressed() const {
	int state = glfwGetMouseButton(glfwwindow, GLFW_MOUSE_BUTTON_LEFT);
	return state == GLFW_PRESS;
}

bool Input::leftMouseReleased() const {
	int state = glfwGetMouseButton(glfwwindow, GLFW_MOUSE_BUTTON_LEFT);
	return state == GLFW_RELEASE;
}

bool Input::escKeyPressed() const {
	return glfwGetKey(glfwwindow, GLFW_KEY_ESCAPE) == GLFW_PRESS;
}