#include "setFigure.h"

int findMinX(struct FigureLList** head)
{
	int minX=0;
	struct FigureLList**temp = head;
	while(*temp)
	{
		if((*temp)->element->position.x<minX)
		{
			minX = (*temp)->element->position.x;
		}
		temp = &((*temp)->next);
	}
	return minX;
}

int findMinY(struct FigureLList** head)
{
	int minY=0;
	struct FigureLList**temp = head;
	while (*temp)
	{
		if ((*temp)->element->position.y < minY)
		{
			minY = (*temp)->element->position.y;
		}
		temp = &((*temp)->next);
	}
	return minY;
}

void moveBlockaByXY(struct FigureLList** head, int xMore, int yMore)
{
	struct FigureLList**temp = head;
	while (*temp)
	{
		(*temp)->element->position.x += xMore;
		(*temp)->element->position.y+=yMore;
		temp = &((*temp)->next);
	}
}

void randomFigure(struct FigureLList** head, int difficulty)
{
	srand(time(NULL));

	int posX =0;
	int posY = 0;
	char symbol = CONTROLED_BLOCK;
	struct Block* newBlock=initBlock(posX,posY, CONTROLED_BLOCK);//initialisation
	addToList(head, newBlock);//at least 1 block
	int blocksOfFigure = (rand() % (difficulty*2))+1;//at least 2 
	if(blocksOfFigure>((X_MAP/2)-2))
	{
		blocksOfFigure = (X_MAP / 2 - 2)-(rand()%3);//to prevent overlaping with frame
	}
	while (blocksOfFigure>0)
	{
		
		int direction = rand() % 4;
		if (direction == 0)//up
		{
			posY--;
		}
		else if (direction == 1)//right
		{
			posX++;
		}
		else if (direction == 2)//down
		{
			posY++;
		}
		else if (direction == 3)//left 
		{
			posX--;
		}
		newBlock=initBlock(posX, posY, CONTROLED_BLOCK);
		addToList(head, newBlock);

		blocksOfFigure--;
	}
	moveBlockaByXY(head, -findMinX(head)+X_MAP/2-1, -findMinY(head));// min is always smaller or equeal 0 thats why '-' before values
}
