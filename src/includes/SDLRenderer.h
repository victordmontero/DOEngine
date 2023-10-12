#pragma once

extern "C" {
#include<SDL.h>
}

#include "abstract/Renderer.h"

using Renderer = doengine::gfx::Renderer;

class SDLRenderer : public Renderer
{
public:
    SDLRenderer(SDL_Renderer* nativeRenderer);
    virtual bool isRenderOk() override;
    virtual void* getNativeRenderer() override;
    virtual void destroy() override;
    
private:
    SDL_Renderer* renderer;
};