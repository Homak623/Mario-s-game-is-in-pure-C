#ifndef GAMEUTILS_H
#define GAMEUTILS_H

#include <stdio.h>
#include <windows.h>
#include "gameMap.h"

void CheckFILE(FILE* file);
int randomSign();
BOOL IsPositionInGameMap(int x,int y);
void SetCursorPosition(int x,int y);
void hideConsoleCursor();
void setConsoleFontSize(int FontSize);

#endif
