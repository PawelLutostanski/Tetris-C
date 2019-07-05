#pragma once
#include"array.h"
#include <time.h>

/**
 *Find minimal x coordinate of figure
 * @param head- pointer to head of figure
 * @return minimal x coordinate
 */
int findMinX(struct FigureLList** head);

/**
 **Find minimal y coordinate of figure
 * @param head- pointer to head of figure
 * @return minimal y coordinate
 */
int findMinY(struct FigureLList** head);
/**
 * Moves each figure Block by given parameters
 * @param head- pointer to head of figure
 * @param xMore- move each x coordinate by xMore
 * @param yMore- move y coordinate by yMore
 */
void moveBlockaByXY(struct FigureLList** head, int xMore, int yMore);
/**
 * Creates random figure (list of blocks), each block of point (x,y) have next block which point (x+/-1,y+/-1) 
 * @param head- pointer to head of figure (figure should be cleared previously
 * @param difficulty- the higher it is the more big figures appear
 */
void randomFigure(struct FigureLList** head, int difficulty);