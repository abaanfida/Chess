#include <iostream>
#include <conio.h>
#include "Chess.h"
#include <fstream>
using namespace std;

int main()
{
	ifstream rdr("State.txt");
	int mode;
	cout << "NEW  (1) OR CONTINUE (2) ??" << endl;
	cin >> mode;
	if (mode == 1)
	{
		Chess C;
		C.play();
		return _getch();
	}
	else
	{
		Chess C(rdr);
		C.play();
		return _getch();
	}
		
}
