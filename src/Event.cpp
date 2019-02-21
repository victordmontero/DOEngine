#include "Event.h"
#include "Window.h"
Event *Event::single = nullptr;
void Event::addKeyboardObserver(KeyboardObserver *ob)
{
    this->keyboard_observers.emplace_back(ob);
}
void Event::addMouseObserver(MouseObserver *mo)
{
    this->mouse_observers.emplace_back(mo);
}
void Event::addTouchObserver(TouchObserver *to)
{
    this->touch_observers.emplace_back(to);
}

void Event::removeKeyboardObserver(KeyboardObserver *ob)
{
    //    for(auto it : keyboard_observers){
    //        if(it == ob)
    //           {
    //               ///keyboard_observers.
    //               ///delete it;
    //           }
    //    }
    for (auto it = keyboard_observers.begin(); it != keyboard_observers.begin(); it++)
    {
        if (*it == ob)
        {
            keyboard_observers.erase(it);
        }
    }
}
void Event::removeMouseObserver(MouseObserver *mo)
{
    for (auto it = mouse_observers.begin(); it != mouse_observers.begin(); it++)
    {
        if (*it == mo)
        {
            mouse_observers.erase(it);
        }
    }
}

void Event::removeTouchObserver(TouchObserver *to)
{
    for (auto it = touch_observers.begin(); it != touch_observers.begin(); it++)
    {
        if (*it == to)
        {
            touch_observers.erase(it);
        }
    }
}

void Event::PollEvent()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
        {
            extern Window *window;
            for (auto it : window_observers)
                it->OnQuit();
            window->Quit();
        }
        break;
        case SDL_KEYDOWN:
        {
            keydown[event.key.keysym.sym] = true;
            keyup[event.key.keysym.sym] = false;
            for (auto it : keyboard_observers)
            {
                it->onKeyDown(keydown);
            }
        }
        break;
        case SDL_KEYUP:
        {
            keydown[event.key.keysym.sym] = false;
            keyup[event.key.keysym.sym] = true;
            for (auto it : keyboard_observers)
            {
                it->onKeyUp(keyup);
            }
        }
        break;
        }
    }
}