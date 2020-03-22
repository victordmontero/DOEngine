#include "Window/Window.h"
#include "Texture/Texture.h"

#include "Drawable/Grids.h"
#include <iostream>

int main(int argc, char *argv[])
{ 
     Window *window = new Window(800,600); 
    while(window->IsRunning())
    {
        
        window->PollEvent();
        window->Update();

        window->Render();
    }
   delete window;
   window = nullptr;
 
   return 0;
}