#pragma once

#include <vec2.hpp>
#include <vec3.hpp>
#include <mat4x4.hpp>
#include <ext/matrix_transform.hpp>

namespace PoolMath {
	float projection(glm::vec2 a, glm::vec2 b);
	float absoluteValue(float x);
	float max(float x, float y);
	bool approximatelyEqual(float x, float y);
	bool approximatelyEqual(float x, float y, float error);
	bool approximatelyEqual(glm::vec2 a, glm::vec2 b, float error);
	glm::vec2 normal(glm::vec2 a);
	glm::mat4 addToRotationMat(glm::mat4 rotationMat, float rotationAngle, glm::vec3 rotationAxis);
	float pointLineSegmentDistance(glm::vec2 p, glm::vec2 a, glm::vec2 b, glm::vec2* outClosestPoint);
	float pointLineSegmentDistance(glm::vec2 p, glm::vec2 a, glm::vec2 b);
}