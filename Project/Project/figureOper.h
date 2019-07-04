#pragma once
#include "setFigure.h"
/**
 *
 * @param arrayOfChars
 * @param head
 * @return
 */
int leftCheck(char arrayOfChars[Y_MAP][X_MAP], struct FigureLList *head);
/**
 *
 * @param arrayOfChars
 * @param head
 */
void allLeft(char arrayOfChars[Y_MAP][X_MAP],struct FigureLList **head);
/**
 *
 * @param arrayOfChars
 * @param head
 * @return
 */
int rightCheck(char arrayOfChars[Y_MAP][X_MAP], struct FigureLList *head);
/**
 *
 * @param arrayOfChars
 * @param head
 */
void allRight(char arrayOfChars[Y_MAP][X_MAP], struct FigureLList **head);
/**
 *
 * @param arrayOfChars
 * @param head
 * @return
 */
int checkBottom(char arrayOfChars[Y_MAP][X_MAP], struct FigureLList* head);
/**
 *
 * @param arrayOfChars
 * @param head
 * @return
 */
int bottomDown(char arrayOfChars[Y_MAP][X_MAP], struct FigureLList **head);
/**
 *
 * @param arrayOfChars
 * @param head
 * @param symbol
 */
void addAllBlocks (char arrayOfChars[Y_MAP][X_MAP], struct FigureLList **head, char symbol);