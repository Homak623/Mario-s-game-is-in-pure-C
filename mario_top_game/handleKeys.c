#include "handleKeys.h"

void handleRKey(int *gameLevel, int *commonScore, int *BOSS_defeat, GameObject *mainCharacter, GameObject **BOSS, GameObject **staticObject, GameObject **movingObject, int *staticObjectLength, int *movingObjectLength, char gameMap[GAME_MAP_HEIGHT][GAME_MAP_WIDTH+1], int levelMax, int *gameFlag,int *maxScore) {
    if(GetKeyState('R') < 0) {
        FILE* file = fopen("C:/c/mariogame.txt", "w");
        CheckFILE(file);
        fprintf(file, "%s\n", "L");
        *gameFlag = 0;
        *gameLevel = 1;
        *commonScore = 0;
        *BOSS_defeat = 1;
        if(*gameLevel==levelMax)
        free(*BOSS);
        fprintf(file, "%d\n", *maxScore);
        fprintf(file, "%d\n", *gameLevel);
        fprintf(file, "%d\n", *commonScore);
        fclose(file);
        GenerateGameLevel(*gameLevel, mainCharacter, BOSS, staticObject, movingObject, staticObjectLength, movingObjectLength, BOSS_defeat, gameMap,levelMax);
    }
}

void handlePKey() {
    if(GetKeyState('P') < 0) {
        system("cls");
        system("color 1F");
        setConsoleFontSize(150);
        hideConsoleCursor();
        printf("\n\n\tPAUSE");
        while(GetKeyState('P') < 0);
        while(GetKeyState('P') >= 0);
        system("cls");
    }
}

void handleMKey(int *gameLevel, int levelMax, int *BOSS_defeat, GameObject **BOSS, int *commonScore, GameObject **staticObject, GameObject **movingObject, int *staticObjectLength, int *movingObjectLength, char gameMap[GAME_MAP_HEIGHT][GAME_MAP_WIDTH+1], GameObject *mainCharacter, int *gameFlag) {
    if(GetKeyState('M') < 0){
    FILE* file = fopen("C:/c/mariogame.txt", "r");
    CheckFILE(file);
    char check;
    fscanf(file, " %c", &check);
    fclose(file);
    if(check == 'W') {
            if(*gameLevel==levelMax)
            free(*BOSS);
            *gameFlag = 0;
            *gameLevel = levelMax+1;
            *commonScore = 0;
            Start_new(gameLevel, levelMax, BOSS_defeat, BOSS, commonScore, staticObject, movingObject, staticObjectLength, movingObjectLength, gameMap, mainCharacter);
    }
    }
}

void handleSKey(int *gameFlag, GameObject **movingObject, int *movingObjectLength, GameObject *mainCharacter) {
    if(GetKeyState('S') < 0 && *gameFlag == 0) {
        InitializeGameObject(CreateNewMovingObject(movingObject, movingObjectLength), mainCharacter->xPos, mainCharacter->yPos + 3, 2, 2, '=');
        *gameFlag = 1;
    }
}

void HandleKeyInputs(int *gameLevel, int *commonScore, int *BOSS_defeat, GameObject *mainCharacter, GameObject **BOSS, GameObject **staticObject, GameObject **movingObject, int *staticObjectLength, int *movingObjectLength, char gameMap[GAME_MAP_HEIGHT][GAME_MAP_WIDTH+1], int levelMax, int *gameFlag,int *maxScore) {
    handleRKey(gameLevel, commonScore, BOSS_defeat, mainCharacter, BOSS, staticObject, movingObject, staticObjectLength, movingObjectLength, gameMap, levelMax, gameFlag, maxScore);
    handlePKey();
    handleMKey(gameLevel, levelMax, BOSS_defeat, BOSS, commonScore, staticObject, movingObject, staticObjectLength, movingObjectLength, gameMap, mainCharacter, gameFlag);
    handleSKey(gameFlag, movingObject, movingObjectLength, mainCharacter);
}

