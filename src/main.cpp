#include <Window.h>
#include <Texture.h>
#include <Grids.h>
#include <iostream>
#include <Vector.h>


#include <map>
#include <string>

int  main(int argc, char *argv[])
{ 
   Window *window = new Window(600,600); 
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
