#include <Window/Window.h>
#include <Texture/Texture.h>
#include <Drawable/Grids.h>
#include <iostream>
#include <Physics/Vector.h>

int  main(int argc, char *argv[])
{ 
#if 0
	Vector<int> fl;
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