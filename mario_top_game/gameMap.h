#ifndef GAMEMAP_H
#define GAMEMAP_H

#define GAME_MAP_WIDTH 80
#define GAME_MAP_HEIGHT 25

#include "gameObjects.h"
#include <windows.h>

void DisplayGameMap(char gameMap[GAME_MAP_HEIGHT][GAME_MAP_WIDTH+1]);
void ClearGameMap(char gameMap[GAME_MAP_HEIGHT][GAME_MAP_WIDTH+1]);
void MoveGameMapHorizontally(float dx, GameObject *mainCharacter, GameObject **staticObject, int *staticObjectLength, GameObject **BOSS, int *BOSS_defeat, int *gameFlag, int *commonScore, int *gameLevel, GameObject **movingObject, int *movingObjectLength, char gameMap[GAME_MAP_HEIGHT][GAME_MAP_WIDTH+1],int levelMax);
void PlaceObjectOnGameMap(GameObject obj, char gameMap[GAME_MAP_HEIGHT][GAME_MAP_WIDTH+1]);

#endif
