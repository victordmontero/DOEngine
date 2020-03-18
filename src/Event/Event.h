#pragma once 
#include <SDL2/SDL.h>
#include <vector>

#include "EventHandler.h"
#include "../Window/Window.h"

struct Event{
    
    static std::vector<KeyDownEvent*> keydown;
    static std::vector<KeyUpEvent*> keyup;
    static std::vector<MouseMovementEvent*> mouse;

    static void PollEvent(Window *window);

    
    static bool mousePressed;
    static bool mouseReleased;
    static bool keyDown;
    static bool keyUp;

};

