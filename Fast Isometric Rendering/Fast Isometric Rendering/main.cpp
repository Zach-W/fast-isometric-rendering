
#include <stdio.h>
#include "Graphics.h"


int main() {

	Graphics g;

	while (g.window->isOpen()) {

		sf::Event event;
		while (g.window->pollEvent(event)) {

			switch (event.type) {
			case sf::Event::Closed:
				g.window->close();
				break;
			default:
				break;
			}

		}

		g.Display();

	}


	return 0;
}