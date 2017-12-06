// basic libraries
#include <iostream>
#include <string>// strings are for yo-yos and cats only
#include <list>
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
	srand(time(NULL));

	//arthur a;
	//a.arthurTestSFML(); // comment out or duplicate if you want to try some stuff out and my code is too messy
	
	int randEnemyGeneration = rand() % 5 + 1;
	std::list<Enemy1*> enemy1List;
	int enemy1Count = 0;

	healthkit health;
	Asteroid death;
	// window settings
	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);

	
	
	int time = 0;
	// player variables
	std::list<Bullet*> playerBullets;
	std::list<Bullet*> NPCBullets;
	int bulletCount = 0;
	int position_in_list = 0;
	std::list<Bullet*>::iterator it1, it2;
	std::list<Enemy1*>::iterator stepper;
	Bullet* b_ptr;
	Player player;
	player.setPosition(640, 600);
	float playerHVelocity = 0.0;
	float playerVVelocity = 0.0;
	float playerSpeed = 4.0;
	bool pressedLeft = false;
	bool pressedRight = false;
	bool pressedUp = false;
	bool pressedDown = false;
	bool firing = false;

	//debug
	sf::Text debugMessage;
	sf::Font font;
	font.loadFromFile("arial.ttf");
	debugMessage.setFillColor(sf::Color::White);
	debugMessage.setCharacterSize(24);
	debugMessage.setFont(font);

	// background code
	sf::Texture backgroundImage;
	if (!backgroundImage.loadFromFile("milky_way_stars_night_sky_space_97654_1280x720.jpg"));
	sf::Sprite background(backgroundImage);
	//https://wallpaperscraft.com/image/milky_way_stars_night_sky_space_97654_1280x720.jpg

	while (window.isOpen())
	{
		
		sf::Event event;
		time++;
		if (randEnemyGeneration == time && enemy1Count < 15) {
			Enemy1* newEnemy = new Enemy1;
			enemy1List.push_back(newEnemy);
			enemy1Count++;
			randEnemyGeneration = rand() % 30 + time;
		}
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
				if (event.key.code == sf::Keyboard::Space) {
					cout << "boom" << endl;
					playerBullets.push_back(new Bullet(90, player.getGraphic().getPosition().x + 20, player.getGraphic().getPosition().y + 20));
					//theOnlyBullet = new Bullet(90, player.getGraphic().getPosition().x, player.getGraphic().getPosition().y);
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
		for (auto const& e : enemy1List) {
			e->movement();
			e->deleteAtEdge();
			b_ptr = e->shoot();
			if (b_ptr != nullptr)
			{
				NPCBullets.push_back(b_ptr);
				bulletCount++;
			}
		}

		for (auto const& q : NPCBullets)
		{
			q->moveObject();

		}
		// this should be working neither remove nor erase works when I pass things in. using the list and nodes I made might work better but I don't want
		// to make that executive decision without discussion before hand. If you guys think that'll work best I am 90% sure my nodes are set up to do what
		//we are using this other list to do just use insert front or yell at me and I can walk throught it with y'all.
		bool allChecked = false;
		while (allChecked = false) {
			it1 = NPCBullets.begin();
			for (auto const& q : NPCBullets)
			{

					if (q->deleteAtEdge())
					{
						allChecked = false;
						break;
					}
					it1++;
					allChecked = true;
				}
			if (allChecked == false) {
				NPCBullets.erase(it1);
			}
		}

		for (auto const& b : playerBullets) {
			b->moveObject();
		}
		
		bool enemyChecked = false;
		while (allChecked = false) {
			stepper = enemy1List.begin();
			for (auto const& e : enemy1List)
			{

				if (e->deleteAtEdge())
				{
					enemyChecked = false;
					break;
				}
				stepper++;
				enemyChecked = true;
			}
			if (enemyChecked == false) {
				enemy1List.erase(stepper);
				enemy1Count--;
			}
		}

		//slater edit
		debugMessage.setString("player horizontal speed: " + std::to_string(playerHVelocity) + '\n' +
			"player vertical speed: " + std::to_string(playerVVelocity) + '\n' +
			"time(frames since start): " + std::to_string(time));

		// collisions
		if (player.checkCollision(death.getCollision())) {
			// cout << "bOOMSD!" << endl; // debug

		}
		else {
			// cout << endl;
		}

		// drawing stage
		window.clear(); //12-2-17 slater
		window.draw(background); //12-2-17 slater
		for (auto const& b : playerBullets) {
			window.draw(b->getGraphic());
		}
		for (auto const& q : NPCBullets)
		{
			window.draw(q->getGraphic());
		}
		window.draw(player.getGraphic());
		window.draw(*death.getGraphic());
		window.draw(*health.getGraphic());
		for (auto const& e : enemy1List) {
			window.draw(*e->get_graphic());
		}
		window.draw(debugMessage);
	
		window.display();
	}




	return 0;
}