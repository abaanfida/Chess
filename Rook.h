#pragma once
#include "Piece.h"
#include <iostream>
class Rook :
    public Piece
{
public:
    Rook(int, int, Color, Board*);
    virtual void draw(int cr,int cc);
    virtual bool is_legal(int sr, int sc, int dr, int dc);
};

