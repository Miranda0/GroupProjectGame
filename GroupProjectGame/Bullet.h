#include "Objects.h"

class Bullet: public Object {
private:
	int direction;
public:
	Bullet(int direction, float xPos, float yPos);
	~Bullet();
	void moveObject();
	sf::Sprite &getGraphic();
	void virtual destroy();
};