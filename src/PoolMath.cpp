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

bool PoolMath::approximatelyEqual(float x, float y, float error) {
	return absoluteValue(x - y) < error;
}

bool PoolMath::approximatelyEqual(glm::vec2 a, glm::vec2 b, float error) {
	return glm::distance(a, b) < error;
}

glm::vec2 PoolMath::normal(glm::vec2 a) {
	return glm::normalize(glm::vec2(a.y, -a.x));
}

glm::mat4 PoolMath::addToRotationMat(glm::mat4 rotationMat, float rotationAngle, glm::vec3 rotationAxis) {
	return glm::rotate(rotationMat, rotationAngle, -rotationAxis);
}

float PoolMath::pointLineSegmentDistance(glm::vec2 p, glm::vec2 a, glm::vec2 b, glm::vec2* outClosestPoint) {
	glm::vec2 closestPoint;
	glm::vec2 ab = b - a;
	glm::vec2 ap = p - a;
	float normalizedProj = dot(ab, ap) / (ab.x * ab.x + ab.y * ab.y);

	if (normalizedProj <= 0) {
		closestPoint = a;
	}
	else if (normalizedProj >= 1) {
		closestPoint = b;
	}
	else {
		closestPoint = a + ab * normalizedProj;
	}

	*outClosestPoint = closestPoint;

	return distance(p, closestPoint);
}

float PoolMath::pointLineSegmentDistance(glm::vec2 p, glm::vec2 a, glm::vec2 b) {
	glm::vec2 closestPoint;
	glm::vec2 ab = b - a;
	glm::vec2 ap = p - a;
	float normalizedProj = dot(ab, ap) / (ab.x * ab.x + ab.y * ab.y);

	if (normalizedProj <= 0) {
		closestPoint = a;
	}
	else if (normalizedProj >= 1) {
		closestPoint = b;
	}
	else {
		closestPoint = a + ab * normalizedProj;
	}

	return distance(p, closestPoint);
}