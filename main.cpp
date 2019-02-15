#include <memory>

#include "Window.h"
#include "Texture.h"
#include "BlockObject.h"
#include "Map.h"
#include "GeometricRender.h"
#include "Event.h"
#include "Arkanoid.h"


Window *window;
 


int main(int argc, char *argv[])
{
   window = new Window(900,600,"test");
    
   Texture::LoadTexture(ARKANOID_SPRITE, "C:\\Aneury\\2D-ENGINE\\bin\\Debug\\sprite-arkanoid.bmp");
   Texture::LoadTexture(BALL_SPRITE, "C:\\Aneury\\2D-ENGINE\\bin\\Debug\\ball.bmp");
   window->getGSM()->addState(ARKANOID_STATE, new ArkanoidGame());
   window->getGSM()->setState(ARKANOID_STATE);

 
   while(window->isRunning())
   {
       window->PollEvent();
       window->setClearColor(0x43, 0x43, 0x43);
       window->Clear();
       window->UpdateScreen();
   }
    return 0;
}