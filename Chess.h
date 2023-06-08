#pragma once
#include <iostream>
using namespace std;

class Board;
class Piece;
class Player;

class Chess
{
	int sri, sci, dri, dci;
	int turn;
	Player* Ps[2];
	Board* fakeb;
	Board* checkb;
	Board* b;
	Board* saveb;
	bool** bmap;
public:
	Chess();
	Chess(ifstream& rdr);
	void play();
	void select_piece();
	void select_dest();
	bool valid_source(Player* a, int r, int c);
	bool valid_dest(Player* a, int r, int c);
	void display_turn_msg(Player* a);
	void turn_change();
	bool** compute_highlight(Player*a,int sr, int sc);
	void find_king(Player* a,Board*B,int& r, int& c);
	bool check(Board*B);
	bool self_check(Board* B);
	bool checkmate();
	void pawn_first();
	void save();
};

