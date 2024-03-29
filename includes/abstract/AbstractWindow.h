#pragma once

#include "Color.h"
#include "Renderer.h"

namespace doengine
{

class AbstractWindow
{
  public:
    virtual const bool IsRunning() const = 0;
    virtual gfx::Renderer* getRender() const = 0;

    virtual AbstractWindow* setFullScreen() = 0;
    virtual AbstractWindow* setWindowMode() = 0;

    virtual AbstractWindow* PollEvent() = 0;
    virtual AbstractWindow* Update() = 0;
    virtual AbstractWindow* Render() = 0;
    virtual AbstractWindow* Quit() = 0;

    virtual int getH() = 0;
    virtual int getW() = 0;

    virtual AbstractWindow* SetWindowPencilColor(Color color) = 0;
};

} // namespace doengine