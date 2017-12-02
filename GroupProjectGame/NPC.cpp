#include "NPC.h"

using std::cout;
using std::endl;

NPC_1::NPC_1():Object(40,3)
{

}

NPC_1::~NPC_1()
{
	cout << "destruction" << endl;
}
void set_graphic(sf::CircleShape* graphic);
void set_speed(float speed);
float get_speed();
sf::CircleShape* get_graphic();
void movement_pattern();