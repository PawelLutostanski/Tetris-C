#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "figureOper.h"
#include "file.h"
#include <conio.h>
#include <Windows.h>

/**
 * The function is used to move the cursor to the desire position in console.
 * @param column- to which column move cursor
 * @param row- to which row move cursor
 */
void gotoxy(int column, int row);
/**
 * points performs operation on static integer depending on mode
 * @param- addThem nubmer which is added in add mode
 * @param- mode if it is 'a' that means operates in add mode and adds addThem to pool, if 'r' resets static variable
 * @return- returns static integer after mode operations
 */ 
int points(int addThem,char mode);
/**
 * The function displays "SCORE:" and argument of function
 * @param score- this variable is displayed
 */
void displayScore(int score);
/**
 * fail displays fail message and waits till player press Enter
 * @return- it is always 0
 */
int fail();
/**
 * game operates with other functions responible for game (figure operations, displaying etc.)
 * @param difficulty- defines difficulty, the higher it is the more big figures appear 
 * @return- returns number of points right before exit operation
 */
int game(int difficulty);
