#include <Side.h>

Side::Side(glm::vec2 a, glm::vec2 b, glm::vec2 normal) {
	this->a = a;
	this->b = b;
	this->normal = normal;
}

Side::Side() {}

glm::vec2 Side::getNormal() const {
	return normal;
}