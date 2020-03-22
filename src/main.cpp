#include "Window.h"
#include "Texture.h"
#include "Grids.h"
#include <iostream>
#include <Vector.h>



int  main(int argc, char *argv[])
{ 
    Vector<int> fl;
#if 0
   Window *window = new Window(400,600); 
    while(window->IsRunning())
    {
        window->PollEvent();
        window->Update();
        window->Render();
    }
   delete window;
   window = nullptr;  
#endif
   return 0;
}