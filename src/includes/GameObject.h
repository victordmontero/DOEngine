#pragma once

#include "abstract/AbstractWindow.h"
#include <string>

using doengine::AbstractWindow;

class GameObject
{
  protected:
    AbstractWindow* window;
    bool renderable;
    bool solid;
    int layer;

    std::string sprite_id;
    std::string texture_id;

  public:
    GameObject(AbstractWindow* window) : window(window)
    {
    }

    virtual ~GameObject()
    {
    }
    virtual void Update(float timer = 0) = 0;
    virtual void Render() = 0;
};