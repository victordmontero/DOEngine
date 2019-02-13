#include <memory>

#include "Window.h"
#include "Texture.h"
#include "BlockObject.h"
#include "Map.h"
#include "GeometricRender.h"
#include "Event.h"


Window *window;

struct KeyboardListener: public KeyboardObserver{
       virtual void onKeyDown(std::map<SDL_Keycode, bool>keys){
           SDL_Log("keyboard Down");
       }
   virtual void onKeyUp(std::map<SDL_Keycode, bool>keys){
       SDL_Log("Sdl_KEyboard UP");
   }
};



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
   window = new Window(900,600,"test");
   std::shared_ptr<KeyboardListener> listener(new KeyboardListener());
   window->addKeyListener(listener.get());
   while(window->isRunning())
   {
       window->PollEvent();
       window->setClearColor(0x43, 0x43, 0x43);
       window->Clear();
       window->UpdateScreen();
   }
    return 0;
}