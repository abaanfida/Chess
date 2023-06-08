#include "Pawn.h"
#include "Board.h"
using namespace std;

Pawn::Pawn(int r, int c, Color clr, Board* b)
	:Piece(r, c, clr, b)
{
	sym = 'p';
	count = 0;
}
void Pawn::draw(int cr,int cc)
{
	char sym = -37;
	SetClr(this->c);
	int r = cr - 1;
	int c = cc - 2;
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
bool Pawn::is_legal(int sr, int sc, int dr, int dc)
{
	if (c == WHITE)
	{
		int r = dr - sr;
		int c = abs(sc - dc);
		if (b->getpieceat(dr, dc) == nullptr)
		{
			
			if (count == 0)
				return r <= 2 && c == 0 && dr > sr && b->is_vertical_clear(sr,sc,dr,dc);

			return r <= 1 && c == 0 && dr > sr;
		}
		else
		{
			return r == 1 && c == 1;
		}
	}
	else
	{
		int r = sr - dr;
		int c = abs(sc - dc);
		if (b->getpieceat(dr, dc) == nullptr)
		{
			if (count == 0)
				return r <= 2 && c == 0 && sr > dr && b->is_vertical_clear(sr,sc,dr,dc);

			return r <= 1 && c == 0 && sr > dr;
		}
		else
		{
			return r == 1 && c == 1;
		}
		
	}
}
void Pawn::setcount()
{
	if (count == 0)
		count = 1;
}