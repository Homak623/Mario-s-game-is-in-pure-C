#include "gameObjects.h"

void InitializeGameObject(GameObject *obj,float xPos,float yPos,float objWidth,float objHeight,char objType)
{
   (*obj).yPos=yPos;
   (*obj).xPos=xPos;
   (*obj).objectWidth=objWidth;
   (*obj).objectHeight=objHeight;
   (*obj).verticalSpeed= 0;
   (*obj).objectType=objType;
   if((*obj).objectType=='=')
   (*obj).horizontalSpeed=0.5;
   else
   (*obj).horizontalSpeed=0.1;
}

GameObject *CreateNewStaticObject(GameObject **staticObject, int *staticObjectLength)
{
    (*staticObjectLength)++;
    *staticObject = realloc(*staticObject, sizeof(**staticObject) * (*staticObjectLength));
    return *staticObject + (*staticObjectLength) - 1;
}

GameObject *CreateNewMovingObject(GameObject **movingObject, int *movingObjectLength)
{
    (*movingObjectLength)++;
    (*movingObject) = realloc((*movingObject), sizeof(**movingObject) * (*movingObjectLength));
    return (*movingObject) + (*movingObjectLength) - 1;
}

void RemoveStaticObject(GameObject **staticObject, int *staticObjectLength, int index) {
    (*staticObjectLength)--;
    (*staticObject)[index] = (*staticObject)[(*staticObjectLength)];
    *staticObject = realloc(*staticObject, sizeof(**staticObject) * (*staticObjectLength));
}

void RemoveMovingObject(GameObject **movingObject, int *movingObjectLength, int index) {
    (*movingObjectLength)--;
    (*movingObject)[index] = (*movingObject)[(*movingObjectLength)];
    *movingObject = realloc(*movingObject, sizeof(**movingObject) * (*movingObjectLength));
}
