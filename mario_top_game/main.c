#include <stdio.h>
#include <stdlib.h>

#include "gameObjects.h"
#include "gameMap.h"
#include "collision.h"
#include "gameLevels.h"
#include "gameUtils.h"
#include "gameUI.h"
#include "gameHandlers.h"
#include "MoveObjects.h"
#include "handleKeys.h"

void free_memory(GameObject** BOSS, GameObject** staticObject, GameObject** movingObject) {
    if (*BOSS != NULL) {
        free(*BOSS);
    }

    if (*staticObject != NULL) {
        free(*staticObject);
    }

    if (*movingObject != NULL) {
        free(*movingObject);
    }
}

void LoadGame(int *gameLevel, int *commonScore, int *BOSS_defeat, GameObject *mainCharacter, GameObject **BOSS, GameObject **staticObject, GameObject **movingObject, int *staticObjectLength, int *movingObjectLength, char gameMap[GAME_MAP_HEIGHT][GAME_MAP_WIDTH+1], int levelMax,int *maxScore,int *Last_Level)
{
    FILE* file = fopen("C:/c/mariogame.txt", "r");
    CheckFILE(file);
    hideConsoleCursor();
    char check;
    fscanf(file, " %c", &check);
    fscanf(file, "%d %d %d", maxScore, Last_Level, commonScore);
    fclose(file);

    StartMenu();
    if(*Last_Level <= levelMax && *Last_Level > 1 && check != 'W') {
        setConsoleFontSize(100);
        hideConsoleCursor();
        printf("Do you want to start play level\n(%d) from your past game? \n 1-Yes 2-No\n", *Last_Level);
    while(1) {
        if(GetKeyState('1') < 0) {
        *gameLevel = *Last_Level;
        break;
        } else if(GetKeyState('2') < 0) {
        *gameLevel = 1;
        *commonScore = 0;
        break;
        }
    }
    file = fopen("C:/c/mariogame.txt", "w");
    CheckFILE(file);
    fprintf(file, "%c\n", 'L');
    fprintf(file, "%d\n", *maxScore);
    fprintf(file, "%d\n", *gameLevel);
    fprintf(file, "%d\n", *commonScore);
    fclose(file);
    }
    GenerateGameLevel(*gameLevel, mainCharacter, BOSS, staticObject, movingObject, staticObjectLength, movingObjectLength, BOSS_defeat, gameMap,levelMax);
}

void checkBossStatus(int gameLevel, int levelMax, int *BOSS_defeat, GameObject*BOSS, int *KD_BOSS) {
        if(BOSS->isFlying == FALSE)
            (*KD_BOSS)++;
        if(*KD_BOSS == 20 && *BOSS_defeat == 0) {
            *KD_BOSS = 0;
            BOSS->verticalSpeed = -1;
        }
}

