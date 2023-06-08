#include "Rook.h"
#include "Board.h"
using namespace std;

Rook::Rook(int r, int c, Color clr, Board* b)
	:Piece(r, c, clr, b)
{
	sym = 'r';
}
void Rook::draw(int cr,int cc)
{
	char sym = -37;
	SetClr(this->c);
	int r = cr - 2;
	int c = cc;
	gotoRowCol(r, c);
	cout << sym;
	r = cr - 1;
	c = cc - 2;
	for (int i = 1; i <= 5; i++)
	{
		gotoRowCol(r, c);
		cout << sym;
		c++;
	}
	r = cr;
	c = cc - 1;
	for (int i = 1; i <= 3; i++)
	{
		gotoRowCol(r, c);
		cout << sym;
		c++;
	}
	r = cr + 1;
	c = cc;
	gotoRowCol(r, c);
	cout << sym;
	r = cr + 2;
	c = cc - 2;
	for (int i = 1; i <= 5; i++)
	{
		gotoRowCol(r, c);
		cout << sym;
		c++;
	}
}
bool Rook::is_legal(int sr, int sc, int dr, int dc)
{
	return (b->is_vertical_move(sr, sc, dr, dc) && b->is_vertical_clear(sr, sc, dr, dc) || b->is_horizontal_move(sr, sc, dr, dc) && b->is_horizontal_clear(sr, sc, dr, dc));
}

