// basic libraries
#include <iostream>
#include <string>						// strings are for yo-yos and cats only
#include "arthur.h"
#include "Asteroid.h"
#include "Slater.h"
#include "Player.h"
#include "healthkit.h"
#include "Andrew.h"
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

	Enemy1 a(1), b(2), c(3), d(4);
	a.movement();
	b.movement();
	c.movement();
	d.movement();

	// window settings
	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
	window.setFramerateLimit(60);

	healthkit health;
	Asteroid death;
	
	int time = 0;
	// player variables
	Player player;
	player.setPosition(640, 600);
	float playerHVelocity = 0.0;
	float playerVVelocity = 0.0;
	float playerSpeed = 4.0;
	bool pressedLeft = false;
	bool pressedRight = false;
	bool pressedUp = false;
	bool pressedDown = false;

	//debug
	sf::Text debugMessage;
	sf::Font font;
	font.loadFromFile("arial.ttf");
	debugMessage.setFillColor(sf::Color::White);
	debugMessage.setCharacterSize(24);
	debugMessage.setFont(font);
	sf::Texture backgroundImage;
	if (!backgroundImage.loadFromFile("milky_way_stars_night_sky_space_97654_1280x720.jpg"));
	sf::Sprite background(backgroundImage);
	//https://wallpaperscraft.com/image/milky_way_stars_night_sky_space_97654_1280x720.jpg

	while (window.isOpen())
	{
		sf::Event event;
		time++;
		while (window.pollEvent(event))
		{

			// player controls that should be better
			if (event.type == sf::Event::KeyPressed)			// key press
			{
				if (!pressedLeft && event.key.code == sf::Keyboard::Left) {
					pressedLeft = true;
				}
				if (!pressedRight && event.key.code == sf::Keyboard::Right) {
					pressedRight = true;
				}
				if (!pressedUp && event.key.code == sf::Keyboard::Up) {
					pressedUp = true;
				}
				if (!pressedDown && event.key.code == sf::Keyboard::Down) {
					pressedDown = true;
				}
			}
			if (event.type == sf::Event::KeyReleased) 			// key release
			{
				if (pressedLeft && event.key.code == sf::Keyboard::Left) {
					pressedLeft = false;
				}
				if (pressedRight && event.key.code == sf::Keyboard::Right) {
					pressedRight = false;
				}
				if (pressedUp && event.key.code == sf::Keyboard::Up) {
					pressedUp = false;
				}
				if (pressedDown && event.key.code == sf::Keyboard::Down) {
					pressedDown = false;
				}
			}

			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
		}

		// sum movements
		playerHVelocity = (pressedRight - pressedLeft) * playerSpeed;
		playerVVelocity = ((pressedDown * 1.5) - (pressedUp)) * playerSpeed * !(pressedUp && pressedDown);
		player.move(playerHVelocity, playerVVelocity);
		death.moveObject();
		a.movement();
		b.movement();
		c.movement();
		d.movement();
		a.shoot();
		b.shoot();
		c.shoot();
		d.shoot();
		//slater edit
		debugMessage.setString("player horizontal speed: " + std::to_string(playerHVelocity) + '\n' +
			"player vertical speed: " + std::to_string(playerVVelocity) + '\n' +
			"time(frames since start): " + std::to_string(time));
		
		

		// drawing stage
		window.clear(); //12-2-17 slater
		window.draw(background); //12-2-17 slater
		window.draw(player.getGraphic());
		window.draw(*death.getGraphic());
		window.draw(*health.getGraphic());
		window.draw(*a.get_graphic());
		window.draw(*b.get_graphic());
		window.draw(*c.get_graphic());
		window.draw(*d.get_graphic());
		window.display();
	}




	return 0;
}