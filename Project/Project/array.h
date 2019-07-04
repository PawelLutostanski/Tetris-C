#pragma once
#include "structure.h"


#define X_MAP 18
#define Y_MAP 47
#define NICE_SYMBOL -78
#define FINE_SYMBOL -79
/**
 *
 * @param arrayOfChars
 */
void fillArray(char arrayOfChars[Y_MAP][X_MAP]);
/**
 *
 * @param arrayOfChars
 */
void display(char arrayOfChars[Y_MAP][X_MAP]);
/**
 *
 * @param arrayOfChars
 * @param blo
 * @param sym
 */
void addPlayer(char arrayOfChars[Y_MAP][X_MAP], struct Block* blo,char sym);
/**
 *
 * @param arrayOfChars
 * @param x
 * @param y
 * @param symbol
 */
void addPoint(char arrayOfChars[Y_MAP][X_MAP], int x, int y,char symbol);
/**
 *
 * @param arrayOfChars
 * @param whichRow
 */
void deleteRow(char arrayOfChars[Y_MAP][X_MAP], int whichRow);
/**
 *
 * @param arrayOfChars
 * @param symbol
 * @return
 */
int checkRows(char arrayOfChars[Y_MAP][X_MAP],char symbol);
/**
 *
 * @param whichRow
 * @param arrayOfChars
 * @return
 */
int addLine(int whichRow, char arrayOfChars[Y_MAP][X_MAP]);