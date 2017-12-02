// basic libraries
#include <iostream>
#include <string>						// strings are for yo-yos and cats only
#include "arthur.h"

// SFML libraries
#include <SFML/Graphics.hpp>

// namespace using statements
using std::cout;
using std::endl;

int main()
{
	cout << "Hello team" << endl;
	cout << "Arthur was here..." << endl;

	arthur a;
	a.arthurTestSFML(); // comment out or duplicate if you want to try some stuff out and my code is too messy
	return 0;
}