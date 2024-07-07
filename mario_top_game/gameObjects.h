#ifndef GAMEOBJECTS_H
#define GAMEOBJECTS_H

#include <windows.h>

typedef struct GameObject
{
   float xPos, yPos;
   float objectWidth, objectHeight;
   float verticalSpeed;
   BOOL isFlying;
   char objectType;
   float horizontalSpeed;
} GameObject;

void RemoveStaticObject(GameObject **staticObject, int *staticObjectLength, int index);
void RemoveMovingObject(GameObject **movingObject, int *movingObjectLength, int index);
void InitializeGameObject(GameObject *obj,float xPos,float yPos,float objWidth,float objHeight,char objType);
GameObject *CreateNewStaticObject(GameObject **staticObject, int *staticObjectLength);
GameObject *CreateNewMovingObject(GameObject **movingObject, int *movingObjectLength);

#endif
