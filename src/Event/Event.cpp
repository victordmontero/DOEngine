
#include "Event.h"
#include "SDL_error.h"
#include "SDL_joystick.h"
#include "abstract/EventHandler.h"
#include <SDL_events.h>
#include <SDL_log.h>
#include <vector>

std::vector<KeyDownEvent*> Event::keydown;
std::vector<KeyUpEvent*> Event::keyup;
std::vector<MouseMovementEvent*> Event::mouse;
std::vector<MouseEvent*> Event::mouseEvent;
std::vector<JoyButtonUpEvent*> Event::joyButtonUpList;
std::vector<JoyButtonDownEvent*> Event::joyButtonDownList;
std::vector<JoyButtonTriggerEvent*> Event::joyButtonTriggerList;
bool Event::mousePressed = false;
bool Event::mouseReleased = false;
bool Event::keyDown = false;
bool Event::keyUp = false;
float Event::timeElapsed = 0.0f;

void Event::PollEvent(AbstractWindow* window)
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT: {
            SDL_Log("Window quit");
            window->Quit();
            break;
        }
        case SDL_KEYDOWN: {
            SDL_Log("Window quit");
            window->Quit();
            mousePressed = false;
            mouseReleased = false;
            keyDown = true;
            keyUp = false;
            // SDL_Log("SDL_KEYDOWN");
        }
        break;
        case SDL_KEYUP: {
            mousePressed = false;
            mouseReleased = false;
            keyDown = false;
            keyUp = true;
            ////    SDL_Log("SDL_KEYUP");
        }
        break; /**< Key released */
        case SDL_TEXTEDITING: {
            /// SDL_Log("SDL_TEXTEDITING");
        }
        break; /**< Keyboard text editing (composition) */
        case SDL_TEXTINPUT: {
            /// SDL_Log("SDL_TEXTEDITING");
        }
        break; /**< Keyboard text input */
        case SDL_MOUSEMOTION: {

            SDL_Point mouse;
            SDL_GetMouseState(&mouse.x, &mouse.y);
            /// SDL_Log("SDL_MOUSEMOTION x: %ld,  y:%ld", mouse.x, mouse.y);

            for (auto itMouse : Event::mouseEvent)
            {
                SDL_Log("Mouse Count = %ld", Event::mouseEvent.size());
                itMouse->MouseMove(mouse.x, mouse.y);
            }
        }
        break;
        case SDL_MOUSEBUTTONDOWN: {
            ///     SDL_Log("SDL_MOUSEBUTTONDOWN");
            mousePressed = true;
            mouseReleased = false;
            keyDown = false;
            keyUp = false;
            for (auto it : mouseEvent)
                it->MouseButtonDown(1);
        }
        break;
        case SDL_MOUSEBUTTONUP: {
            /// SDL_Log("SDL_MOUSEBUTTONUP");
            mousePressed = false;
            mouseReleased = true;
            keyDown = false;
            keyUp = false;
            for (auto it : mouseEvent)
                it->MouseButtonUp(1);
        }
        break;
        case SDL_MOUSEWHEEL: {
            ////    SDL_Log("SDL_MOUSEWHEEL");
        }
        break;
        case SDL_JOYAXISMOTION:
        case SDL_CONTROLLERAXISMOTION:
            SDL_Log("SDL_CONTROLLERAXISMOTION Axis %d, Value %d",
                    event.jaxis.axis, event.jaxis.value);
            break;
        case SDL_JOYBUTTONUP:
            SDL_Log("SDL_JOYBUTTONUP  %d", event.jbutton.button);
            break;
        case SDL_JOYBUTTONDOWN:
            SDL_Log("SDL_JOYBUTTONDOWN %d", event.jbutton.button);
            break;
        default:
            mousePressed = false;
            mouseReleased = false;
            keyDown = false;
            keyUp = false;
            break;
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

void Event::getMousePosition(int* x, int* y)
{
    SDL_GetMouseState(x, y);
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

void Event::AddMouseEvent(MouseEvent* event)
{
    Event::mouseEvent.push_back(event);
    /// SDL_Log("Adding EVent Handler %02x", event);
}