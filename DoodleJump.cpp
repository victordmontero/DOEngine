#include <ctime>
#include <cstdlib>
#include "Window.h"
#include "DoodleJump.h"
#include "Sprite.h"
namespace
{

    Sprite plat;
    Sprite doodle;
    Point point[12];
    int x=100;
    int y=100;
    int h=200;
    float dx=0;
    float dy=0;


    

};


void DoodleState::onEnter()
{
    
    plat.SetTextureID(PLATFORM_SPRITE);
    doodle.SetTextureID(DOODLE_SPRITE);
   
    doodle.SetCropRect(Rect(0,0,80,80));
    doodle.SetRect(Rect(0,0,48*2,48*2));

    plat.SetCropRect(Rect(0,0,68,14));
    plat.SetSize(68*2,14*2);
    h = window->getHeight()-400;
    std::srand(std::time(NULL));
    extern Window *window;
    window->addKeyListener(this);
    for(int i=0;i<10;i++)
    { 
      point[i].x = rand()%window->getWidth();
      point[i].y = rand()%window->getHeight();
    }
}
void DoodleState::onExit(){}
void DoodleState::Update()
{
    
    dy+=0.2;
    y +=dy;
    if(y>=window->getHeight() - doodle.getH())
        dy -= 10;
    
    if(y<h)
    {
       for(int i =0;i<10;i++)
       {
           point[i].y = point[i].y-dy;
           if(point[i].y>window->getHeight())
           {
               point[i].y = 0; 
               point[i].x = rand()%window->getWidth();
           }
       }
    }

	for (int i=0;i<10;i++)
    if ((x+50>point[i].x) && (x+20<point[i].x+68)
    && (y+70>point[i].y) && (y+70<point[i].y+14) && (dy>0))  dy=-10;


    doodle.SetPosition(x, y);
}
void DoodleState::Render()
{
    extern Window *window;
    window->DrawSprite(&doodle);
    for(int i=0;i<10;i++)
    {
        plat.SetPosition(point[i].x, point[i].y);
         window->DrawSprite(&plat);
    }
    SDL_Delay(16);
}


void DoodleState::onKeyDown(std::map<SDL_Keycode, bool>keys)
{
    // if(keys[SDLK_LEFT])x-=3;
    // if(keys[SDLK_RIGHT])x+=3;
    const Uint8 *keyboard=SDL_GetKeyboardState(NULL);
     if(keyboard[SDL_SCANCODE_LEFT])x-=3;
     if(keyboard[SDL_SCANCODE_RIGHT])x+=3;
}
void DoodleState::onKeyUp(std::map<SDL_Keycode, bool>keys)
{

}