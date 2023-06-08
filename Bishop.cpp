#include "Bishop.h"
#include "Board.h"
using namespace std;

Bishop::Bishop(int r, int c, Color _c, Board* b):Piece(r,c,_c,b)
{
	sym = 'b';
}
void Bishop::draw(int cr,int cc)
{
	SetClr(this->c);
	char sym = -37;

	int r, c;

	r = cr - 2;
	c = cc;
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
	c = cc - 2;
	for (int i = 1; i <= 5; i++)
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
bool Bishop::is_legal(int sr, int sc, int dr, int dc)
{
	if (dc < sc)
	{
		return (b->is_diagonal_move(sr,sc,dr,dc) && b->is_diagonal_R2L_clear(sr,sc,dr,dc));
	}
	else
	{
		return (b->is_diagonal_move(sr, sc, dr, dc) && b->is_diagonal_L2R_clear(sr, sc, dr, dc));
	}
}
