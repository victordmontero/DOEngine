#pragma once 

#include "DOEngine.h"

struct Event{
    
    static float timeElapsed;
    static std::vector<KeyDownEvent*> keydown;
    static std::vector<KeyUpEvent*> keyup;
    static std::vector<MouseMovementEvent*> mouse;

    static void PollEvent(Window *window);
    static void AddKeydownEventListener(KeyDownEvent* ev);
    static void RemoveKeydownEventListener(KeyDownEvent* ev);
    
    static bool mousePressed;
    static bool mouseReleased;
    static bool keyDown;
    static bool keyUp;

};

