#include "collision.h"

BOOL CheckCollision(GameObject obj1, GameObject obj2) {
    return (((obj1.xPos + obj1.objectWidth) > obj2.xPos) &&
            (obj1.xPos < (obj2.xPos + obj2.objectWidth)) &&
            ((obj1.yPos + obj1.objectHeight) > obj2.yPos) &&
            (obj1.yPos < (obj2.yPos + obj2.objectHeight)));
}

void HandleMainCharacterAndDogCollision(GameObject **movingObject, int *movingObjectLength, GameObject *mainCharacter, int *commonScore, int *gameLevel, int *BOSS_defeat, GameObject **BOSS, GameObject **staticObject, int *staticObjectLength, char gameMap[GAME_MAP_HEIGHT][GAME_MAP_WIDTH+1],int*gameFlag,int levelMax) {
    for(int i = 0; i < *movingObjectLength; i++) {
        if((*movingObject)[i].objectType == '=') {
            for(int j = 0; j < *movingObjectLength; j++) {
                if((*movingObject)[j].objectType == 'o' && CheckCollision((*movingObject)[i], (*movingObject)[j]) && j != i) {
                RemoveMovingObject(movingObject, movingObjectLength, j);
                *commonScore += 50;
                j--;
                }
            }
            continue;
        }
        if(CheckCollision(*mainCharacter, (*movingObject)[i])) {
            if((*movingObject)[i].objectType == 'o') {
                if(((*mainCharacter).verticalSpeed > 0) && ((*mainCharacter).yPos + (*mainCharacter).objectHeight < (*movingObject)[i].yPos + (*movingObject)[i].objectHeight)) {
                    *commonScore += 50;
                    RemoveMovingObject(movingObject, movingObjectLength, i);
                    i--;
                    continue;
                } else {
                    HandlePlayerDeath(gameFlag, mainCharacter, commonScore, gameLevel, BOSS, staticObject, movingObject, staticObjectLength, movingObjectLength, BOSS_defeat, gameMap,levelMax);
                }
            }
            if((*movingObject)[i].objectType == '$') {
                *commonScore += 100;
                RemoveMovingObject(movingObject, movingObjectLength, i);
                i--;
                continue;
            }
        }
    }
    if(*BOSS_defeat == 0 && CheckCollision(*mainCharacter, **BOSS)) {
        if(((*mainCharacter).verticalSpeed > 0) && ((*mainCharacter).yPos + (*mainCharacter).objectHeight < (*BOSS)->yPos + (*BOSS)->objectHeight)) {
            free(*BOSS);
            *BOSS_defeat = 1;
            (*gameLevel)++;
            Start_new(gameLevel, levelMax, BOSS_defeat, BOSS, commonScore, staticObject, movingObject, staticObjectLength, movingObjectLength, gameMap, mainCharacter);
        } else {
            HandlePlayerDeath(gameFlag, mainCharacter, commonScore, gameLevel, BOSS, staticObject, movingObject, staticObjectLength, movingObjectLength, BOSS_defeat, gameMap,levelMax);
        }
    }
}

void handleQuestionMarkObject(GameObject *obj, GameObject **staticObject, int i, GameObject **movingObject, int *movingObjectLength) {
    (*staticObject)[i].objectType = '-';
    int randomValue;
    randomValue =  randomSign();
    if(randomValue == 1) {
        GameObject *newMovingObject = CreateNewMovingObject(movingObject, movingObjectLength);
        InitializeGameObject(newMovingObject, (*staticObject)[i].xPos, (*staticObject)[i].yPos - 2, 3, 2, '$');
        (*movingObject)[*movingObjectLength - 1].verticalSpeed = -0.7;
    } else {
        randomValue = randomSign();
        GameObject *newMovingObject = CreateNewMovingObject(movingObject, movingObjectLength);
        InitializeGameObject(newMovingObject, (*staticObject)[i].xPos - ((*staticObject)[i].objectWidth / 2 + 3) * (randomValue), (*staticObject)[i].yPos - 5, 2, 2, 'o');
        (*movingObject)[*movingObjectLength - 1].verticalSpeed = -0.7;
    }
}

