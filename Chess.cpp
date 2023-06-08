#include "Chess.h"
#include "Board.h"
#include "King.h" 
#include "Pawn.h"
#include "Player.h"
#include <time.h>
#include "Piece.h"
#include <iostream>
#include <fstream>
using namespace std;
Chess::Chess()
{
	Ps[0] = new Player("TORY", BLACK);
	Ps[1] = new Player("MEGAN", WHITE);
	b = new Board();
	fakeb = new Board();
	checkb = new Board();
	saveb = new Board();
	turn = 0;
}
Chess::Chess(ifstream& rdr)
{
	Ps[0] = new Player("TORY", BLACK);
	Ps[1] = new Player("MEGAN", WHITE);
	rdr >> turn;
	b = new Board(rdr);
	fakeb = new Board(rdr);
	checkb = new Board(rdr);
}
void Chess::display_turn_msg(Player* p)
{
	gotoRowCol(9, 100);
	cout << p->getname() << " 's Turn!!\n";
}
void Chess::select_piece()
{
	gotoRowCol(10, 100);
	cout << "Enter Desired Row and Col (SOURCE)" << endl;
	int rpos;
	int cpos;
	int brows = 10;
	int bcols = 10;

	getRowColbyLeftClick(rpos, cpos);
	this->sri = rpos / brows;
	this->sci = cpos / bcols;
}
void Chess::select_dest()
{
	gotoRowCol(10, 100);
	cout << "Enter Desired Row and Col (DESTINATION)" << endl;
	int rpos;
	int cpos;
	int brows = 10;
	int bcols = 10;

	getRowColbyLeftClick(rpos, cpos);
	this->dri = rpos / brows;
	this->dci = cpos / bcols;
}
	
void Chess::turn_change()
{
	turn = (turn + 1) % 2;
}
void Chess::play()
{
	while (true)
	{
		b->display_board();
		display_turn_msg(Ps[turn]);
		do
		{
			do
			{
				do
				{
					do
					{
						select_piece();
					} while (valid_source(Ps[turn], sri, sci) == false);
					bmap = compute_highlight(Ps[turn], sri, sci);
					b->highlight(bmap);
					select_dest();
				} while (valid_dest(Ps[turn], dri, dci) == false);
				b->unhighlight(bmap);
			} while (b->getpieceat(sri, sci)->is_legal(sri, sci, dri, dci) == false);
			fakeb->copy(b);
			fakeb->move(sri, sci, dri, dci);
		} while (self_check(fakeb));
		pawn_first();
		b->move(sri, sci, dri, dci);
		if (checkmate() == true)
		{
			b->display_board();
			gotoRowCol(8, 100);
			cout << "CHECKMATE!! GAME OVER :(" << " " << Ps[turn]->getname() << " WINS";
			exit(1);
		}
		if (dri == 0 || dri == 7)
		{
			SetClr(15);
			b->pawn_promote(dri,dci,turn);
		}
		if (checkmate() == true)
		{
			b->display_board();
			gotoRowCol(8, 100);
			cout << "CHECKMATE!! GAME OVER :(" << " " << Ps[turn]->getname() << " WINS";
			exit(1);
		}
		turn_change();
		save();
	}
}
void Chess::pawn_first()
{
	Piece* p = b->getpieceat(sri, sci);
	if (dynamic_cast<Pawn*>(p) != nullptr)
	{
		dynamic_cast<Pawn*>(p)->setcount();
	}
}

bool Chess::checkmate()
{
	int sr,sc;
	int dr,dc;

	int turn2 = (turn + 1) % 2;
	if (check(b) == true)
	{
		for (int r = 0; r < 8; r++)
		{
			for (int c = 0; c < 8; c++)
			{
				sr = r;
				sc = c;
				if (valid_source(Ps[turn2],sr,sc) == true)
				{
					for (int i = 0; i < 8; i++)
					{
						for (int j = 0; j < 8; j++)
						{
							dr = i;
							dc = j;
							if (valid_dest(Ps[turn2],dr,dc) == true && b->getpieceat(sr,sc)->is_legal(sr,sc,dr,dc) == true)
							{
								checkb->copy(b);
								checkb->move(sr, sc, dr, dc);
								if (check(checkb) == false)
								{
									return false;
								}
							}
						}
					}
				}

			}
		}
		return true;

	}
	else
	{
		return false;
	}
}
bool Chess::valid_source(Player* a,int r,int c)
{
	if (r < 0 || r >= 8 || c < 0 || c >= 8)
		return false;
	Piece* p = b->getpieceat(r, c);
	return (p != nullptr && p->getcolor() == a->getcolor());
}
bool Chess::valid_dest(Player* a, int r, int c)
{
	if(r < 0 || r >= 8 || c < 0 || c >= 8)
		return false;
	Piece* p = b->getpieceat(r, c);
	if (p == nullptr)
		return true;
	else
		return (p->getcolor() != a->getcolor());
}
bool** Chess::compute_highlight(Player* a,int sr,int sc)
{
	bool** bmap = new bool* [8];
	for (int i = 0; i < 8; i++)
	{
		bmap[i] = new bool[8] {};
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (valid_dest(a,i,j)==true&&b->getpieceat(sr,sc)->is_legal(sr,sc,i, j) == true )
			{
				bmap[i][j] = true;
			}
			else
			{
				bmap[i][j] = false;
			}
		}
	}
	return bmap;
}

void Chess::find_king(Player* a, Board* B,int& r,int& c)
{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				Piece* p = B->getpieceat(i, j);
				if (dynamic_cast<King*>(p) != nullptr && dynamic_cast<King*>(p)->getcolor() == a->getcolor())
				{
					r = i;
					c = j;
					return;
				}

			}
		}
	
}
bool Chess::check(Board* B)
{
	int dr, dc = 0;
	turn_change();
	find_king(Ps[turn],B,dr,dc);
	turn_change();

	int sr, sc = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			sr = i;
			sc = j;
			if (valid_source(Ps[turn],sr,sc)&& B->getpieceat(sr,sc)->is_legal(sr,sc,dr,dc)==true)
			{
				return true;
			}
		}
	}
	return false;

}
bool Chess::self_check(Board* B)
{
	turn_change();
	if (check(B) == true)
	{
		turn_change();
		return true;
	}
	else
	{
		turn_change();
		return false;
	}
}
void Chess::save()
{
	ofstream writer("State.txt");

	writer << turn << endl;

	for (int i = 0; i < 8; i++) 
	{
		for (int j = 0; j < 8; j++) 
		{
			Piece* piece = b->getpieceat(i,j);
			if (piece != nullptr)
			{
				char c = piece->getsym();
				if(piece->getcolor()==WHITE)
					writer << char(toupper(c)) << endl;
				else
					writer << (c) << endl;
			}
			else
			{
				writer << '0' << endl;
			}
		}
	}
}