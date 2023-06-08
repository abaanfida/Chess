#include "Knight.h"
using namespace std;

Knight::Knight(int r, int c, Color _c, Board* b) :Piece(r, c, _c, b)
{
	sym = 'n';
}
void Knight::draw(int cr,int cc)
{
	SetClr(this->c);
	char sym = -37;
	int r = cr - 2;
	int c = cc - 1;;
	for (int i = 1; i <= 2; i++)
	{
		gotoRowCol(r, c);
		cout << sym;
		c++;
	}
	r = cr - 1;
	c = cc - 3;
	for (int i = 1; i <= 5; i++)
	{
		gotoRowCol(r, c);
		cout << sym;
		c++;
	}
	r = cr;
	c = cc - 3;
	gotoRowCol(r, c);
	cout << sym;
	c++;
	gotoRowCol(r, c);
	cout << sym;
	c += 2;
	for (int i = 1; i <= 2; i++)
	{
		gotoRowCol(r, c);
		cout << sym;
		c++;
	}
	r = cr + 1;
	c = cc - 1;
	for (int i = 1; i <= 3; i++)
	{
		gotoRowCol(r, c);
		cout << sym;
		c++;
	}
	r = cr + 2;
	c = cc - 3;
	for (int i = 1; i <= 6; i++)
	{
		gotoRowCol(r, c);
		cout << sym;
		c++;
	}
}
bool Knight::is_legal(int sr, int sc, int dr, int dc)
{
	int r = abs(sr - dr);
	int c = abs(sc - dc);
	return (r == 1 && c == 2 || r == 2 && c == 1);
}
