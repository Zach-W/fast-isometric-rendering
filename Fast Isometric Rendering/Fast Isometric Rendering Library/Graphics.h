#pragma once

#ifdef FIR_LIBRARY_EXPORTS
#define FIRLIBRARY_API __declspec(dllexport)
#else
#define FIRLIBRARY_API __declspec(dllimport)
#endif


#include <SFML/Graphics.hpp>


extern class Graphics {
public:
	Graphics();
	~Graphics();

	void Display();
private:


	double playerX;
	double playerY;

public:

	sf::RenderWindow* window;
	sf::View* view;
};