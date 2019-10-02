#include <memory>

#include "Window.h"
#include "Texture.h"
#include "BlockObject.h"
#include "Map.h"
#include "GeometricRender.h"
#include "Event.h"
#include "UDP.h"
Window *window;


int main(int argc, char *argv[])
{

   window = new Window(900,600,"test");

   while(window->isRunning())
   {
       window->PollEvent();
       window->setClearColor(0x43, 0x43, 0x43);
       window->Clear();
       window->UpdateScreen();
   }
    delete window;
    window = nullptr;
    return 0;
}