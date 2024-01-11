#include "SDLMock.h"

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

void SetSDLMock(SDLMock* newSdlMock)
{
    sdlMock = newSdlMock;
}