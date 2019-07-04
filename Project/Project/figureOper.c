#include "figureOper.h"

int leftCheck(char arrayOfChars[Y_MAP][X_MAP], struct FigureLList *head)
{
	int value = 1;
	while (head) {
		int xCoord = head->element->position.x;
		int yCoord = head->element->position.y;
		if (arrayOfChars[yCoord][xCoord - 1] == NICE_SYMBOL || arrayOfChars[yCoord][xCoord-1]== -37)//-37 is side frame
		{
			value = 0;
			break;
		}
		head = head->next;
	}
	return value;

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
	int value = 1;
	while (head) {
		int xCoord = head->element->position.x;
		int yCoord = head->element->position.y;
		if (arrayOfChars[yCoord][xCoord + 1] == NICE_SYMBOL || arrayOfChars[yCoord-1][xCoord+1] == -37)//-37 is side frame
		{
			value = 0;
			break;
		}
		head = head->next;
	}
	return value;

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
	int collision_bool = 0;
	while (head)
	{
		if (head->element->position.y+1 == Y_MAP - 1 || arrayOfChars[head->element->position.y+1][head->element->position.x] == NICE_SYMBOL) {
			collision_bool = 1;
		}
		head = head->next;
	}
	return collision_bool;
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
			addPoint(&arrayOfChars[0][0], coordX, coordY, NICE_SYMBOL);
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