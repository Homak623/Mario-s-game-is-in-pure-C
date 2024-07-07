#include "gameUI.h"

void DisplayScoreOnGameMap(int commonScore, char gameMap[GAME_MAP_HEIGHT][GAME_MAP_WIDTH+1]) {
    char scoreString[15];
    sprintf(scoreString, "Score: %d", commonScore);
    int scoreStringLength = strlen(scoreString);
    for(int i = 0; i < scoreStringLength; i++) {
        gameMap[1][i + 6] = scoreString[i];
    }
}

void DisplayJumpCount(int jumpCount, char gameMap[GAME_MAP_HEIGHT][GAME_MAP_WIDTH+1]) {
    char jumpCountString[15];
    sprintf(jumpCountString, "Jumps: %d", jumpCount);
    int jumpCountStringLength = strlen(jumpCountString);
    for(int i = 0; i < jumpCountStringLength; i++) {
        gameMap[1][i + 20] = jumpCountString[i];
    }
}

void DisplayGameLevel(int gameLevel, char gameMap[GAME_MAP_HEIGHT][GAME_MAP_WIDTH+1]) {
    char gameLevelString[15];
    sprintf(gameLevelString, "Level: %d", gameLevel);
    int gameLevelStringLength = strlen(gameLevelString);
    for(int i = 0; i < gameLevelStringLength; i++) {
        gameMap[1][i + 35] = gameLevelString[i];
    }
}

void StartMenu() {
    char check;
    int maxScore;
    FILE* file = fopen("C:/c/mariogame.txt", "r");
    CheckFILE(file);
    fscanf(file, " %c", &check);
    fscanf(file, "%d", &maxScore);
    fclose(file);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    printf("Your max Score: %d\n", maxScore);
    printf("Hello, today you will be able to play a very interesting game called Mario, but before that, a little instruction...\n'*' - object which yo should eat\n'#' - ordinary blocks on which you can jump.\n'%%' - blocks after contact with which the character will die.\n'&' - quicksand which disappears when you step on it\n'?'-if you hit it from the bottom up, a character will fall out of them '$' after contact with which the character gets 100 points,but be careful because the villain can also fall out)\n'o' - enemies of the character that interfere with the passage of the level.\n'+' - elements at the end of the level, touching which you can go to the next level or, if it is the last, select a level to pass.\n'B' - the boss who defeats the game will be considered completed.\nYou can also use the keys to move horizontally left and right 'A' and 'D' respectively\nfor vertical (up) 'SPACE'\nto release a dog that kills enemies 'S' (you can use it once per level)\nIn order to start the game first, there is a button 'R' and in order to go to the left level (available only after passing) - 'M';\n'P' - PAUSE\nThat's all for a good game)\n");
    printf("Press any key to continue . . . ");
    getch();
    system("cls");
}

