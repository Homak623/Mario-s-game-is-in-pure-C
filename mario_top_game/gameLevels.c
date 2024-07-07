#include "gameLevels.h"

void GenerateGameLevel(int levelNumber, GameObject *mainCharacter, GameObject **BOSS, GameObject **staticObject, GameObject **movingObject, int *staticObjectLength, int *movingObjectLength, int *BOSS_defeat, char gameMap[GAME_MAP_HEIGHT][GAME_MAP_WIDTH+1],int levelMax) {
    *staticObjectLength = 0;
    *staticObject = realloc(*staticObject, 0);
    *movingObjectLength = 0;
    *movingObject = realloc(*movingObject, 0);
     char filename[20];

    typedef struct {
        float xPos;
        float yPos;
        float width;
        float height;
        char type;
    } LevelData;
    LevelData data;

    InitializeGameObject(mainCharacter, 40, 10, 3, 5, '@');

    sprintf(filename, "C:/c/level%d.txt", levelNumber);
    FILE* file = fopen(filename, "r");
    CheckFILE(file);

    if(levelNumber == levelMax) {
        *BOSS_defeat=0;
        *BOSS=malloc(sizeof(GameObject));
        InitializeGameObject(*BOSS, 50, 15, 3, 3, 'B');
    }

    while (fscanf(file, "%f %f %f %f %c", &data.xPos, &data.yPos, &data.width, &data.height, &data.type) == 5) {
        if (data.type == 'o' || data.type == '$' ) {
            InitializeGameObject(CreateNewMovingObject(movingObject, movingObjectLength), data.xPos, data.yPos, data.width, data.height, data.type);
        } else {
            InitializeGameObject(CreateNewStaticObject(staticObject, staticObjectLength), data.xPos, data.yPos, data.width, data.height, data.type);
        }
    }
    fclose(file);
}

void handleLevelSelection(int *gameLevel, int *BOSS_defeat, GameObject **BOSS) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    while(1) {
        if(GetKeyState('1') < 0) {
            *gameLevel = 1;
            *BOSS_defeat = 1;
            break;
        }
        if(GetKeyState('2') < 0) {
            *gameLevel = 2;
            *BOSS_defeat = 1;
            break;
        }
        if(GetKeyState('3') < 0) {
            *gameLevel = 3;
            *BOSS_defeat = 1;
            break;
        }
        if(GetKeyState('4') < 0) {
            *gameLevel = 4;
            *BOSS_defeat = 0;
            break;
        }
    }
}

void Start_new(int *gameLevel, int levelMax, int *BOSS_defeat, GameObject **BOSS, int *commonScore, GameObject **staticObject, GameObject **movingObject, int *staticObjectLength, int *movingObjectLength, char gameMap[GAME_MAP_HEIGHT][GAME_MAP_WIDTH+1], GameObject *mainCharacter) {

    if(*gameLevel > levelMax) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 12);
        char check;
        int maxScore;
        system("cls");
        FILE* file = fopen("C:/c/mariogame.txt", "r");
        CheckFILE(file);
        fscanf(file, " %c", &check);
        fscanf(file, "%d %d %d", &maxScore, gameLevel, commonScore);
        if(check == 'L'){
            setConsoleFontSize(150);
            hideConsoleCursor();
            printf("\n\tVICTORY!!!\nMAX SCORE: %d\nYOUR SCORE: %d\n",maxScore,*commonScore);
            Sleep(3000);
        }
        fclose(file);
        file = fopen("C:/c/mariogame.txt", "w");
        CheckFILE(file);
        fprintf(file, "%c\n", 'W');

        if(check == 'W') {
            fprintf(file, "%d\n", maxScore);
        } else {
            if(*commonScore > maxScore) {
                fprintf(file, "%d\n", *commonScore);
            } else {
                fprintf(file, "%d\n", maxScore);
            }
        }
        *commonScore=0;
        fprintf(file, "%d\n", 1);
        fprintf(file, "%d", *commonScore);
        fclose(file);
        system("cls");
        setConsoleFontSize(90);
        hideConsoleCursor();
        printf("\n\tchoose level:\n");
        SetConsoleTextAttribute(hConsole, 13);
        printf("\t1 - first level\n \t2 - second level\n \t3 - third level:\n \t4 - fourth level\n ");
        handleLevelSelection(gameLevel, BOSS_defeat, BOSS);
        system("cls");
        GenerateGameLevel(*gameLevel, mainCharacter, BOSS, staticObject, movingObject, staticObjectLength, movingObjectLength, BOSS_defeat, gameMap,levelMax);
    }
}


