#include "Graphics.h"

Graphics::Graphics() {

	playerX = 100;
	playerY = 100;

	window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "FIR");
	window->setPosition(sf::Vector2i(150, 150));
	window->setVerticalSyncEnabled(false);
	window->setFramerateLimit(60);
	view = new sf::View(sf::FloatRect(0, 0, 1920, 1080));
	window->setView(*view);
	view->setCenter(playerX, playerY);
}

Graphics::~Graphics() {

}

void Graphics::Display() {

	window->clear();
	window->setView(*view);
	window->display();
}