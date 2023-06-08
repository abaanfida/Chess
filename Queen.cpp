#include "Queen.h"
#include "Board.h"
using namespace std;

Queen::Queen(int r, int c, Color _c, Board* b) :Piece(r, c, _c, b)
{
	sym = 'q';
}
void Queen::draw(int cr,int cc)
{
	SetClr(this->c);
	char sym = -37;

	int r = cr - 2;
	int c = cc;
	gotoRowCol(r, c);
	cout << sym;

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
bool Queen::is_legal(int sr, int sc, int dr, int dc)
{
	return ((b->is_vertical_move(sr, sc, dr, dc) && b->is_vertical_clear(sr, sc, dr, dc) || b->is_horizontal_move(sr, sc, dr, dc) && b->is_horizontal_clear(sr, sc, dr, dc)) || (b->is_diagonal_move(sr, sc, dr, dc) && dc>sc&& b->is_diagonal_L2R_clear(sr, sc, dr, dc))|| (b->is_diagonal_move(sr, sc, dr, dc) && sc>dc&& b->is_diagonal_R2L_clear(sr, sc, dr, dc)));
}