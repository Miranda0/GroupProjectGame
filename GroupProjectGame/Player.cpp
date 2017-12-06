#include "Player.h"
#include "Bullet.h"
#include <iostream>


Player::Player(): Object(5.0,0.0){
	playerGraphic.loadFromFile("fighter.png");
	graphic->setTexture(playerGraphic);
	//collisionBox.setSize(sf::Vector2f(texture.getSize().x, texture.getSize().y));
	collisionBox.setSize(sf::Vector2f(50.0f, 50.0f));
	collisionBox.setFillColor(sf::Color::White);
}
Player::~Player() {

}
void Player::move(float newX, float newY) {
	this->graphic->move(newX, newY);
	this->collisionBox.move(newX, newY);
}
void Player::shoot() {

	std::cout << "pew" << std::endl;
}
void Player::destroy() {
	std::cout << "player go boom" << std::endl;
}
/*
will heal player up to playerMaxHealth
precondition: healPoints is positive
*/
void Player::heal(int healPoints) {
	playerCurrentHealth += healPoints;
	if (playerCurrentHealth > playerMaxHealth)
		playerCurrentHealth = playerMaxHealth;
}
/*
will damage player until health is < 1
runs destroy() when player health is < 1
precondition: damagePoints is positive
*/
void Player::damage(int damagePoints) {
	playerCurrentHealth -= damagePoints;
	if (playerCurrentHealth < 1)
		destroy();
}
void Player::setPosition(float setX, float setY) {
	this->graphic->setPosition(setX, setY);
	this->collisionBox.setPosition(setX + 10, setY + 10);
}
bool Player::isAlive() {
	return alive;
}
sf::Sprite &Player::getGraphic(){
	return *graphic;
}
sf::RectangleShape Player::getCollisionBox() {
	return collisionBox;
}
bool Player::checkCollision(Collider &other) {
	sf::Vector2f otherPosition = other.getPosition();
	sf::Vector2f otherHalfSize = other.getHalfSize();
	sf::Vector2f thisPosition = collisionBox.getPosition();
	sf::Vector2f thisHalfSize = collisionBox.getSize() / 2.0f;

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;
	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f) {
		return true;
	}
	return false;
}