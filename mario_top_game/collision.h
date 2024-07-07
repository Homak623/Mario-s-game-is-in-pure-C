#ifndef COLLISION_H
#define COLLISION_H

#include "gameObjects.h"
#include "gameMap.h"
#include <stdio.h>

BOOL CheckCollision(GameObject obj1, GameObject obj2);
BOOL CheckBOSSCollision(GameObject obj1, GameObject obj2);
void HandleMainCharacterAndDogCollision(GameObject **movingObject, int *movingObjectLength, GameObject *mainCharacter, int *commonScore, int *gameLevel, int *BOSS_defeat, GameObject **BOSS, GameObject **staticObject, int *staticObjectLength, char gameMap[GAME_MAP_HEIGHT][GAME_MAP_WIDTH+1],int*gameFlag,int levelMax);
void HandleObjectCollision(GameObject *obj, GameObject **staticObject, int *staticObjectLength, GameObject *mainCharacter, int *commonScore, int *gameLevel, int levelMax, GameObject **BOSS, char gameMap[GAME_MAP_HEIGHT][GAME_MAP_WIDTH+1], int *gameFlag, GameObject **movingObject, int *movingObjectLength, int *BOSS_defeat);

#endif

