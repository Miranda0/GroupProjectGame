// basic libraries
#include <iostream>
#include <string>						// strings are for yo-yos and cats only

// SFML libraries
#include <SFML/Graphics.hpp>

// namespace using statements
using std::cout;
using std::endl;

// function prototypes
void testSFML();

int main() 
{
	cout << "Hello team" << endl;
	cout << "Arthur was here..." << endl;

	testSFML();

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
void testSFML()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
}