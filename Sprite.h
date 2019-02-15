#pragma once 
#include "GeometricRender.h"
#include "Texture.h"
 
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
    void SetSize(int w, int h);
    void Move(int x, int y);
    void SetRect(Rect rect);

    void SetCropRect(Rect rect);
    inline int getX(){
        return rect.x;
    }
    inline int getY(){
        return rect.y;
    }
    inline int getW(){
        return rect.w;
    }
    inline int getH(){
        return rect.h;
    }
   
    int getTextureID(){
        return id;
    }


    Rect& getRect(){
        return rect;
    }
    Rect& getCropRect(){
        return clip;
    }

};