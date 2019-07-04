#pragma once
#include <stdio.h>
#include <stdlib.h>

/**
 *
 */
typedef struct Point
{
	int x;
	int y;
}coord;
/**
 *
 */
struct Block{
	coord position;
	char sym;
};
/**
 *
 */
struct FigureLList {
	struct Block* element;
	struct FigureLList* next;
};
/**
 *
 * @param head
 * @param data
 */
void add(struct FigureLList** head, struct Block* data);
/**
 *
 * @param head
 */
void clearList(struct FigureLList** head);
/**
 *
 * @param x
 * @param y
 * @param c
 * @return
 */
struct Block* initBlock(int x, int y, char c);


