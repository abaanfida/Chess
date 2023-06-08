#include "King.h"
#include "Board.h"
using namespace std;

King::King(int r, int c, Color _c, Board* b) :Piece(r, c, _c, b)
{
	sym = 'k';
}
void King::draw(int cr,int cc)
{
	SetClr(this->c);
	char sym = -37;
	int r = cr - 2;
	int c = cc - 2;
	for (int i = 1; i <= 3; i++)
	{
		gotoRowCol(r, c);
		cout << sym;
		c += 2;
	}
	r = cr - 1;
	c = cc - 1;
	for (int i = 1; i <= 3; i++)
	{
		gotoRowCol(r, c);
		cout << sym;
		c++;
	}
	r = cr;
	c = cc;
	gotoRowCol(r, c);
	cout << sym;
	r = cr + 1;
	c = cc - 1;
	for (int i = 1; i <= 3; i++)
	{
		gotoRowCol(r, c);
		cout << sym;
		c++;
	}
	r = cr + 2;
	c = cc - 2;
	for (int i = 1; i <= 5; i++)
	{
		gotoRowCol(r, c);
		cout << sym;
		c++;
	}
}
bool King::is_legal(int sr, int sc, int dr, int dc)
{
	int r = abs(sr - dr);
	int c = abs(sc - dc);
	return r<=1&&c<=1&&((b->is_vertical_move(sr, sc, dr, dc) || b->is_horizontal_move(sr, sc, dr, dc) || (b->is_diagonal_move(sr, sc, dr, dc) )));
}