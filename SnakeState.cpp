#include "GeometricRender.h"
#include "SnakeState.h"
#include "Texture.h"
#include "Sprite.h"
#include "Window.h"
namespace
{
     Sprite white;
     Sprite red;
     Sprite green;
     int counter_x;
     int counter_y;
     int size=16;
     int dir,num =4;

    
    Point s[100];

void Tick()
{
   for(int i=num;i>0;--i)
   {
       s[i].x = s[i-1].x;
       s[i].y = s[i-1].y;
   }
   if(dir==0)s[0].y+=1;
   if(dir==0)s[1].x-=1;
   if(dir==0)s[2].x+=1;
   if(dir==0)s[3].y-=1;
}
};
extern Window* window;

void SnakeState::onEnter()
{
   white.SetTextureID(WHITE_SPRITE);
   white.SetCropRect(Rect(0,0,16,16));

   red.SetTextureID(RED_SPRITE);
   red.SetCropRect(Rect(0,0,16,16));

   green.SetTextureID(GREEN_SPRITE);
   green.SetCropRect(Rect(0,0,16,16));

   counter_x = window->getWidth()/16;
   counter_y = window->getHeight()/16;
   counter_x -=2;
   counter_y -=2;
}
void SnakeState::onExit()
{



}
void SnakeState::Update(){}
void SnakeState::Render()
{
    for(int y=0;y<counter_y;y++)
    {
        for(int x=0;x<counter_x;x++)
        {
            white.SetRect(Rect(x*16+16, y*16+16,16,16));
            window->DrawSprite(&white);
        }
    }
    
}
void SnakeState::onKeyDown(std::map<SDL_Keycode, bool>keys){}
void SnakeState::onKeyUp(std::map<SDL_Keycode, bool>keys){}