#include <memory>

#include "Window.h"
#include "Texture.h"
#include "BlockObject.h"
#include "Map.h"
Window *window;

int test_map[]=
{
    1, 1, 1, 1, 1,1, 1, 1, 1, 1,
    1, 1, 1, 1, 1,1, 1, 1, 1, 1,
    1, 1, 1, 1, 1,1, 1, 1, 1, 1,
    1, 1, 1, 1, 1,1, 1, 1, 1, 1,
    1, 1, 1, 1, 1,1, 1, 1, 1, 1,
    1, 1, 1, 1, 1,1, 1, 1, 1, 1
};



int main(int argc, char *argv[])
{
   window = new Window(1200,800,"test");
   Texture::texture_ints[1] = new Texture("C:\\Aneury\\2D-ENGINE\\bin\\Debug\\block.bmp", {0,0,0,0});
   
   while(window->isRunning())
   {
       window->PollEvent();
       window->setClearColor(0x43, 0x43, 0x43);
       window->Clear();
       
       window->UpdateScreen();
   }
    return 0;
}