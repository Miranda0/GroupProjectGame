#include "Objects.h"

class Bullet: public Object {
private:
	int direction;
public:
	Bullet(int direction);
	~Bullet();
	void moveObject();
	void virtual destroy();
};