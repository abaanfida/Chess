#include "Piece.h"
using namespace std;

Piece::Piece(int r, int c, Color clr, Board* _b)
{
	this->ri = r;
	this->ci = c;
	this->c = clr;
	this->b = _b;
}
void Piece::move(int r, int c)
{
	this->ri = r;
	this->ci = c;
}
Color Piece::getcolor()
{
	return this->c;
}
char Piece::getsym()
{
	return sym;
}