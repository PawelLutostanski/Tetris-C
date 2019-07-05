#pragma once
#include "setFigure.h"
/**
 * Checks if there would occure collision with array symbols after moving figure left
 * @param arrayOfChars- array where symbols are
 * @param head- head of figure
 * @return 1 if no collision 0 is collision
 */
int leftCheck(char arrayOfChars[Y_MAP][X_MAP], struct FigureLList *head);
/**
 * Moves all blocks coords of figure left if there would not be collision
 * @param arrayOfChars- array for wich we leftCheck
 * @param head- pointer to head of figure
 */
void allLeft(char arrayOfChars[Y_MAP][X_MAP],struct FigureLList **head);
/**
* Checks if there would occure collision with array symbols after moving figure right
* @param arrayOfChars - array where symbols are
* @param head - head of figure
* @return 1 if no collision 0 is collision
 */
int rightCheck(char arrayOfChars[Y_MAP][X_MAP], struct FigureLList *head);
/**
 * Moves all blocks coords of figure right if there would not be collision
 * @param arrayOfChars- array for wich we rightCheck
 * @param head- head of figure */
void allRight(char arrayOfChars[Y_MAP][X_MAP], struct FigureLList **head);
/**
 * Checks if there would be collision with array symbols after moving figure down 
 * @param arrayOfChars- array of symbols
 * @param head- pointer to head of figure
 * @return returns 1 if there would be collision and 0 if not 
 */
int checkBottom(char arrayOfChars[Y_MAP][X_MAP], struct FigureLList* head);
/**
 * Operates with other "moving figure in array" functions and moves figure to one cell
 * down or all to save point ( X_MAP/2 , 0)
 * @param arrayOfChars- array of symbols
 * @param head- head of figure
 * @return
 */
int bottomDown(char arrayOfChars[Y_MAP][X_MAP], struct FigureLList **head);
/**
 * Add to symbol to array cells defined by Points of Blocks of Figure 
 * @param arrayOfChars-array 
 * @param head- pointer to head of figure
 * @param symbol- symbol added to array
 */
void addAllBlocks (char arrayOfChars[Y_MAP][X_MAP], struct FigureLList **head, char symbol);