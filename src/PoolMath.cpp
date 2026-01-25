#include <PoolMath.h>

float PoolMath::projection(glm::vec2 a, glm::vec2 b) {
	return glm::dot(a, b) / glm::length(b);
}

float PoolMath::absoluteValue(float x) {
	if (x < 0.0f) {
		return -x;
	}

	return x;
}

float PoolMath::max(float x, float y) {
	if (x >= y) {
		return x;
	}

	return y;
}

bool PoolMath::approximatelyEqual(float x, float y) {
	return absoluteValue(x - y) < 0.1f;
}

glm::vec2 PoolMath::normal(glm::vec2 a) {
	return glm::normalize(glm::vec2(a.y, -a.x));
}