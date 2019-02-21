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
   Texture::LoadTexture(ARKANOID_SPRITE, "sprite-arkanoid.bmp");
   Texture::LoadTexture(BALL_SPRITE, "ball.bmp");
  
    ////FOR DOODLE
//    Texture::LoadTexture(DOODLE_SPRITE, "doodle.bmp");
//    Texture::LoadTexture(PLATFORM_SPRITE, "platform.bmp");

//     ////FOR SNAKE
//    Texture::LoadTexture(GREEN_SPRITE, "green.bmp");
//    Texture::LoadTexture(RED_SPRITE, "red.bmp");
//    Texture::LoadTexture(WHITE_SPRITE, "white.bmp");


//    window->getGSM()->addState(DOODLE_JUMP, new DoodleState());
   window->getGSM()->addState(ARKANOID_STATE, new ArkanoidGame());
//    window->getGSM()->addState(SNAKE_STATE, new SnakeState());
   

   
   window->getGSM()->setState(ARKANOID_STATE);

 
   while(window->isRunning())
   {
       window->PollEvent();
       window->setClearColor(0x43, 0x43, 0x43);
       window->Clear();
       window->UpdateScreen();
   }
 

}