#include "MoveObjects.h"

void MoveObjectVertically(GameObject *obj, GameObject **staticObject, int *staticObjectLength, GameObject *mainCharacter, int *commonScore, int *gameLevel, int levelMax, GameObject **BOSS, char gameMap[GAME_MAP_HEIGHT][GAME_MAP_WIDTH+1], int *gameFlag, GameObject **movingObject, int *movingObjectLength, int *BOSS_defeat) {
    (*obj).isFlying = TRUE;
    (*obj).verticalSpeed += 0.05;
    (*obj).yPos = (*obj).yPos + (*obj).verticalSpeed;
    HandleObjectCollision(obj, staticObject, staticObjectLength, mainCharacter, commonScore, gameLevel, levelMax, BOSS, gameMap, gameFlag, movingObject, movingObjectLength, BOSS_defeat);
}


void MoveObjectHorizontally(GameObject *obj, GameObject **staticObject, int *staticObjectLength, GameObject *mainCharacter, int *commonScore, int *gameLevel, int levelMax, GameObject **BOSS, char gameMap[GAME_MAP_HEIGHT][GAME_MAP_WIDTH+1], int *gameFlag, GameObject **movingObject, int *movingObjectLength,int *BOSS_defeat) {
    (*obj).xPos += (*obj).horizontalSpeed;

    for(int i = 0; i < *staticObjectLength; i++) {
        if(CheckCollision(*obj, (*staticObject)[i])) {
            (*obj).xPos -= (*obj).horizontalSpeed;
            (*obj).horizontalSpeed = -(*obj).horizontalSpeed;
            return;
        }
    }

    if((*obj).objectType == 'o') {
        GameObject tempObj = *obj;
        MoveObjectVertically(&tempObj, staticObject, staticObjectLength, mainCharacter, commonScore, gameLevel, levelMax, BOSS, gameMap, gameFlag, movingObject, movingObjectLength, BOSS_defeat);
        if(tempObj.isFlying == TRUE) {
            (*obj).xPos -= (*obj).horizontalSpeed;
            (*obj).horizontalSpeed = -(*obj).horizontalSpeed;
        }
    }
}
