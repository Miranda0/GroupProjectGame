#include "arthur.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;


/*
Arthur: I am using this just to test SFML for the time being
we can get rid of it once we actually start building
the game for reals

SFML installation:
In the sfml zip file theres just a folder which contains everything
I just put that folder directly into my C: directory (C:\SFML-2.4.2).
I think if everyone puts it in the same directory it should work for everyone.
I dont know how to manage things if everyone has it in different
directories on their computer.
*/
void arthur::arthurTestSFML()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
	window.setFramerateLimit(60);
	sf::CircleShape shape(50.f);
	shape.setPosition(640, 600);
	shape.setFillColor(sf::Color::Red);

	// time 
	int time = 0;

	// player variables
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

	// this is the main game loop
	// events in this loop will happen ~60 times a second
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

			// exit functions
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
		}
		// sum the movement together
		playerHVelocity = (pressedRight - pressedLeft) * playerSpeed;
		playerVVelocity = ((pressedDown * 1.5) - (pressedUp)) * playerSpeed * !(pressedUp && pressedDown);
		shape.move(playerHVelocity, playerVVelocity);


		debugMessage.setString("player horizontal speed: " + std::to_string(playerHVelocity) + '\n' +
							   "player vertical speed: " + std::to_string(playerVVelocity) + '\n' +
							   "time(frames since start): " + std::to_string(time));
		

		window.clear();
		window.draw(shape);
		window.draw(debugMessage);
		window.display();
	}
}