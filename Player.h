#pragma once
#include <string>
#include "Utility.h"
using namespace std;
class Player
{
protected:
	string name;
	Color c;
public:
	Player(string, Color);
	string getname();
	Color getcolor();
};

