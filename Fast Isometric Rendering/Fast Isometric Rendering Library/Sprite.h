#pragma once



#include <SFML/Graphics.hpp>

extern class Sprite {
public:
	Sprite();
	~Sprite();


private:

	std::pair<int, int> spriteLocation;

	int variantIndex;
	int rotationIndex;
	int animationFrame;


};