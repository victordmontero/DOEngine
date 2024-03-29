#pragma once

#include <map>
#include <string>
// #include "Window.h"
#include "GameState.h"
#include "abstract/AbstractWindow.h"

using doengine::AbstractWindow;
// class GameState;

class GameStateManager
{
    AbstractWindow* window;
    std::map<int, GameState*> states;
    int current_state;

  public:
    GameStateManager(AbstractWindow* window) : window(window)
    {
    }

    virtual ~GameStateManager()
    {
    }

    virtual void AddState(int state_id, GameState* object);
    virtual void RemoveState(int state_id);
    virtual void SetState(int state_id);

    virtual void Update(float elapsed);
    virtual void Render();
};