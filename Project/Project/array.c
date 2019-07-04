#include"array.h"

void fillArray(char arrayOfChars[Y_MAP][X_MAP]) 
{
	int i;

	for (i = 0; (i < Y_MAP); i++)
	{
		int j;
		for (j = 0; j < X_MAP; j++)
		{
			if (i == Y_MAP - 1)
			{
				arrayOfChars[i][j] = -33;//lower side frame
			}
			else if (j == 0 || j == X_MAP - 1)//doing left and right side frames
			{
				arrayOfChars[i][j] = -37;
			}
			else 
			{
				arrayOfChars[i][j] = ' ';
			}
		}

	}
}

void display(char arrayOfChars[Y_MAP][X_MAP]) 
{	
	int i;
	printf("\t\t\t");
	for (i = 0; i < Y_MAP; i++)
	{
		int j;
		for (j = 0; j < X_MAP; j++)
		{
			int k;
			if (j != 0 && j != X_MAP - 1) 
			{
				for (k = 0; k < 2; k++)
				{
					printf("%c", arrayOfChars[i][j]);//to make char==-76 square like char
				}
			}
			else{ printf("%c", arrayOfChars[i][j]); }
		}
		if(i!=Y_MAP-1){
		printf("\n\t\t\t");}
	}
}

void addPlayer(char arrayOfChars[Y_MAP][X_MAP], struct Block* blo, char sym) 
{
	arrayOfChars[blo->position.y][blo->position.x] = sym;
}

void addPoint(char arrayOfChars[Y_MAP][X_MAP], int x,int y,char symbol)
{
	arrayOfChars[y][x] = symbol;
}

void deleteRow(char arrayOfChars[Y_MAP][X_MAP],int whichRow) 
{
	int x;
	int y;
	for (x = 1; x < X_MAP-1; x++) {
			arrayOfChars[whichRow][x] = ' ';
	}
	for (y = whichRow - 1; y >Y_MAP / 5-1; y--) {
		for (x = 1; x < X_MAP - 1; x++) {
			if(arrayOfChars[y][x]!='_') arrayOfChars[y+1][x] = arrayOfChars[y][x];
			else arrayOfChars[y + 1][x] = ' ';
		}
	}
}
int checkRows(char arrayOfChars[Y_MAP][X_MAP], char symbol) 
{
	int rowFullcount = 0;
	int i;
	for (i = 0; i < Y_MAP-1; i++) 
	{
		int j;
		int counterOfFilled = 0;
		for (j = 1; j < X_MAP-1; j++) 
		{
			if (arrayOfChars[i][j]!=' '&&arrayOfChars[i][j] != '_') 
			{
				counterOfFilled++;
			}
		}
		if (counterOfFilled >= X_MAP -2) 
		{
			deleteRow(&arrayOfChars[0][0], i);
			rowFullcount++;
		}
	}
	return rowFullcount;
}
int addLine(int whichRow, char arrayOfChars[Y_MAP][X_MAP])
{
	int fail=0;
	int i;
	for (i = 1; i < X_MAP-1; i++)
	{
		if (arrayOfChars[whichRow][i] == NICE_SYMBOL)
		{
			fail=1;//fail game
		}
		else
		{
			arrayOfChars[whichRow][i] = '_';
		}
	}
	return fail;
}
