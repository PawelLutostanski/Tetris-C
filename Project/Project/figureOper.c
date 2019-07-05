#include "figureOper.h"

int leftCheck(char arrayOfChars[Y_MAP][X_MAP], struct FigureLList *head)
{
	int noCollision = 1;
	while (head) {
		int xCoord = head->element->position.x;
		int yCoord = head->element->position.y;
		if (arrayOfChars[yCoord][xCoord - 1] == FALLEN_BLOCK || arrayOfChars[yCoord][xCoord-1]== -37)//-37 is side frame
		{
			noCollision = 0;
			break;
		}
		head = head->next;
	}
	return noCollision;

}
void allLeft(char arrayOfChars[Y_MAP][X_MAP], struct FigureLList **head)
{
	if (leftCheck(&arrayOfChars[0][0], *head)) {
		struct FigureLList**temp = head;
		while (*temp)
		{
			(*temp)->element->position.x--;
			temp = &(*temp)->next;
		}
	}
}

int rightCheck(char arrayOfChars[Y_MAP][X_MAP], struct FigureLList *head)
{
	int noColision = 1;
	while (head) {
		int xCoord = head->element->position.x;
		int yCoord = head->element->position.y;
		if (arrayOfChars[yCoord][xCoord + 1] == FALLEN_BLOCK || arrayOfChars[yCoord-1][xCoord+1] == -37)//-37 is side frame
		{
			noColision = 0;
			break;
		}
		head = head->next;
	}
	return noColision;

}
void allRight(char arrayOfChars[Y_MAP][X_MAP], struct FigureLList **head)
{
	if (rightCheck(&arrayOfChars[0][0], *head)) {
		struct FigureLList**temp = head;
		while (*temp)
		{
			(*temp)->element->position.x++;
			temp = &(*temp)->next;
		}
	}
}
int checkBottom(char arrayOfChars[Y_MAP][X_MAP], struct FigureLList* head)
{
	int collision = 0;
	while (head)
	{
		if (head->element->position.y+1 == Y_MAP - 1 || arrayOfChars[head->element->position.y+1][head->element->position.x] == FALLEN_BLOCK) {
			collision = 1;
		}
		head = head->next;
	}
	return collision;
}

int bottomDown(char arrayOfChars[Y_MAP][X_MAP], struct FigureLList **head)
{
	int value = 0;
	int collision = checkBottom(&arrayOfChars[0][0], *head);
	struct FigureLList** temp = head;
	while (*temp)
	{
		
		int coordX = (*temp)->element->position.x;
		int coordY = (*temp)->element->position.y;
		if (collision)
		{
			addPoint(&arrayOfChars[0][0], coordX, coordY, FALLEN_BLOCK);
			(*temp)->element->position.y = 0;//set to begining
			(*temp)->element->position.x = X_MAP / 2;
		
		}
		else 
		{
			(*temp)->element->position.y++;
		}
		temp = &((*temp)->next);
	}
	return collision;
}

void addAllBlocks(char arrayOfChars[Y_MAP][X_MAP], struct FigureLList **head, char symbol)
{
	struct FigureLList** temp = head;
	while (*temp)
	{
		addPlayer(&arrayOfChars[0][0],(*temp)->element, symbol);
		temp = &((*temp)->next);
	}
}