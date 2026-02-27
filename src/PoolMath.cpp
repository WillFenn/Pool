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

Rotation PoolMath::addRotation(Rotation rotation1, Rotation rotation2) {
	glm::vec3 kBeforeRotations(0.0f, 0.0f, 1.0f);

	glm::mat4 rotation1mat = glm::rotate(glm::mat4(1.0f), rotation1.angle, rotation1.axis);
	glm::mat4 rotation2mat = glm::rotate(glm::mat4(1.0f), rotation2.angle, rotation1.axis);

	glm::vec3 kAfterRotations = rotation2mat * rotation1mat * glm::vec4(kBeforeRotations, 0.0f);

	float newAngle = glm::acos(glm::dot(kBeforeRotations, kAfterRotations));

	glm::vec3 newAxis;

	if (newAngle == 0.0f || newAngle == glm::pi<float>()) {
		newAxis = glm::vec3(1.0f, 0.0f, 0.0f);
	}
	else {
		newAxis = glm::normalize(glm::cross(kBeforeRotations, kAfterRotations));
	}

	std::cout << "----------------------------------------addRotation()----------------------------------------" << std::endl;						// delete
	std::cout << " kBeforeRotations  x: " << kBeforeRotations.x << "  y: "  << kBeforeRotations.y << "  z: " << kBeforeRotations.z << std::endl;	//
	std::cout << " kAfterRotations  x: " << kAfterRotations.x << "  y: " << kAfterRotations.y << "  z: " << kAfterRotations.z << std::endl;			//
	std::cout << std::endl << std::endl;																											//

	return { newAngle, newAxis };
}