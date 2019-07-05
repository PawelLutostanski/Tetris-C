#include "gameName.h"

void symbolXTimes(int X, char symbol)
{
	int i;
	for (i = 0; i < X; i++)
	{
		printf("%c", symbol);
	}
}

void row1Print()
{
	symbolXTimes(8, -37);
	printf("  ");
	symbolXTimes(8, -37);
	printf("  ");
	symbolXTimes(8, -37);
	printf("  ");
	symbolXTimes(8, -37);
	printf("  ");
	symbolXTimes(4, -37);
	printf("  ");
	symbolXTimes(8, -37);
}

void row2Print()
{
	symbolXTimes(3, ' ');
	symbolXTimes(2, -37);
	symbolXTimes(5, ' ');
	symbolXTimes(2, -37);
	symbolXTimes(11, ' ');
	symbolXTimes(2, -37);
	symbolXTimes(5, ' ');
	symbolXTimes(2, -37);
	symbolXTimes(4, ' ');
	symbolXTimes(2, -37);
	symbolXTimes(3, ' ');
	symbolXTimes(2, -37);
	symbolXTimes(3, ' ');
	symbolXTimes(2, -37);
}

void row3Print()
{
	symbolXTimes(3, ' ');
	symbolXTimes(2, -37);
	symbolXTimes(5, ' ');
	symbolXTimes(8, -37);
	symbolXTimes(5, ' ');
	symbolXTimes(2, -37);
	symbolXTimes(5, ' ');
	symbolXTimes(8, -37);
	symbolXTimes(3, ' ');
	symbolXTimes(2, -37);
	symbolXTimes(3, ' ');
	symbolXTimes(8, -37);
}

void row4Print()
{
	symbolXTimes(3, ' ');
	symbolXTimes(2, -37);
	symbolXTimes(5, ' ');
	symbolXTimes(2, -37);
	symbolXTimes(11, ' ');
	symbolXTimes(2, -37);
	symbolXTimes(5, ' ');
	symbolXTimes(2, -37);
	symbolXTimes(3, ' ');
	symbolXTimes(2, -37);
	symbolXTimes(4, ' ');
	symbolXTimes(2, -37);
	symbolXTimes(9, ' ');
	symbolXTimes(2, -37);
}

void row5Print()
{
	symbolXTimes(3, ' ');
	symbolXTimes(2, -37);
	symbolXTimes(5, ' ');
	symbolXTimes(8, -37);
	symbolXTimes(5, ' ');
	symbolXTimes(2, -37);
	symbolXTimes(5, ' ');
	symbolXTimes(2, -37);
	symbolXTimes(4, ' ');
	symbolXTimes(2, -37);
	symbolXTimes(2, ' ');
	symbolXTimes(4, -37);
	symbolXTimes(2, ' ');
	symbolXTimes(8, -37);
}	

void displayGameName(int col, int row)
{
	//1st row
	gotoxy(col, row);
	row1Print();

	//2nd row
	gotoxy(col, row + 1);
	row2Print();

	//3rd row
	gotoxy(col, row + 2);
	row3Print();

	//4th row
	gotoxy(col, row + 3);
	row4Print();

	//5th row
	gotoxy(col, row + 4);
	row5Print();
	
}