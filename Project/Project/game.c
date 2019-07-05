#include "game.h"

void gotoxy(int column, int row)
{
	COORD coord;
	coord.X = column;
	coord.Y = row;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), coord
	);
}

int points(int addThem, char mode)
{
	static int points = 0;
	if (mode=='a')//a - add
	{
		points += addThem;
	}
	else if (mode=='r')//r-reset
	{
		points = 0;
	}
	return points;
}

void displayScore(int score)
{

	gotoxy(4*X_MAP , 5);
	printf("SCORE : %10d", score);
}

int fail() {
	int i;
	for (i = 14; i < 22; i++)
	{
		gotoxy(25, i);
		printf("                                ");
	}
	gotoxy(35, 15);
	printf("  YOU FAILED  ");
	gotoxy(34, 17);
	printf("  YOUR SCORE:%d", points(0, 'a'));
	gotoxy(25, 20);
	printf(" Press ENTER to return to menu\n");
	Sleep(3000);
	char c = _getch();
	while (c != '\r'&&c!=' ') 
	{
		gotoxy(25, 20);
		printf("                               ");
		Sleep(200);
		gotoxy(25, 20);
		printf(" Press ENTER to return to menu\n");
		Sleep(200);
		c = _getch();
	}
	return 0;

}

int game(int difficulty) {
	
	struct FigureLList *figure = NULL;
	randomFigure(&figure, difficulty);
	char gameMap[Y_MAP][X_MAP];
	fillArray(&gameMap);

	displayScore(points(0,'r'));
	char  key = NULL;
	while (1) {
		if (addLine(Y_MAP / 5 +2, &gameMap))
		{
			clearList(&figure);
			fail();
			return points(0,'a'); //return to menu
		}
		addAllBlocks(&gameMap, &figure, CONTROLED_BLOCK);// add figure to array
		gotoxy(0, 0);
		display(gameMap);
		addAllBlocks(&gameMap, &figure, ' ');// clear figure from array
		key = _getch();//taking char from input stream
		int move = 0;
		if (key == 'a' || key == 'A' || key == 75)//a and A(in case of capslk) and left arrow  keys
		{
			move = 1;
			allLeft(&gameMap, &figure);
		}
		else if (key == 'd' || key == 'D' || key == 77)//d and D(in case of capslk) and right keys
		{
			move = 1;
			allRight(&gameMap, &figure);
		}
		else if ( key == 27) //tilde or  esc
		{
			clearList(&figure);
			fail();
			return points(0,'a');
		}
		else if (key == 80 || key == 72||key=='w' ||key =='W' || key == 's' || key == 'S')
		{
			move = 1;
		}
		if (move)
		{
			if (bottomDown(&gameMap, &figure)) {//check colision(if there is the fill wtih NICE_SYMBOL)
				clearList(&figure);
				int val = checkRows(&gameMap);
				if (val)
				{
					displayScore(points(100 * val*val, 'a')); // squre of deleted rows times 100
				}
				randomFigure(&figure, difficulty);
			}
		}
	}
}