void handleAsteriskObject(int *commonScore, GameObject **staticObject, int *staticObjectLength, int i) {
    *commonScore += 25;
    RemoveStaticObject(staticObject, staticObjectLength, i);
    if (i > 0) {
        i--;
    }
}

void handleAmpersandObject(GameObject *obj, GameObject **staticObject, int *staticObjectLength, int i) {
    RemoveStaticObject(staticObject, staticObjectLength, i);
    if (i > 0) {
        i--;
    }
}

void handlePercentObject(int *gameFlag, GameObject *mainCharacter, int *commonScore, int *gameLevel, GameObject **BOSS, GameObject **staticObject, GameObject **movingObject, int *staticObjectLength, int *movingObjectLength, int *BOSS_defeat, char gameMap[GAME_MAP_HEIGHT][GAME_MAP_WIDTH+1], int levelMax) {
    HandlePlayerDeath(gameFlag, mainCharacter, commonScore, gameLevel, BOSS, staticObject, movingObject, staticObjectLength, movingObjectLength, BOSS_defeat, gameMap,levelMax);
}

void handlePlusObject(int *gameLevel, int levelMax, GameObject **BOSS, int *commonScore, int *gameFlag, GameObject **staticObject, GameObject **movingObject, int *staticObjectLength, int *movingObjectLength, char gameMap[GAME_MAP_HEIGHT][GAME_MAP_WIDTH+1], GameObject *mainCharacter, int *BOSS_defeat) {
    (*gameLevel)++;
    FILE* file = fopen("C:/c/mariogame.txt", "r");
    CheckFILE(file);
    char check;
    int maxScore;
    fscanf(file, " %c", &check);
    fscanf(file, "%d", &maxScore);
    fclose(file);
    file = fopen("C:/c/mariogame.txt", "w");
    CheckFILE(file);
    fprintf(file, "%c\n", check);
    fprintf(file, "%d\n", maxScore);
    fprintf(file, "%d\n", *gameLevel);
    fprintf(file, "%d", *commonScore);
    fclose(file);
    HandleWinCondition(*gameLevel, gameFlag, commonScore, levelMax, BOSS, staticObject, movingObject, staticObjectLength, movingObjectLength, gameMap, mainCharacter, BOSS_defeat);
    GenerateGameLevel(*gameLevel, mainCharacter, BOSS, staticObject, movingObject, staticObjectLength, movingObjectLength, BOSS_defeat, gameMap,levelMax);
}

void HandleObjectCollision(GameObject *obj, GameObject **staticObject, int *staticObjectLength, GameObject *mainCharacter, int *commonScore, int *gameLevel, int levelMax, GameObject **BOSS, char gameMap[GAME_MAP_HEIGHT][GAME_MAP_WIDTH+1], int *gameFlag, GameObject **movingObject, int *movingObjectLength, int *BOSS_defeat) {
    for(int i = 0; i < (*staticObjectLength); i++) {
        if(CheckCollision(*obj, (*staticObject)[i])) {
            if((*obj).verticalSpeed > 0) {
                (*obj).isFlying = FALSE;
            }
            if((obj == mainCharacter)){
            if(((*staticObject)[i].objectType == '?') && ((*obj).verticalSpeed < 0)) {
                handleQuestionMarkObject(obj, staticObject, i, movingObject, movingObjectLength);
            }
            if((*staticObject)[i].objectType == '*'  && ((*obj).verticalSpeed < 0)) {
                handleAsteriskObject(commonScore, staticObject, staticObjectLength, i);
            }
            if((*staticObject)[i].objectType == '%' ) {
                handlePercentObject(gameFlag, mainCharacter, commonScore, gameLevel, BOSS, staticObject, movingObject, staticObjectLength, movingObjectLength, BOSS_defeat, gameMap,levelMax);
            }
            if((*staticObject)[i].objectType == '+' ) {
                handlePlusObject(gameLevel, levelMax, BOSS, commonScore, gameFlag, staticObject, movingObject, staticObjectLength, movingObjectLength, gameMap, mainCharacter, BOSS_defeat);
            }
            }
            if((*staticObject)[i].objectType == '&') {
                handleAmpersandObject(obj, staticObject, staticObjectLength, i);
            }
            else {
                (*obj).yPos -= (*obj).verticalSpeed;
                (*obj).verticalSpeed = 0;
            }
        }
    }
}