void main_func() {
    char gameMap[GAME_MAP_HEIGHT][GAME_MAP_WIDTH+1];
    GameObject mainCharacter;
    GameObject* BOSS = NULL;
    GameObject *staticObject = NULL;
    GameObject *movingObject = NULL;
    int movingObjectLength = 0;
    int gameFlag = 0;
    int staticObjectLength = 0;
    int levelMax = 4;
    int gameLevel = 1;
    int commonScore = 0;
    int BOSS_defeat = 1;
    int jumpCount = 0;
    int KD_BOSS = 0;
    int maxScore = 0;
    int Last_Level = 0;
    LoadGame(&gameLevel, &commonScore, &BOSS_defeat, &mainCharacter, &BOSS, &staticObject, &movingObject, &staticObjectLength, &movingObjectLength, gameMap, levelMax,&maxScore,&Last_Level);
do {
    system("color 0F");
    ClearGameMap(gameMap);
    HandleKeyInputs(&gameLevel, &commonScore, &BOSS_defeat, &mainCharacter, &BOSS, &staticObject, &movingObject, &staticObjectLength, &movingObjectLength, gameMap, levelMax, &gameFlag,&maxScore);
    if((mainCharacter.isFlying == FALSE) && GetKeyState(VK_SPACE) < 0) {
        mainCharacter.verticalSpeed = -1;
        jumpCount += 1;
    }
    if(gameLevel == levelMax && BOSS_defeat == 0) {
    checkBossStatus(gameLevel, levelMax, &BOSS_defeat, BOSS, &KD_BOSS);
}
    if(mainCharacter.yPos > GAME_MAP_HEIGHT) {
        HandlePlayerDeath(&gameFlag, &mainCharacter, &commonScore, &gameLevel, &BOSS, &staticObject, &movingObject, &staticObjectLength, &movingObjectLength, &BOSS_defeat, gameMap,levelMax);
    }
    MoveObjectVertically(&mainCharacter, &staticObject, &staticObjectLength, &mainCharacter, &commonScore, &gameLevel, levelMax, &BOSS, gameMap, &gameFlag, &movingObject, &movingObjectLength, &BOSS_defeat);

    if(BOSS_defeat == 0) {
        MoveObjectVertically(BOSS, &staticObject, &staticObjectLength, &mainCharacter, &commonScore, &gameLevel, levelMax, &BOSS, gameMap, &gameFlag, &movingObject, &movingObjectLength, &BOSS_defeat);
        MoveObjectHorizontally(BOSS, &staticObject, &staticObjectLength, &mainCharacter, &commonScore, &gameLevel, levelMax, &BOSS, gameMap, &gameFlag, &movingObject, &movingObjectLength, &BOSS_defeat);
    }
    HandleMainCharacterAndDogCollision(&movingObject, &movingObjectLength, &mainCharacter, &commonScore, &gameLevel, &BOSS_defeat, &BOSS, &staticObject, &staticObjectLength, gameMap,&gameFlag, levelMax);

    if(GetKeyState('A') < 0) {
        MoveGameMapHorizontally(1, &mainCharacter, &staticObject, &staticObjectLength, &BOSS, &BOSS_defeat, &gameFlag, &commonScore, &gameLevel, &movingObject, &movingObjectLength, gameMap, levelMax);
     }

    if(GetKeyState('D') < 0) {
        MoveGameMapHorizontally(-1, &mainCharacter, &staticObject, &staticObjectLength, &BOSS, &BOSS_defeat, &gameFlag, &commonScore, &gameLevel, &movingObject, &movingObjectLength, gameMap, levelMax);
    }

    for(int i = 0; i < staticObjectLength; i++)
        PlaceObjectOnGameMap(staticObject[i], gameMap);

    for(int i = 0; i < movingObjectLength; i++) {
        MoveObjectVertically(movingObject + i, &staticObject, &staticObjectLength, &mainCharacter, &commonScore, &gameLevel, levelMax, &BOSS, gameMap, &gameFlag, &movingObject, &movingObjectLength, &BOSS_defeat);
        MoveObjectHorizontally(movingObject + i, &staticObject, &staticObjectLength, &mainCharacter, &commonScore, &gameLevel, levelMax, &BOSS, gameMap, &gameFlag, &movingObject, &movingObjectLength, &BOSS_defeat);

        if(movingObject[i].yPos > GAME_MAP_HEIGHT) {
            RemoveMovingObject(&movingObject, &movingObjectLength, i);
            i--;
            continue;
        }
        PlaceObjectOnGameMap(movingObject[i], gameMap);
    }
    if(BOSS_defeat == 0){
    PlaceObjectOnGameMap(*BOSS, gameMap);
    }

    PlaceObjectOnGameMap(mainCharacter, gameMap);

    DisplayJumpCount(jumpCount, gameMap);
    DisplayGameLevel(gameLevel, gameMap);
    DisplayScoreOnGameMap(commonScore, gameMap);
    SetCursorPosition(0,0);
    DisplayGameMap(gameMap);
} while(GetKeyState(VK_ESCAPE) >= 0);
 free_memory(&BOSS, &staticObject, &movingObject);
}
int main() {
    main_func();
}
