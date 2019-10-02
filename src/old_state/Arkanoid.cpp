#include "Event.h"
#include "Arkanoid.h"
#include "Window.h"
#include "Sprite.h"
#include "Texture.h"

namespace 
{
    Sprite block[1000];
    int n;
    Sprite paddle;
    float x=0;
    Sprite Ball;  
};


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
   paddle.Move(x,0);
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