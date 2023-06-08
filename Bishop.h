#pragma once
#include "Piece.h"
class Bishop :
    public Piece
{
public:
    Bishop(int, int, Color, Board*);
    virtual void draw(int cr,int cc);
    virtual bool is_legal(int sr, int sc, int dr, int dc);
};

