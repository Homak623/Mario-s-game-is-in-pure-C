#ifndef GAMEUI_H
#define GAMEUI_H

#include <stdio.h>
#include<windows.h>

#define GAME_MAP_WIDTH 80
#define GAME_MAP_HEIGHT 25

void DisplayScoreOnGameMap(int commonScore, char gameMap[GAME_MAP_HEIGHT][GAME_MAP_WIDTH+1]);
void DisplayJumpCount(int jumpCount, char gameMap[GAME_MAP_HEIGHT][GAME_MAP_WIDTH+1]);
void DisplayGameLevel(int gameLevel, char gameMap[GAME_MAP_HEIGHT][GAME_MAP_WIDTH+1]);
void StartMenu();

#endif
