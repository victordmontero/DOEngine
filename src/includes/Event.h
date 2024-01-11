#pragma once

// #include "DOEngine.h"
#include "abstract/AbstractWindow.h"
#include "abstract/EventHandler.h"
#include <vector>

using doengine::AbstractWindow;

struct Event
{
    static float timeElapsed;
    static std::vector<KeyDownEvent*> keydown;
    static std::vector<KeyUpEvent*> keyup;
    static std::vector<MouseMovementEvent*> mouse;
    static std::vector<MouseEvent*> mouseEvent;
    static std::vector<JoyButtonUpEvent*> joyButtonUpList;
    static std::vector<JoyButtonDownEvent*> joyButtonDownList;
    static std::vector<JoyButtonTriggerEvent*> joyButtonTriggerList;

    static void getMousePosition(int* x, int* y);

    static void PollEvent(AbstractWindow* window);
    static void AddKeydownEventListener(KeyDownEvent* ev);
    static void RemoveKeydownEventListener(KeyDownEvent* ev);
    static void AddMouseEvent(MouseEvent* event);

    static bool mousePressed;
    static bool mouseReleased;
    static bool keyDown;
    static bool keyUp;
};
