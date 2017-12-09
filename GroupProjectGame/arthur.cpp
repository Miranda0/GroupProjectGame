#include "arthur.h"
#include <iostream>
#include <string>
#include <list>
#include "NPC.h"
#include "Player.h"
#include "Enemy3.h"
#include "Andrew.h"
#include "healthkit.h"
#include "Asteroid.h"

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
	// window settings
	//sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
	//window.setFramerateLimit(60);
	//window.setKeyRepeatEnabled(false);
	//int time = 0;

	//// entities
	//int randEnemyGeneration = rand() % 5 + 1;
	//std::list<Enemy1*> enemy1List;
	//int enemy1Count = 0;
	//healthkit health;	// debug
	//Asteroid death;		// debug

	//// player variables
	//std::list<Bullet*> playerBullets;
	//std::list<Bullet*> NPCBullets;
	//int bulletCount = 0;
	//int position_in_list = 0;
	//std::list<Bullet*>::iterator it1, it2;
	//std::list<Enemy1*>::iterator stepper;
	//Bullet* b_ptr;
	//Player player;
	//player.setPosition(640, 600);
	//float playerHVelocity = 0.0;
	//float playerVVelocity = 0.0;
	//float playerSpeed = 4.0;
	//bool pressedLeft = false;
	//bool pressedRight = false;
	//bool pressedUp = false;
	//bool pressedDown = false;
	//bool firing = false;

	////debug (maybe use this for player health?)
	//sf::Text debugMessage;
	//sf::Font font;
	//font.loadFromFile("arial.ttf");
	//debugMessage.setFillColor(sf::Color::White);
	//debugMessage.setCharacterSize(24);
	//debugMessage.setFont(font);

	//// background code
	//sf::Texture backgroundImage;
	//if (!backgroundImage.loadFromFile("milky_way_stars_night_sky_space_97654_1280x720.jpg"));
	//sf::Sprite background(backgroundImage);
	////https://wallpaperscraft.com/image/milky_way_stars_night_sky_space_97654_1280x720.jpg

	//while (window.isOpen())
	//{
	//	sf::Event event;
	//	time++;
	//	while (window.pollEvent(event))
	//	{
	//		// player controls that should be better
	//		if (event.type == sf::Event::KeyPressed)			// key press
	//		{
	//			if (!pressedLeft && event.key.code == sf::Keyboard::Left) {
	//				pressedLeft = true;
	//			}
	//			if (!pressedRight && event.key.code == sf::Keyboard::Right) {
	//				pressedRight = true;
	//			}
	//			if (!pressedUp && event.key.code == sf::Keyboard::Up) {
	//				pressedUp = true;
	//			}
	//			if (!pressedDown && event.key.code == sf::Keyboard::Down) {
	//				pressedDown = true;
	//			}
	//			if (event.key.code == sf::Keyboard::Space) {
	//				cout << "boom" << endl;
	//				playerBullets.push_back(new Bullet(90, player.getGraphic().getPosition().x + 20, player.getGraphic().getPosition().y + 20));
	//			}
	//		}
	//		if (event.type == sf::Event::KeyReleased) 			// key release
	//		{
	//			if (pressedLeft && event.key.code == sf::Keyboard::Left) {
	//				pressedLeft = false;
	//			}
	//			if (pressedRight && event.key.code == sf::Keyboard::Right) {
	//				pressedRight = false;
	//			}
	//			if (pressedUp && event.key.code == sf::Keyboard::Up) {
	//				pressedUp = false;
	//			}
	//			if (pressedDown && event.key.code == sf::Keyboard::Down) {
	//				pressedDown = false;
	//			}
	//		}

	//		if (event.type == sf::Event::Closed)
	//			window.close();
	//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	//			window.close();
	//	}

	//	// sum movements
	//	playerHVelocity = (pressedRight - pressedLeft) * playerSpeed;
	//	playerVVelocity = ((pressedDown * 1.5) - (pressedUp)) * playerSpeed * !(pressedUp && pressedDown);
	//	player.move(playerHVelocity, playerVVelocity);
	//	death.moveObject();
	//	for (auto const& q : NPCBullets) {
	//		q->moveObject();
	//	}
	//	for (auto const& b : playerBullets) {
	//		b->moveObject();
	//	}
	//	for (auto const& e : enemy1List) {
	//		e->movement();
	//		e->deleteAtEdge();
	//		b_ptr = e->shoot();
	//		if (b_ptr != nullptr)
	//		{
	//			NPCBullets.push_back(b_ptr);
	//			bulletCount++;
	//		}
	//	}

	//	// random generation of entities
	//	if (randEnemyGeneration < time && enemy1List.size() < 15) {
	//		Enemy1* newEnemy = new Enemy1;
	//		enemy1List.push_back(newEnemy);
	//		enemy1Count++;
	//		randEnemyGeneration = rand() % 30 + time + 60;
	//	}


	//	// removing off screen objects
	//	bool allChecked = false;
	//	while (allChecked == false && NPCBullets.size() > 0) {	// remove enemy bullets
	//		it1 = NPCBullets.begin();
	//		for (auto const& q : NPCBullets)
	//		{

	//			if (q->deleteAtEdge())
	//			{
	//				allChecked = false;
	//				break;
	//			}
	//			it1++;
	//			allChecked = true;
	//		}
	//		if (allChecked == false) {
	//			NPCBullets.erase(it1);
	//		}
	//	}
	//	bool enemyChecked = false;
	//	while (enemyChecked == false && enemy1List.size() > 0) {	// remove enemies
	//		stepper = enemy1List.begin();
	//		for (auto const& e : enemy1List)
	//		{

	//			if (e->deleteAtEdge())
	//			{
	//				enemyChecked = false;
	//				break;
	//			}
	//			stepper++;
	//			enemyChecked = true;
	//		}
	//		if (enemyChecked == false) {
	//			enemy1List.erase(stepper);
	//			enemy1Count--;
	//		}
	//	}

	//	// this should be working neither remove nor erase works when I pass things in. 
	//	// using the list and nodes I made might work better but I don't want
	//	// to make that executive decision without discussion before hand. 
	//	// If you guys think that'll work best I am 90% sure my nodes are set up to do what
	//	// we are using this other list to do just use insert front or yell at me and I can 
	//	// walk throught it with y'all.

	//	//slater edit
	//	debugMessage.setString("player horizontal speed: " + std::to_string(playerHVelocity) + '\n' +
	//		"NPCBullets.size() =  " + std::to_string(NPCBullets.size()) + '\n' +
	//		"Enemy1List.size() =  " + std::to_string(enemy1List.size()) + '\n' +
	//		"time(frames since start): " + std::to_string(time));

	//	// collisions
	//	if (player.checkCollision(death.getCollision())) {
	//		// cout << "bOOMSD!" << endl; // debug

	//	}
	//	else {
	//		// cout << endl;
	//	}

	//	// drawing stage
	//	window.clear(); //12-2-17 slater
	//	window.draw(background); //12-2-17 slater
	//	for (auto const& b : playerBullets) {
	//		window.draw(b->getGraphic());
	//	}
	//	for (auto const& q : NPCBullets)
	//	{
	//		window.draw(q->getGraphic());
	//	}
	//	for (auto const& e : enemy1List) {
	//		window.draw(*e->get_graphic());
	//	}
	//	window.draw(player.getGraphic());
	//	window.draw(*death.getGraphic());
	//	window.draw(*health.getGraphic());
	//	window.draw(debugMessage);
	//
	//	window.display();
	//}
}