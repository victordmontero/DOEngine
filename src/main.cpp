 
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
   std::shared_ptr<Window> window(new Window(1200,900)); 
    while(window->IsRunning()==true)
    {
        window->PollEvent()
              ->Update()
              ->Render();
    } 
   return 0;
}
 



