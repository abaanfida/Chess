#pragma once
#include <iostream>
#include "Utility.h"
using namespace std;

class Board;

class Piece
{
protected:
	int ri, ci;
	Color c;
	Board* b;
	char sym = 0;
public:
	Piece(int r, int c, Color clr, Board* b);
	virtual void draw(int cr,int cc) = 0;
	void move(int r, int c);
	virtual bool is_legal(int sr, int sc, int dr, int dc) = 0;
	char getsym();
	Color getcolor();
};