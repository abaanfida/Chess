#pragma once
#include <iostream>
using namespace std;

#include "Piece.h"


class Pawn :public Piece
{
	int count;
public:
	Pawn(int r, int c, Color clr, Board* b);
	virtual void draw(int cr,int cc);
    virtual bool is_legal(int sr,int sc,int dr,int dc);
	void setcount();
};
