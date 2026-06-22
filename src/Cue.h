#pragma once

#include <vec2.hpp>
#include <GameObject.h>
#include <string>
#include <Texture.h>

struct Cue : public GameObject {
public:
	Cue(glm::vec2 pos, std::string textureFilepath, bool flipTexture, bool active);
	Cue();
	float getSpeed();
	void setSpeed(float speed);
	bool getWasPulledBack();
	void setWasPulledBack(bool wasPulledBack);

private:
	float speed;
	bool wasPulledBack;
};