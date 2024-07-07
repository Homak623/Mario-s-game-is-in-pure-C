#ifndef HANDLE_KEYS_H
#define HANDLE_KEYS_H

#include "gameObjects.h"
#include <stdio.h>

#define GAME_MAP_HEIGHT 25
#define GAME_MAP_WIDTH 80

void HandleKeyInputs(int *gameLevel, int *commonScore, int *BOSS_defeat, GameObject *mainCharacter, GameObject **BOSS, GameObject **staticObject, GameObject **movingObject, int *staticObjectLength, int *movingObjectLength, char gameMap[GAME_MAP_HEIGHT][GAME_MAP_WIDTH+1], int levelMax, int *gameFlag,int *maxScore);

#endif

