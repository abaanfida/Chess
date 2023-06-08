#include "Board.h"
#include "Pawn.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Queen.h"
#include "Rook.h"
#include "Utility.h"
#include <iostream>
#include <fstream>
using namespace std;

Board::Board()
{
	ps = new Piece **[8];
	for (int i = 0; i < 8; i++)
	{
		ps[i] = new Piece * [8];
		for (int j = 0; j < 8; j++)
		{
			if (i == 0)
			{
				if (j == 0 || j==7)
				{
					ps[i][j] = new Rook(i, j, WHITE, this);
				}
				else if (j == 1||j==6)
			    {
					ps[i][j] = new Knight(i, j, WHITE, this);
				}
				else if (j == 2||j==5)
				{
					ps[i][j] = new Bishop(i, j, WHITE, this);
				}
				else if (j == 3)
				{
					ps[i][j] = new Queen(i, j, WHITE, this);
				}
				else if (j == 4)
				{
					ps[i][j] = new King(i, j, WHITE, this);
				}
			}
			else if (i == 1)
			{
				ps[i][j] = new Pawn(i, j, WHITE, this);
			}
			else if (i == 6)
			{
				ps[i][j] = new Pawn(i, j, BLACK, this);
			}
			else if (i == 7)
			{
				if (j == 0 || j == 7)
				{
					ps[i][j] = new Rook(i, j, BLACK, this);
				}
				else if (j == 1 || j == 6)
				{
					ps[i][j] = new Knight(i, j, BLACK, this);
				}
				else if (j == 2 || j == 5)
				{
					ps[i][j] = new Bishop(i, j, BLACK, this);
				}
				else if (j == 3)
				{
					ps[i][j] = new Queen(i, j, BLACK, this);
				}
				else if (j == 4)
				{
					ps[i][j] = new King(i, j, BLACK, this);
				}
			}
			else
			{
				ps[i][j] = nullptr;
			}
		}
	}
}
Board::Board(ifstream& rdr)
{
	char c;
	ps = new Piece * *[8];
	for (int i = 0; i < 8; i++)
	{
		ps[i] = new Piece * [8];
		for (int j = 0; j < 8; j++)
		{
			rdr >> c;
			if (c == 'R' || c == 'r')
			{
				if (c == 'R')
					ps[i][j] = new Rook(i, j, WHITE, this);
				else
					ps[i][j] = new Rook(i, j, BLACK, this);
			}
			else if (c == 'B' || c == 'b')
			{
				if (c == 'B')
					ps[i][j] = new Bishop(i, j, WHITE, this);
				else
					ps[i][j] = new Bishop(i, j, BLACK, this);
			}
			else if (c == 'N' || c == 'n')
			{
				if (c == 'N')
					ps[i][j] = new Knight(i, j, WHITE, this);
				else
					ps[i][j] = new Knight(i, j, BLACK, this);
			}
			else if (c == 'Q' || c == 'q')
			{
				if (c == 'Q')
					ps[i][j] = new Queen(i, j, WHITE, this);
				else
					ps[i][j] = new Queen(i, j, BLACK, this);
			}
			else if (c == 'K' || c == 'k')
			{
				if (c == 'K')
					ps[i][j] = new King(i, j, WHITE, this);
				else
					ps[i][j] = new King(i, j, BLACK, this);
			}
			else if (c == 'P' || c == 'p')
			{
				if (c == 'P')
					ps[i][j] = new Pawn(i, j, WHITE, this);
				else
					ps[i][j] = new Pawn(i, j, BLACK, this);
			}
			else
			{
				ps[i][j] = nullptr;
			}

		}
	}
}
void draw_box(int sr, int sc, int brows, int bcols, int color)
{
	for (int r = 0; r < brows; r++)
	{
		for (int c = 0; c < bcols; c++)
		{
			SetClr(color);
			gotoRowCol(sr + r, sc + c);
			cout << char(-37);
		}
	}
	SetClr(15);
}
void Board::display_board()
{
	int brows = 10;
	int bcols = 10;
	system("cls");
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((i + j) % 2 == 0)
			{
				draw_box(i * brows, j * bcols, brows, bcols, 9);
				gotoRowCol(i * brows + brows / 2, j * bcols + bcols / 2);
				if (ps[i][j] != nullptr)
				{
					ps[i][j]->draw(i * brows + brows / 2, j * bcols + bcols / 2);
				}
				

			}
			else
			{

				draw_box(i * brows, j * bcols,brows,bcols, 11);
				gotoRowCol(i * brows + brows / 2, j * bcols + bcols / 2);
				if (ps[i][j] != nullptr)
				{
					ps[i][j]->draw(i * brows + brows / 2, j * bcols + bcols / 2);
				}
			}
		}
	}
	SetClr(15);
}
void Board::highlight(bool** m)
{
	int brows = 10, bcols = 10;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (m[i][j] == true)
			{
				if (ps[i][j] == nullptr)
				{
					draw_box(i * brows, j * bcols, brows, bcols, 2);
				}
				else
				{
					draw_box(i * brows, j * bcols, brows, bcols, 4);
					ps[i][j]->draw(i * brows + brows / 2, j * bcols + bcols / 2);

				}
			}

		}
	}
}
void Board::unhighlight(bool** m)
{
	int brows = 10, bcols = 10;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (m[i][j] == true)
			{
				if ((i + j) % 2 == 0)
				{
					draw_box(i * brows, j * bcols, brows, bcols, 9);
				}
				else
				{
					draw_box(i * brows, j * bcols, brows, bcols, 11);

				}
				if (ps[i][j] != nullptr)
				{
					ps[i][j]->draw(i* brows + brows / 2, j* bcols + bcols / 2);
				}
			}
		}
	}
}
Piece* Board::getpieceat(int r,int c)
{
	return ps[r][c];
}
void Board::move(int sr, int sc, int dr, int dc)
{
	ps[dr][dc] = ps[sr][sc];
	ps[sr][sc] = nullptr;
}
bool Board::is_horizontal_move(int sr, int sc, int dr, int dc)
{
	return sr == dr;
}
bool Board::is_vertical_move(int sr, int sc, int dr, int dc)
{
	return sc == dc;
}
bool Board::is_diagonal_move(int sr, int sc, int dr, int dc)
{
	return  abs(sr - dr) == abs(sc - dc);
}
bool Board::is_horizontal_clear(int sr, int sc, int dr, int dc)
{
	if (sc < dc)
	{
		for (int i = sc + 1; i < dc; i++)
		{
			if (ps[sr][i] !=nullptr)
			{
				return false;
			}
		}
	}
	else
	{
		for (int i = sc - 1; i > dc; i--)
		{
			if (ps[sr][i] != nullptr)
			{
				return false;
			}
		}
	}
	return true;
}
bool Board::is_vertical_clear(int sr, int sc, int dr, int dc)
{
	if (sr < dr)
	{
		for (int i = sr + 1; i < dr; i++)
		{
			if (ps[i][sc] != nullptr)
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		for (int i = sr - 1; i > dr; i--)
		{
			if (ps[i][sc] != nullptr)
			{
				return false;
			}
		}
		return true;
	}
}
bool Board::is_diagonal_L2R_clear(int sr, int sc, int dr, int dc)
{
	if (sr<dr)
	{
		for (int i = sr+1,j=sc+1; i < dr; i++,j++)
		{
			if (ps[i][j] != nullptr)
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		for (int i = dr + 1, j = dc - 1; i < sr; i++, j--)
		{
			if (ps[i][j] != nullptr)
			{
				return false;
			}
		}
		return true;
	}
}
bool Board::is_diagonal_R2L_clear(int sr, int sc, int dr, int dc)
{
	if (sr > dr)
	{
		for (int i = dr + 1, j = dc + 1; i < sr; i++,j++)
		{
			if (ps[i][j] != nullptr)
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		for (int i = dr - 1, j = dc + 1; i > sr; i--, j++)
		{
			if (ps[i][j] != nullptr)
			{
				return false;
			}
		}
		return true;
	}
}
void Board::copy(Board* b)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (b->ps[i][j] != nullptr)
				ps[i][j] = b->getpieceat(i, j);
			else
				ps[i][j] = nullptr;
		}
	}
}


