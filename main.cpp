#include <memory>

#include "Window.h"
#include "Texture.h"
#include "BlockObject.h"
#include "Map.h"
#include "GeometricRender.h"
#include "Event.h"
#include "Arkanoid.h"
#include "onelonecoder.h"
#include "UDP.h"
#include "SnakeState.h"
#include "DoodleJump.h"
Window *window;


int main(int argc, char *argv[])
{

   window = new Window(900,600,"test");

   ////FOR ARKANID 
   Texture::LoadTexture(ARKANOID_SPRITE, "C:\\Aneury\\2D-ENGINE\\bin\\Debug\\sprite-arkanoid.bmp");
   Texture::LoadTexture(BALL_SPRITE, "C:\\Aneury\\2D-ENGINE\\bin\\Debug\\ball.bmp");
  
    ////FOR DOODLE
   Texture::LoadTexture(DOODLE_SPRITE, "C:\\Aneury\\2D-ENGINE\\bin\\Debug\\doodle.bmp");
   Texture::LoadTexture(PLATFORM_SPRITE, "C:\\Aneury\\2D-ENGINE\\bin\\Debug\\platform.bmp");

    ////FOR SNAKE
   Texture::LoadTexture(GREEN_SPRITE, "C:\\Aneury\\2D-ENGINE\\bin\\Debug\\green.bmp");
   Texture::LoadTexture(RED_SPRITE, "C:\\Aneury\\2D-ENGINE\\bin\\Debug\\red.bmp");
   Texture::LoadTexture(WHITE_SPRITE, "C:\\Aneury\\2D-ENGINE\\bin\\Debug\\white.bmp");


   window->getGSM()->addState(DOODLE_JUMP, new DoodleState());
   window->getGSM()->addState(ARKANOID_STATE, new ArkanoidGame());
   window->getGSM()->addState(SNAKE_STATE, new SnakeState());
   

   
   window->getGSM()->setState(SNAKE_STATE);

 
   while(window->isRunning())
   {
       window->PollEvent();
       window->setClearColor(0x43, 0x43, 0x43);
       window->Clear();
       window->UpdateScreen();
   }
 

}