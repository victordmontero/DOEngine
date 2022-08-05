
#include <Window.h>
#include <Texture.h>
#include <Grids.h>
#include <iostream>
#include <Vector.h>
#include <memory>


int  main(int argc, char *argv[])
{ 

    std::shared_ptr<Window> window(new Window(600, 600));
    while(window->IsRunning())
    {
        window->PollEvent();
        window->Update();
        window->Render();
    }
   return 0;
}
