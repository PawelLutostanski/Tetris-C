#include "menu.h"
#include "gameName.h"

int whichChoice(char c,int max)
{

	static int choiceVal = 0;
	if (c == 'w'||c=='W'||c== 72|| c== 'd' || c == 'D' || c == 77)
	{
		choiceVal--;
	}
	else if (c=='s'||c=='S'||c==80|| c == 'a' || c == 'A' || c == 75)//s or down
	{
		choiceVal++;
	}
	if (choiceVal < 0) {
		choiceVal = max;
	}
	else if (choiceVal > max) 
	{
		choiceVal = 0;
	}
	return choiceVal;
}

int selectDiff(char key)
{
	int val;
	while (1)
	{
		gotoxy(40, 13);
		printf("%c SELECT DIFFICULTY:            ", -81);
		gotoxy(65, 13);
		val = (6 - whichChoice(key,5));
		symbolXTimes(val, -8);
		gotoxy(73, 13);
		printf("| %d   ", val);
		key = _getch();
		if (key == ' ' || key == '\r') { return val; }
		if (key == '`' || key == '~' || key == 27) { return -1; }
	}
}

void displayMenu(int whereAsterix)
{
	gotoxy(0, 13);
	printf("\t      NEW GAME\n\n");
	printf("\t      LEADERBOARD\n\n");
	printf("\t      EXIT\n\n");
	gotoxy(10, 13 + whereAsterix*2);

	printf("%c",-81);
}

