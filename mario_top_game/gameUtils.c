#include "gameUtils.h"

void CheckFILE(FILE* file)
{
    if (file == NULL)
    {
        system("cls");
        printf("\nFailed to open file\n");
        exit(-1);
    }
}

int randomSign()
{
    return (rand() % 2 == 0) ? 1 : -1;
}

BOOL IsPositionInGameMap(int x,int y)
{
    return ((x>=0) && (x<GAME_MAP_WIDTH) && (y>=0) && (y<GAME_MAP_HEIGHT));
}

void SetCursorPosition(int x,int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=x;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void hideConsoleCursor() {
    HANDLE  handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(handle, &structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(handle, &structCursorInfo);
}

void setConsoleFontSize(int FontSize) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;
    cfi.dwFontSize.Y = FontSize;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy(cfi.FaceName, L"Consolas");
    SetCurrentConsoleFontEx(hConsole,FALSE, &cfi);
}



