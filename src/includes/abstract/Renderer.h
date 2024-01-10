#pragma once

#include "Color.h"

namespace doengine::gfx
{

class Renderer
{
  public:
    virtual bool isRenderOk() = 0;
    virtual void* getNativeRenderer() = 0;
    virtual void destroy() = 0;
    virtual void clear() = 0;
    virtual void setDrawColor(doengine::Color) = 0;
    virtual void present() = 0;
};

} // namespace doengine::gfx