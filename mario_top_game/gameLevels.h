#ifndef GAMELEVELS_H
#define GAMELEVELS_H

#include "gameObjects.h"
#include "gameMap.h"
#include <stdio.h>
#include <stdlib.h>

void GenerateGameLevel(int levelNumber, GameObject *mainCharacter, GameObject **BOSS, GameObject **staticObject, GameObject **movingObject, int *staticObjectLength, int *movingObjectLength, int *BOSS_defeat, char gameMap[GAME_MAP_HEIGHT][GAME_MAP_WIDTH+1],int levelMax);
void Start_new(int *gameLevel, int levelMax, int *BOSS_defeat, GameObject **BOSS, int *commonScore, GameObject **staticObject, GameObject **movingObject, int *staticObjectLength, int *movingObjectLength, char gameMap[GAME_MAP_HEIGHT][GAME_MAP_WIDTH+1], GameObject *mainCharacter);

#endif

