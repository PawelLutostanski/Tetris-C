#include "structure.h"


void addToList(struct FigureLList** head, struct Block* data) // adding new node to a list
{
	struct FigureLList** tmp;
	tmp = head;
	while (*tmp)
	{
		tmp = &((*tmp)->next);
	}
	(*tmp) = (struct FigureLList*) malloc(sizeof(struct FigureLList));
	(*tmp)->next = NULL;
	(*tmp)->element= data;
}

void clearList(struct FigureLList** head) 
{
	
	struct FigureLList* tmp = *head;
	struct FigureLList* tmpNext;
	while (tmp)
	{
		tmpNext = tmp->next;
		free(tmp->element);
		free(tmp);
		tmp = tmpNext;
	}
	*head = 0;
}

struct Block* initBlock(int x, int y, char c) 
{
	struct Block* newBlock=(struct Block*) malloc(sizeof(struct Block)) ;
	newBlock->position.x = x;
	newBlock->position.y = y;
	newBlock->sym = c;
	return newBlock;
}