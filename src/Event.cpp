#include "Event.h"
#include "Window.h"
Event *Event::single =nullptr;
void Event::addKeyboardObserver(KeyboardObserver *ob){
    this->keyboard_observers.emplace_back(ob);
}
void Event::addMouseObserver(MouseObserver *mo){}
void Event::addTouchObserver(MouseObserver *to){}
 
void Event::removeKeyboardObserver(KeyboardObserver *ob)
{
   for(auto it : keyboard_observers){
       if(it == ob)
          {
              ///keyboard_observers.
              ///delete it;
          }
   }
}
void Event::removeMouseObserver(MouseObserver *mo){}
void Event::removeTouchObserver(MouseObserver *to){}
   
void Event::PollEvent()
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
         switch(event.type)
         {
             case SDL_QUIT:
             {
                    extern Window* window;
                    for(auto it : window_observers)
                        it->OnQuit();
                    window->Quit();
             }
             break;
             case SDL_KEYDOWN:
             {
                 keydown[event.key.keysym.sym]=true;
                 keyup[event.key.keysym.sym]=false;
                 for(auto it : keyboard_observers)
                 {
                     it->onKeyDown(keydown);
                 }
             }
             break;
            case SDL_KEYUP:
             {
                 keydown[event.key.keysym.sym]=false;
                 keyup[event.key.keysym.sym]=true;
                 for(auto it : keyboard_observers)
                 {
                     it->onKeyUp(keyup);
                 }
             }
             break;
         }
    }
}