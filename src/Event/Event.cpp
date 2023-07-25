
#include "DOEngine.h"

std::vector<KeyDownEvent*>       Event::keydown;
std::vector<KeyUpEvent*>         Event::keyup;
std::vector<MouseMovementEvent*> Event::mouse;
bool Event::mousePressed    = false;
bool Event::mouseReleased   = false;
bool Event::keyDown         = false;
bool Event::keyUp           = false;
float Event::timeElapsed    = 0.0f;

void Event::PollEvent(Window *window)
{
   SDL_Event event;
   while(SDL_PollEvent(&event))
   {
       switch(event.type)
       {
           case SDL_QUIT:
           {
               SDL_Log("Window quit");
               window->Quit();
               break;
           }
           case SDL_KEYDOWN:
           {
                SDL_Log("Window quit");
                window->Quit();
                mousePressed = false;
                mouseReleased= false;
                keyDown= true;
                keyUp= false;
               //SDL_Log("SDL_KEYDOWN");
           }break;
           case SDL_KEYUP:
                {
                mousePressed = false;
                mouseReleased= false;
                keyDown= false;
                keyUp= true;
                ////    SDL_Log("SDL_KEYUP");
                }break;                  /**< Key released */
           case SDL_TEXTEDITING:
                {
                    ///SDL_Log("SDL_TEXTEDITING");
                }break;            /**< Keyboard text editing (composition) */
           case SDL_TEXTINPUT:
                {
                    ///SDL_Log("SDL_TEXTEDITING");
                }break;              /**< Keyboard text input */
            case SDL_MOUSEMOTION :
                {
                   /// SDL_Log("SDL_MOUSEMOTION");
                }break; 
            case  SDL_MOUSEBUTTONDOWN:
             {
           ///     SDL_Log("SDL_MOUSEBUTTONDOWN");
                mousePressed = true;
                mouseReleased= false;
                keyDown= false;
                keyUp= false;
              }break; 
            case SDL_MOUSEBUTTONUP:
            {
              /// SDL_Log("SDL_MOUSEBUTTONUP");
                mousePressed = false;
                mouseReleased= true;
                keyDown= false;
                keyUp= false;


            }break; 
           case SDL_MOUSEWHEEL:
            {
            ////    SDL_Log("SDL_MOUSEWHEEL");
            }break; 
        default:
            mousePressed = false;
            mouseReleased= false;
            keyDown= false;
            keyUp= false;break;
       }

     /*if(keyDown==true && keydown.size()>0)
     {
        for(auto it : keydown)
           it->OnKeydown(event.key.keysym.sym);
        keyDown = false;
     }
     if(keyUp==true && keyup.size()>0)
     {
        for(auto it : keyup)
           it->OnKeyup(event.key.keysym.sym);
        keyUp = false;
     }*/

   }
}


void Event::AddKeydownEventListener(KeyDownEvent* ev)
{
    Event::keydown.emplace_back(ev);
}

void Event::RemoveKeydownEventListener(KeyDownEvent* ev)
{
    for (auto it : Event::keydown)
    {
       // if (it == ev)
       //     Event::keydown.erase(*it);
    }
}