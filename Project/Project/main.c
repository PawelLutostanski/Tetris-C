#include "menu.h"
#include "gameName.h"

int main() 
{
	char key;
	displayMenu(0);
	gotoxy(X_MAP + 45, 7);
	printf("  made by Pawel Lutostanski");
	while (1)
	{	
		int i = 5;
		displayGameName(X_MAP / 3, 3);
		key = _getch();
		int command =whichChoice(key,2);
		if (key==27)// esc
		{
			return 0;
		}
		if (key == ' '|| key == '\r')//space or enter
		{
			if (command == 0)
			{
				int val = selectDiff(key);
				if(val==-1){}
				else 
				{
					system("cls");
					char name[15];
					gotoxy(10, 10);
					printf("ENTER YOUR NAME: \n\tmaximal name length is 14 letters, the rest of letters will be ignored\n");
					gotoxy(27, 10);
					fgets(name, 15, stdin);
					printf("\n\n\t\t Press ESCAPE to return to menu or ANY OTHER KEY to contiunue ");
					key=_getch();
					system("cls");
					if (key != 27)// no esc
					{
						int points = game(val);
						savingScore(&name, points);
					}
				}
				system("cls");
			}
			else if (command == 1)
			{
				showLeaderboard(10, 10);
				key = _getch();
				while (key != '\r'&&key!=27&&key!=' ') {
					key = _getch();
				}
				system("cls");
			}
			else if (command == 2)
			{
				return 0;
			}
		}
		Sleep(300);
		displayMenu(command);
	}
	return 0;
}