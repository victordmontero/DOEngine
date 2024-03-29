#pragma once

#include "Canvas.h"
#include "GameObject.h"
#include "GameState.h"
#include "abstract/EventHandler.h"

class CanvasTestState : public GameState, MouseEvent
{

    int pencil_size = 20;
    Canvas* pencil1;

  public:
    CanvasTestState(doengine::AbstractWindow* w) : window(w)
    {
    }

    virtual void OnEnter() override;
    virtual void OnExit() override;
    virtual void Update(float elapsed) override;
    virtual void Render() override;

 
   

  private:
    doengine::AbstractWindow* window;
};