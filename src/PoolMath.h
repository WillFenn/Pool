#pragma once

#include <vec2.hpp>
#include <ext/matrix_transform.hpp>

namespace PoolMath {
	float projection(glm::vec2 a, glm::vec2 b) {
		return glm::dot(a, b) / glm::length(b);
	}

	float absoluteValue(float x) {
		if (x < 0.0f) {
			return -x;
		}

		return x;
	}

	float max(float x, float y) {
		if (x >= y) {
			return x;
		}

		return y;
	}

	bool approximatelyEqual(float x, float y) {
		return absoluteValue(x - y) < 0.1f;
	}

	glm::vec2 normal(glm::vec2 a) {
		return glm::normalize(glm::vec2(a.y, -a.x));
	}
}