void Board::pawn_promote(int dr,int dc,int turn)
{
	int choice;
	if (turn == BLACK)
	{
		if (dynamic_cast<Pawn*>(ps[dr][dc]) != nullptr && dr == 0)
		{
			gotoRowCol(9, 100);
			cout << "CHOOSE PIECE TO PROMOTE TO";
			gotoRowCol(10, 100);
			cout << "1 FOR QUEEN";
			gotoRowCol(11, 100);
			cout << "2 FOR KNIGHT";
			gotoRowCol(12, 100);
			cout << "3 FOR BISHOP";
			gotoRowCol(13, 100);
			cout << "4 FOR ROOK";
			gotoRowCol(14, 100);
			cin >> choice;
			switch (choice)
			{
			case 1:
				delete[]ps[dr][dc];
				ps[dr][dc] = new Queen(dr, dc, BLACK, this);
				break;
			case 2:
				delete[]ps[dr][dc];
				ps[dr][dc] = new Knight(dr, dc, BLACK, this);
				break;
			case 3:
				delete[]ps[dr][dc];
				ps[dr][dc] = new Bishop(dr, dc, BLACK, this);
				break;
			case 4:
				delete[]ps[dr][dc];
				ps[dr][dc] = new Rook(dr, dc, BLACK, this);
				break;
			}
		}
	}
	else
	{
		if (dynamic_cast<Pawn*>(ps[dr][dc]) != nullptr && dr == 7)
		{
			gotoRowCol(9, 100);
			cout << "CHOOSE PIECE TO PROMOTE TO";
			gotoRowCol(10, 100);
			cout << "1 FOR QUEEN";
			gotoRowCol(11, 100);
			cout << "2 FOR KNIGHT";
			gotoRowCol(12, 100);
			cout << "3 FOR BISHOP";
			gotoRowCol(13, 100);
			cout << "4 FOR ROOK";
			gotoRowCol(14, 100);
			cin >> choice;
			switch (choice)
			{
			case 1:
				delete[]ps[dr][dc];
				ps[dr][dc] = new Queen(dr, dc, WHITE, this);
			case 2:
				delete[]ps[dr][dc];
				ps[dr][dc] = new Knight(dr, dc, WHITE, this);
			case 3:
				delete[]ps[dr][dc];
				ps[dr][dc] = new Bishop(dr, dc, WHITE, this);
			case 4:
				delete[]ps[dr][dc];
				ps[dr][dc] = new Rook(dr, dc, WHITE, this);
			}
		}
	}


}
