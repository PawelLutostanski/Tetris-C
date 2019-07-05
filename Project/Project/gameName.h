#pragma once
#include "menu.h"
/**
 *The function prints in console symbol X times in console
 * @param X- number of print repetions 
 * @param symbol- symbol printed
 */
void symbolXTimes(int X, char symbol);
/**
*Functions prints following rows of "tetris" made of other symbols 
*/
void row1Print();
void row2Print();
void row3Print();
void row4Print();
void row5Print();
/**
 *The function operates with other functions and displays word "tetris" made of other symbols 
 * @param col- collumn where is displayed first row
 * @param row- row is the space from left console output side 
 */
void displayGameName(int col, int row);