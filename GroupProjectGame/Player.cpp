#include "Player.h"
#include <iostream>


Player::Player(): Object(5.0,0.0){
	playerGraphic.loadFromFile("fighter.png");
	graphic->setTexture(playerGraphic);
}
Player::~Player() {

}
void Player::move(float newX, float newY) {
	this->graphic->move(newX, newY);
}
void Player::shoot() {
	std::cout << "pew" << std::endl;
}
void Player::destroy() {
	std::cout << "player go boom" << std::endl;
}
void Player::setPosition(float setX, float setY) {
	this->graphic->setPosition(setX, setY);
}
bool Player::isAlive() {
	return alive;
}
sf::Sprite &Player::getGraphic(){
	return *graphic;
}