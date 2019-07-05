#pragma once
#include "game.h"
/**
 *Function operates with static variable 
 * @param c- is inputed charater, depending on it static integer changes 
 * @param max- maximal value of static variable 
 * @return- returns changed static integer
 */
int whichChoice(char c,int max);
/**
 * selectDiff displays message to user about difficulty after changes
 * @param key- depending on key and whichChoice we obtain difficulty
 * @return difficulty
 */
int selectDiff(char key);
/**
 *The function displays message to user about operation performed after action
 * @param whereMark- defines before which operation displays Mark 
 */
void displayMenu(int whereMark);