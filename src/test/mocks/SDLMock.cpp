#include "SDLMock.h"
#include <cstddef>

using namespace doengine::mocks;

SDLMock* sdlMock = nullptr;

Uint32 SDL_GetTicks()
{
    return sdlMock->SDL_GetTicks();
}

void SDL_Delay(Uint32 a)
{
    sdlMock->SDL_Delay(a);
}

void SDL_Log(const char* fmt, ...)
{
    sdlMock->SDL_Log(nullptr);
}

int SDL_PollEvent(SDL_Event* event)
{
    return sdlMock->SDL_PollEvent(event);
}

Uint32 SDL_GetMouseState(int* x, int* y)
{
    return sdlMock->SDL_GetMouseState(x, y);
}

void SetSDLMock(SDLMock* newSdlMock)
{
    sdlMock = newSdlMock;
}