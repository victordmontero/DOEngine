#pragma once

#include "gmock/gmock.h"
namespace doengine::mocks
{

class SDLInterface
{
  public:
    virtual uint32_t SDL_GetTicks() = 0;
    virtual void SDL_Delay(uint32_t) = 0;
};

class SDLMock : public SDLInterface
{
  public:
    MOCK_METHOD(uint32_t, SDL_GetTicks, (), (override));
    MOCK_METHOD(void, SDL_Delay, (uint32_t a), (override));
};

} // namespace doengine::mocks

extern doengine::mocks::SDLMock* sdlMock;

typedef uint32_t Uint32;
Uint32 SDL_GetTicks();
void SDL_Delay(Uint32);
void SetSDLMock(doengine::mocks::SDLMock* newSdlMock);