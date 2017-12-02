#include "Slater.h"
#include <iostream>
#include <string>


void slater::test()
{

	sf::RenderWindow window(sf::VideoMode(640, 480), "Background star");

	sf::Texture texture;
	if(!texture.loadFromFile("stars_background_blue_photoshop_color_space_sky_dark-610854.jpg"));
	sf::Sprite sprite(texture);

	window.clear();
	window.draw(sprite);
	window.display();
}

