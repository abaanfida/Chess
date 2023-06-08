#pragma once
#include <iostream>
using namespace std;

class Piece;

class Board
{
protected:
	Piece*** ps;
public:
	Board();
	Board(ifstream& rdr);
	void display_board();
	Piece* getpieceat(int r, int c);
	void move(int sr, int sc, int dr, int dc);
	bool is_horizontal_move(int sr, int sc, int dr, int dc);
	bool is_vertical_move(int sr, int sc, int dr, int dc);
	bool is_diagonal_move(int sr, int sc, int dr, int dc);
	bool is_horizontal_clear(int sr, int sc, int dr, int dc);
	bool is_vertical_clear(int sr, int sc, int dr, int dc);
	bool is_diagonal_L2R_clear(int sr, int sc, int dr, int dc);
	bool is_diagonal_R2L_clear(int sr, int sc, int dr, int dc);
	void highlight(bool** m);
	void unhighlight(bool** m);
	void copy(Board *b);
	void swap(int sr,int sc,int dr,int dc);
	void pawn_promote(int dr,int dc,int turn);
};
