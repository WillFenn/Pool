#pragma once

#include <vec2.hpp>
#include <ext/matrix_transform.hpp>

namespace PoolMath {
	float projection(glm::vec2 a, glm::vec2 b);
	float absoluteValue(float x);
	float max(float x, float y);
	bool approximatelyEqual(float x, float y);
	glm::vec2 normal(glm::vec2 a);
}