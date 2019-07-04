#pragma once
#include "game.h"
#include <string.h>
#define LINE_SIZE 15
#define TOP_PLAYERS 5

/**
 *
 * @param str
 * @param garbage
 */
void removeChar(char *str, char garbage);
/**
 *
 * @param playerName
 * @param score
 */
void savingScore(char playerName[15], int score);
/**
 *
 * @param i
 * @param j
 * @param k
 */
void displayBlank(int i, int j, int k);
/**
 *
 * @param i
 * @param j
 */
void showLeaderboard(int i, int j);