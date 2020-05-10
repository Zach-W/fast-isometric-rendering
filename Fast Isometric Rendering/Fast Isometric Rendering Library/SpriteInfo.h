#pragma once

#include <SFML/Graphics.hpp>

extern class SpriteInfo {
public:
	SpriteInfo();
	~SpriteInfo();


private:

	std::pair<int, int> spritePositon;
	std::pair<int, int> spriteDimentions;
	int variantMax;


};