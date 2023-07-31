#pragma once 

#include "DOEngine.h"

struct Event{
    
    static float timeElapsed;
    static std::vector<KeyDownEvent*> keydown;
    static std::vector<KeyUpEvent*> keyup;
    static std::vector<MouseMovementEvent*> mouse;
    static std::vector<MouseEvent*> mouseEvent;

    
    static void getMousePosition(int *x, int *);

    static void PollEvent(Window *window);
    static void AddKeydownEventListener(KeyDownEvent* ev);
    static void RemoveKeydownEventListener(KeyDownEvent* ev);
    static void AddMouseEvent(MouseEvent *event);
    
    static bool mousePressed;
    static bool mouseReleased;
    static bool keyDown;
    static bool keyUp;

};

