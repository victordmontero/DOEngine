#pragma once 
#include "GeometricRender.h"

class Sprite
{
   int id;
   Rect rect;
   Rect clip;
   Point point;
   
   public:

    Sprite();
    Sprite(int texture_id);
    ~Sprite();

    void SetTextureID(int id);
    void SetPosition(int x, int y);

};