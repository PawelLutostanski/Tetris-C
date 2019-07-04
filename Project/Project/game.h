#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "array.h"
#include "figureOper.h"
#include "setFigure.h"
#include "file.h"
#include <conio.h>
#include <Windows.h>

/**
 *
 * @param column
 * @param line
 */
void gotoxy(int column, int line);
/**
 *
 * @param addThem
 * @param whatToDo
 * @return
 */
int points(int addThem,char whatToDo);
/**
 *
 * @param score
 */
void displayScore(int score);
/**
 *
 * @return
 */
int fail();
/**
 *
 * @param dif
 * @return
 */
int game(int dif);
