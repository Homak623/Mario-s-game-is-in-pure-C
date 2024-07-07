#include "gameHandlers.h"

void HandlePlayerDeath(int *gameFlag, GameObject *mainCharacter, int *commonScore, int *gameLevel, GameObject **BOSS, GameObject **staticObject, GameObject **movingObject, int *staticObjectLength, int *movingObjectLength, int *BOSS_defeat, char gameMap[GAME_MAP_HEIGHT][GAME_MAP_WIDTH+1],int levelMax)
{
  *gameFlag=0;
   system("color 4F");
   Sleep(1000);
   FILE* file = fopen("C:/c/mariogame.txt", "r");
   CheckFILE(file);
   char check;
   int var1,var2;
   fscanf(file, " %c", &check);
   fscanf(file, "%d %d", &var1, &var2);
   fscanf(file,"%d",commonScore);
   fclose(file);
   GenerateGameLevel(*gameLevel, mainCharacter, BOSS, staticObject, movingObject, staticObjectLength, movingObjectLength, BOSS_defeat, gameMap,levelMax);
}

void HandleWinCondition(int levelNumber, int *gameFlag, int *commonScore, int levelMax, GameObject **BOSS, GameObject **staticObject, GameObject **movingObject, int *staticObjectLength, int *movingObjectLength, char gameMap[GAME_MAP_HEIGHT][GAME_MAP_WIDTH+1], GameObject *mainCharacter, int *BOSS_defeat)
{
    *gameFlag=0;
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consoleHandle, FOREGROUND_GREEN);
    system("cls");
    setConsoleFontSize(100);
    hideConsoleCursor();
    printf("\n\n\n\tYour score: %d\n", *commonScore);
    Sleep(2000);
    GenerateGameLevel(levelNumber, mainCharacter, BOSS, staticObject, movingObject, staticObjectLength, movingObjectLength, BOSS_defeat, gameMap,levelMax);
}

