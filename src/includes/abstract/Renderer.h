#pragma once

namespace doengine::gfx
{

class Renderer
{
  public:
    virtual bool isRenderOk() = 0;
    virtual void* getNativeRenderer() = 0;
    virtual void destroy() = 0;
};

} // namespace doengine::gfx