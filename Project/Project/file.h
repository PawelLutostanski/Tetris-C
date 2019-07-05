#pragma once
#include "game.h"
#include <string.h>
#define LINE_SIZE 15
#define TOP_PLAYERS 5

/**
 *Copies TOP_PLAYERSx2 lines to appropiete arrays, then write them in order with score and playerName
 * @param playerName- user's string
 * @param score- user's score
 */
void savingScore(char playerName[15], int score);
/**
 *Displays blank Leaderboard for k place with score=0 and playerName ='-'
 * @param i- collumn where Leaderboard should start displaying
 * @param j- row where Leaderboard should start displaying
 * @param k- which placement is blank
 */
void displayBlank(int i, int j, int k);
/**
 *Displays message and then scores and playerNames from filewith such formating: "<Placement> . <playerName>    <score>"
 * @param i- collumn where Leaderboard should start displaying
 * @param j- row where Leaderboard should start displaying
 */
void showLeaderboard(int i, int j);