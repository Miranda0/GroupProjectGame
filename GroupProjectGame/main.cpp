// basic libraries
#include <iostream>
#include <string>						// strings are for yo-yos and cats only
#include "arthur.h"
#include "Asteroid.h"
#include "Slater.h"

// SFML libraries
#include <SFML/Graphics.hpp>

// namespace using statements
using std::cout;
using std::endl;

int main()
{
	cout << "Hello team" << endl;
	cout << "Arthur was here..." << endl;

	

	//arthur a;
	//a.arthurTestSFML(); // comment out or duplicate if you want to try some stuff out and my code is too messy
	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
	window.setFramerateLimit(60);
	Asteroid death;
	int time = 0;
	while (window.isOpen())
	{
		sf::Event event;
		time++;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
		}

		//slater edit

		sf::Texture texture;
		if (!texture.loadFromFile("milky_way_stars_night_sky_space_97654_1280x720.jpg"));
		sf::Sprite sprite(texture);
		//https://wallpaperscraft.com/image/milky_way_stars_night_sky_space_97654_1280x720.jpg
		window.clear(); //12-2-17 slater
		window.draw(sprite); //12-2-17 slater

		

		death.moveObject();
		//window.clear();
		window.draw(*death.getGraphic());
		window.display();
	}




	return 0;
}