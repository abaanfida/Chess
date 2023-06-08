#include "Player.h"
Player::Player(string n,Color clr)
{
	this->name = n;
	this->c = clr;
}
Color Player::getcolor()
{
	return this->c;
}
string Player::getname()
{
	return this->name;
}