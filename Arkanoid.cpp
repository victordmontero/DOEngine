#include "Event.h"
#include "Arkanoid.h"
#include "Window.h"
#include "Sprite.h"
#include "Texture.h"

#include <time.h>
#include <stdlib.h>

namespace {
    Sprite block[1000];
    int n;
    Sprite paddle;
    float x=0;

    Sprite Ball;
    float dx = 1, dy=1;

    bool isCollide(Sprite s1, Sprite s2){
      SDL_Rect r1={s1.getX(), s1.getY(), s1.getW(), s1.getH()};
      SDL_Rect r2={s2.getX(), s2.getY(), s2.getW(), s2.getH()};
      return SDL_HasIntersection(&r1, &r2)==SDL_TRUE;
    }
}

 extern Window *window;
void ArkanoidGame::onEnter()
{
  extern Window *window;
  window->addKeyListener(this);
   paddle.SetTextureID(ARKANOID_SPRITE);
   paddle.SetPosition(350,540);
   paddle.SetCropRect(Rect(300,0,150,32));
   paddle.SetSize(100,32);
   
   Ball.SetTextureID(BALL_SPRITE);
   Ball.SetPosition(350,440);
   Ball.SetCropRect(Rect(0,0,32,32));
   Ball.SetSize(32,32);
  

   n =0;
   for(int i=1;i<=18;i++)
    for(int j=1; j<=10;j++)
    {
      block[n].SetTextureID(ARKANOID_SPRITE);
      block[n].SetPosition(i*45, j*35);
      block[n].SetSize(43,20);
      block[n].SetCropRect(Rect(0,0,100,32));
       
      n++;
    }

}


void ArkanoidGame::onExit()
{}
void ArkanoidGame::Update()
{

   srand(time(NULL));
   paddle.Move(x,0);
   if(isCollide(Ball, paddle))
   {
      dy = -(rand()%2+1);
   }


 
   Ball.Move(dx,0);
    for(int i=0;i<n;i++)
      {
         if(isCollide(Ball, block[i])){block[i].SetPosition(0,-500); dx = -dx;}
      }
 
    Ball.Move(0,dy);
    for(int i=0;i<n;i++)
      {
         if(isCollide(Ball, block[i])){block[i].SetPosition(0,-500); dy = -dy;}
      }
 

   Rect rect = Ball.getRect();
   if(rect.x < 0 || rect.x >= window->getWindowRect().w) dx =-dx;
   if(rect.y < 0 || rect.y >= window->getWindowRect().h) dy =-dy;

}
void ArkanoidGame::Render()
{
  extern Window *window;
  window->setClearColor(41, 95, 181);
  window->Clear();
  window->DrawSprite(&paddle);
  window->DrawSprite(&Ball);
  for(int i=0;i<n;i++)
    window->DrawSprite(&block[i]);
}


void ArkanoidGame::onKeyDown(std::map<SDL_Keycode, bool>keys)
{ 
   if(keys[SDLK_LEFT]){
     x=-1;
   }
    if(keys[SDLK_RIGHT]){
     x=1;
   }
}
void ArkanoidGame::onKeyUp(std::map<SDL_Keycode, bool>keys)
{
  x=0;
   
}