#pragma once
#include <stdio.h>
#include <stdlib.h>

/**
 * Cartesian coordinte system's point (x,y)
 */
typedef struct Point
{
	int x;
	int y;
};
/**
 * Block is defined as point with symbol
 */
struct Block{
	struct Point position;
	char sym;
};
/**
 *FigureLList is Linked List of Blocks
 */
struct FigureLList {
	struct Block* element;
	struct FigureLList* next;
};
/**
 * appends Block to figure
 * @param head- pointer to head of figure
 * @param data- pointer to Block 
 */
void addToList(struct FigureLList** head, struct Block* data);
/**
 * frees memory where nodes and their elements were allocated, then set head to NULL
 * @param head-pointer to head of figure
 */
void clearList(struct FigureLList** head);
/**
 * Creates new Block and allocate memory for it
 * @param x- x coordinate of Point of Block
 * @param y- y coordinate of Point of Block
 * @param c- symbol of Block
 * @return pointer to new block
 */
struct Block* initBlock(int x, int y, char c);


