#include "game.h"

void gotoxy(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), coord
	);
}

int points(int addThem, char whatToDo)
{
	static int points = 0;
	if (whatToDo=='a')//a - add
	{
		points += addThem;
	}
	else if (whatToDo=='r')//r-reset
	{
		points = 0;
	}
	return points;
}

void displayScore(int score)
{

	gotoxy(4*X_MAP , 5);
	printf("SCORE : %d", score);
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
	while (c != '\r') 
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

int game(int dif) {
	
	struct FigureLList *figure = NULL;
	randomFigure(&figure, dif);
	char gameMap[Y_MAP][X_MAP];
	fillArray(&gameMap);

	displayScore(points(0,'r'));
	char  state = NULL;
	while (1) {
		if (addLine(Y_MAP / 5 +2, &gameMap))
		{
			clearList(&figure);
			fail();
			return points(0,'a'); //return to menu
		}
		addAllBlocks(&gameMap, &figure, FINE_SYMBOL);// add figure to array
		gotoxy(0, 0);
		display(gameMap);
		addAllBlocks(&gameMap, &figure, ' ');// clear figure from array
		state = _getch();//taking char from input stream
		int move = 0;
		if (state == 'a' || state == 'A' || state == 75)//a and A(in case of capslk) and left arrow  keys
		{
			move = 1;
			allLeft(&gameMap, &figure);
		}
		else if (state == 'd' || state == 'D' || state == 77)//d and D(in case of capslk) and right keys
		{
			move = 1;
			allRight(&gameMap, &figure);
		}
		else if (state == '`' || state == '~' || state == 27) //tilde or  esc
		{
			clearList(&figure);
			
			return points(0,'a');
		}
		else if (state == 80 || state == 72||state=='w' ||state =='W' || state == 's' || state == 'S')
		{
			move = 1;
		}
		if (move)
		{
			if (bottomDown(&gameMap, &figure)) {//check colision(if there is the fill wtih NICE_SYMBOL)
				clearList(&figure);
				int val = checkRows(&gameMap, NICE_SYMBOL);
				if (val)
				{
					displayScore(points(100 * val*val, 'a')); // squre of deleted rows times 100
				}
				randomFigure(&figure, dif);
			}
		}
	}
}