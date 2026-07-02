#pragma once

#include <vec2.hpp>

class Line {
public:
	Line(glm::vec2 a, glm::vec2 b);
	Line();
	glm::vec2 getA() const;
	glm::vec2 getB() const;

protected:
	glm::vec2 a;
	glm::vec2 b;
};