#ifndef MOVE_OBJECTS_H
#define MOVE_OBJECTS_H

#include "gameObjects.h"
#include "gameMap.h"
#include <stdio.h>

void MoveObjectVertically(GameObject *obj, GameObject **staticObject, int *staticObjectLength, GameObject *mainCharacter, int *commonScore, int *gameLevel, int levelMax, GameObject **BOSS, char gameMap[GAME_MAP_HEIGHT][GAME_MAP_WIDTH+1], int *gameFlag, GameObject **movingObject, int *movingObjectLength, int *BOSS_defeat);
void MoveObjectHorizontally(GameObject *obj, GameObject **staticObject, int *staticObjectLength, GameObject *mainCharacter, int *commonScore, int *gameLevel, int levelMax, GameObject **BOSS, char gameMap[GAME_MAP_HEIGHT][GAME_MAP_WIDTH+1], int *gameFlag, GameObject **movingObject, int *movingObjectLength,int *BOSS_defeat);

#endif
