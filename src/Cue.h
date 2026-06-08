#pragma once

#include <vec2.hpp>
#include <GameObject.h>
#include <string>
#include <Texture.h>

struct Cue : public GameObject {
public:
	Cue(glm::vec2 pos, std::string textureFilepath, bool flipTexture);
	Cue();
	Cue(const Cue& other);

	float speed;
	bool wasPulledBack;
};