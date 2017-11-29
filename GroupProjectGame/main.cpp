// basic libraries
#include <iostream>
#include <string>						// strings are for yo-yos and cats only

// SFML libraries
#include <SFML/Graphics.hpp>

// namespace using statements
using std::cout;
using std::endl;

// function prototypes
void arthurTestSFML();

int main()
{
	cout << "Hello team" << endl;
	cout << "Arthur was here..." << endl;

	arthurTestSFML(); // comment out or duplicate if you want to try some stuff out and my code is too messy

	return 0;
}

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
void arthurTestSFML()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
	sf::CircleShape shape(50.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		window.setKeyRepeatEnabled(true);

		// player variables
		float playerHVelocity = 0.0;
		float playerVVelocity = 0.0;
		float playerSpeed = 5.0;

		// this is the main game loop
		// events in this loop will happen ~60 times a second
		while (window.pollEvent(event))
		{
			// player controls that should be better
			/*
			if (event.type == sf::Event::KeyPressed)			// key press
			{
				if (event.key.code == sf::Keyboard::Right) {
					playerHVelocity = playerSpeed;
				}
			}
			if (event.type == sf::Event::KeyReleased) 			// key release
			{
				if (event.key.code == sf::Keyboard::Right) {
					playerHVelocity = 0.0;
				}
			}
			shape.move(playerHVelocity, playerVVelocity);

			/*/

			// sucky player controls 
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				shape.move(-playerSpeed, 0.0);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				shape.move(playerSpeed, 0.0);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				shape.move(0.0, -playerSpeed);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				shape.move(0.0, playerSpeed);
			//*/

			// exit functions
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
}