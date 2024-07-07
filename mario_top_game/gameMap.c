#include "gameMap.h"

void DisplayGameMap(char gameMap[GAME_MAP_HEIGHT][GAME_MAP_WIDTH+1])
{
    setConsoleFontSize(30);
    hideConsoleCursor();
    for(int i=0;i<GAME_MAP_HEIGHT;i++){
            printf("%s\n",gameMap[i]);
    }
}

void ClearGameMap(char gameMap[GAME_MAP_HEIGHT][GAME_MAP_WIDTH+1])
{
    for(int i=0;i<GAME_MAP_WIDTH;i++){
        for(int j=0;j<GAME_MAP_HEIGHT;j++){
        gameMap[j][i]=' ';
        if(i==0)
        gameMap[j][GAME_MAP_WIDTH]='\0';
        }
    }
}

void MoveGameMapHorizontally(float dx, GameObject *mainCharacter, GameObject **staticObject, int *staticObjectLength, GameObject **BOSS, int *BOSS_defeat, int *gameFlag, int *commonScore, int *gameLevel, GameObject **movingObject, int *movingObjectLength, char gameMap[GAME_MAP_HEIGHT][GAME_MAP_WIDTH+1],int levelMax)
{
      (*mainCharacter).xPos-=dx;
    for(int i=0;i<(*staticObjectLength);i++)
    {
        if(CheckCollision(*mainCharacter,(*staticObject)[i]))
        {
                (*mainCharacter).xPos+=dx;
        return;
        }
    }
    if(*BOSS_defeat==0)
        (*(*BOSS)).xPos+=dx;
    (*mainCharacter).xPos+=dx;
    for(int i=0;i<*staticObjectLength;i++)
        (*staticObject)[i].xPos+=dx;
        for(int i=0;i<*movingObjectLength;i++)
        (*movingObject)[i].xPos+=dx;
}


void DrawObject(GameObject obj, char gameMap[GAME_MAP_HEIGHT][GAME_MAP_WIDTH+1], int xPos, int yPos,int i,int j) {
    gameMap[j][i] = obj.objectType;
    if(IsPositionInGameMap(xPos, yPos))
        gameMap[yPos][xPos] = '|';
    if(IsPositionInGameMap(xPos+2, yPos))
        gameMap[yPos][xPos+2] = '|';
    if(IsPositionInGameMap(xPos, yPos+1))
        gameMap[yPos+1][xPos] = '-';
    if(IsPositionInGameMap(xPos+2, yPos+1))
        gameMap[yPos+1][xPos+2] = '-';
    if(IsPositionInGameMap(xPos, yPos+2))
        gameMap[yPos+2][xPos] = ' ';
    if(IsPositionInGameMap(xPos+2, yPos+2))
        gameMap[yPos+2][xPos+2] = ' ';
    if(IsPositionInGameMap(xPos+1, yPos+4))
        gameMap[yPos+4][xPos+1] = ' ';
}

void PlaceObject(GameObject obj, char gameMap[GAME_MAP_HEIGHT][GAME_MAP_WIDTH+1], int xPos, int yPos, int i, int j) {
    if(obj.objectType == '@') {
        DrawObject(obj, gameMap, xPos, yPos, i, j);
    } else {
        gameMap[j][i] = obj.objectType;
    }
}

void PlaceObjectOnGameMap(GameObject obj, char gameMap[GAME_MAP_HEIGHT][GAME_MAP_WIDTH+1]) {
    int roundedXPos,roundedYPos,roundedObjectWidth,roundedObjectHeight;
     roundedXPos = (int)round(obj.xPos);
     roundedYPos = (int)round(obj.yPos);
     roundedObjectWidth = (int)round(obj.objectWidth);
     roundedObjectHeight = (int)round(obj.objectHeight);

    for(int i = roundedXPos; i < (roundedXPos + roundedObjectWidth); i++) {
        for(int j = roundedYPos; j < (roundedYPos + roundedObjectHeight); j++) {
            if(IsPositionInGameMap(i, j)) {
                PlaceObject(obj, gameMap, roundedXPos, roundedYPos, i, j);
            }
        }
    }
}


