 
#include "Window.h"
#include "Texture.h"
#include "Grids.h"
#include <iostream>
#include <Vector.h>
#include <map>
#include <string>
#include <memory>
 
int  main(int argc, char *argv[])
{ 
   std::shared_ptr<Window> window(new Window(600,600)); 
    while(window->IsRunning()==true)
    {
        window->PollEvent();
        window->Update();
        window->Render();
    } 
   return 0;
}
 



