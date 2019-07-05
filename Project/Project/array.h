#pragma once
#include "structure.h"


#define X_MAP 18
#define Y_MAP 47
#define FALLEN_BLOCK -78
#define CONTROLED_BLOCK -79
/**
 *The function fills array
 * @param arrayOfChars array (given by pointer) is filled in proper way, frames and spaces
 */
void fillArray(char arrayOfChars[Y_MAP][X_MAP]);
/**
 *The function displays array
 * @param arrayOfChars- array is displayed
 */
void display(char arrayOfChars[Y_MAP][X_MAP]);
/**
 *The function adds character sym to array coordinates given by Block's points
 * @param arrayOfChars- array(given by pointer) to which we put Block
 * @param blo- Block but we use from it only Point's x and y
 * @param sym- symbol put in array
 */
void addPlayer(char arrayOfChars[Y_MAP][X_MAP], struct Block* blo,char sym);
/**
 *Function adds symbol to array coordinates x and y 
 *(the main difference between addPlayer is the fact thar add Point
 *don't require Block structure)
 * @param arrayOfChars- array(given by pointer) to which we put symbol
 * @param x- x coordinates
 * @param y- y coordinates
 * @param symbol-
 */
void addPoint(char arrayOfChars[Y_MAP][X_MAP], int x, int y,char symbol);
/**
 * deleteRow replaces row with spaces and then replace array cell with cell
 * "above", if it occure there '_' it replaces array with space
 * @param arrayOfChars- array(given by pointer) in which we delete row
 * @param whichRow- defines which row function deletes
 */
void deleteRow(char arrayOfChars[Y_MAP][X_MAP], int whichRow);
/**
 * checkRows checks rows and order to deletes rows filled with fallen figures
 * @param arrayOfChars-  array(given by pointer) in which we checks rows
 * @return - returs number of deleted rows
 */
int checkRows(char arrayOfChars[Y_MAP][X_MAP]);
/**
 *Adds line conisted of '_' to array
 * @param whichRow- defines in which row put line 
 * @param arrayOfChars-  array(given by pointer) in which we add line
 * @return- returns 1 if '_' will overwrite symbol of fig
 */
int addLine(int whichRow, char arrayOfChars[Y_MAP][X_MAP]);