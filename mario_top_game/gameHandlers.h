#ifndef GAMEHANDLERS_H
#define GAMEHANDLERS_H

#include <stdio.h>
#include "gameObjects.h"
#include "gameMap.h"

void HandlePlayerDeath(int *gameFlag, GameObject *mainCharacter, int *commonScore, int *gameLevel, GameObject **BOSS, GameObject **staticObject, GameObject **movingObject, int *staticObjectLength, int *movingObjectLength, int *BOSS_defeat, char gameMap[GAME_MAP_HEIGHT][GAME_MAP_WIDTH+1],int levelMax);
void HandleWinCondition(int levelNumber, int *gameFlag, int *commonScore, int levelMax, GameObject **BOSS, GameObject **staticObject, GameObject **movingObject, int *staticObjectLength, int *movingObjectLength, char gameMap[GAME_MAP_HEIGHT][GAME_MAP_WIDTH+1], GameObject *mainCharacter, int *BOSS_defeat);

#endif
