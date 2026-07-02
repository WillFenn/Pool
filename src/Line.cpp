#include <Line.h>

Line::Line(glm::vec2 a, glm::vec2 b) {
	this->a = a;
	this->b = b;
}

Line::Line() {}

glm::vec2 Line::getA() const {
	return a;
}

glm::vec2 Line::getB() const {
	return b;
}