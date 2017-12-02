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
	sf::CircleShape shape(50.f);
	shape.setPosition(640, 600);
	shape.setFillColor(sf::Color::Red);

	// player variables
	float playerHVelocity = 0.0;
	float playerVVelocity = 0.0;
	float playerSpeed = 0.25;
	bool pressedLeft = false;
	bool pressedRight = false;
	bool pressedUp = false;
	bool pressedDown = false;

	//debug
	sf::Text text;
	sf::Font font;
	font.loadFromFile("arial.ttf");
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(24);
	text.setFont(font);

	while (window.isOpen())
	{
		sf::Event event;

		// this is the main game loop
		// events in this loop will happen ~60 times a second
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
		playerVVelocity = (pressedDown - pressedUp) * playerSpeed/2;
		shape.move(playerHVelocity, playerVVelocity);
		text.setString("player h speed is: " + std::to_string(playerHVelocity));
		

		window.clear();
		window.draw(shape);
		window.draw(text);
		window.display();
	}
}