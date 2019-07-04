#pragma once
#include"array.h"
#include"structure.h"
#include <time.h>

/**
 *
 * @param head
 * @return
 */
int findMinX(struct FigureLList** head);

/**
 *
 * @param head
 * @return
 */
int findMinY(struct FigureLList** head);
/**
 *
 * @param head
 * @param xMore
 * @param yMore
 */
void moveBlockaByXY(struct FigureLList** head, int xMore, int yMore);
/**
 *
 * @param head
 * @param difficulty
 */
void randomFigure(struct FigureLList** head, int difficulty);