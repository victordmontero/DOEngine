#pragma once

#include "gmock/gmock.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL_ttf.h>

namespace doengine
{
namespace mocks
{

class SDLMock
{
  public:
    MOCK_METHOD(int, SDL_Init, (Uint32 flags));
    MOCK_METHOD(SDL_Window*, SDL_CreateWindow,
                (const char* title, int x, int y, int w, int h, Uint32 flags));
    MOCK_METHOD(SDL_Renderer*, SDL_CreateRenderer,
                (SDL_Window * window, int index, Uint32 flags));
    MOCK_METHOD(int, SDL_SetRenderDrawColor,
                (SDL_Renderer * renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a));
    MOCK_METHOD(void, SDL_RenderPresent, (SDL_Renderer * renderer));
    MOCK_METHOD(int, SDL_RenderClear, (SDL_Renderer * renderer));
    MOCK_METHOD(int, SDL_SetWindowFullscreen,
                (SDL_Window * window, Uint32 flags));
    MOCK_METHOD(void, SDL_SetWindowSize, (SDL_Window * window, int w, int h));
    MOCK_METHOD(Uint32, SDL_GetTicks, ());
    MOCK_METHOD(void, SDL_Delay, (Uint32));
    MOCK_METHOD(void, SDL_Log, (const char*));
    MOCK_METHOD(int, SDL_PollEvent, (SDL_Event*));
    MOCK_METHOD(Uint32, SDL_GetMouseState, (int*, int*));
    MOCK_METHOD(const Uint8*, SDL_GetKeyboardState, (int*));
    MOCK_METHOD(SDL_JoystickID, SDL_JoystickGetDeviceInstanceID, (int));
    MOCK_METHOD(SDL_JoystickID, SDL_JoystickInstanceID, (SDL_Joystick*));
    MOCK_METHOD(SDL_bool, SDL_JoystickHasLED, (SDL_Joystick*));
    MOCK_METHOD(SDL_bool, SDL_JoystickHasRumble, (SDL_Joystick*));
    MOCK_METHOD(int, SDL_JoystickGetPlayerIndex, (SDL_Joystick*));
    MOCK_METHOD(Sint16, SDL_JoystickGetAxis, (SDL_Joystick*, int));
    MOCK_METHOD(Uint8, SDL_JoystickGetButton, (SDL_Joystick*, int));
    MOCK_METHOD(int, SDL_JoystickNumAxes, (SDL_Joystick*));
    MOCK_METHOD(int, SDL_JoystickNumButtons, (SDL_Joystick*));
    MOCK_METHOD(SDL_JoystickPowerLevel, SDL_JoystickCurrentPowerLevel,
                (SDL_Joystick*));
    MOCK_METHOD(int, SDL_JoystickRumble,
                (SDL_Joystick*, Uint16, Uint16, Uint32));
    MOCK_METHOD(void, SDL_JoystickSetPlayerIndex, (SDL_Joystick*, int));
    MOCK_METHOD(int, SDL_JoystickSetLED, (SDL_Joystick*, Uint8, Uint8, Uint8));
    MOCK_METHOD(const char*, SDL_JoystickNameForIndex, (int device_index));
    MOCK_METHOD(const char*, SDL_JoystickName, (SDL_Joystick*));
    MOCK_METHOD(SDL_Joystick*, SDL_JoystickOpen, (int device_index));
    MOCK_METHOD(void, SDL_JoystickClose, (SDL_Joystick * joystick));
    MOCK_METHOD(const char*, SDL_GetError, ());
    MOCK_METHOD(int, SDL_RenderCopyEx,
                (SDL_Renderer*, SDL_Texture*, const SDL_Rect*, const SDL_Rect*,
                 const double, const SDL_Point*, const SDL_RendererFlip));
    MOCK_METHOD(int, SDL_RenderCopy,
                (SDL_Renderer*, SDL_Texture*, const SDL_Rect*,
                 const SDL_Rect*));
    MOCK_METHOD(int, SDL_GetCurrentDisplayMode,
                (int displayIndex, SDL_DisplayMode* mode));

    MOCK_METHOD(void, SDL_DestroyRenderer, (SDL_Renderer * renderer), ());
    MOCK_METHOD(int, SDL_RenderDrawPoint,
                (SDL_Renderer * renderer, int x, int y), ());
    MOCK_METHOD(int, SDL_RenderDrawLine,
                (SDL_Renderer * renderer, int x1, int y1, int x2, int y2), ());
    MOCK_METHOD(int, SDL_RenderDrawRect,
                (SDL_Renderer * renderer, const SDL_Rect* rect), ());
    MOCK_METHOD(int, SDL_RenderFillRect,
                (SDL_Renderer * renderer, const SDL_Rect* rect), ());

    MOCK_METHOD(SDL_RWops*, SDL_RWFromFile,
                (const char* file, const char* mode), ());
    MOCK_METHOD(SDL_Surface*, SDL_LoadBMP_RW, (SDL_RWops * src, int freesrc),
                ());
    MOCK_METHOD(SDL_Surface*, SDL_ConvertSurface,
                (SDL_Surface * src, const SDL_PixelFormat* fmt, Uint32 flags),
                ());
    MOCK_METHOD(int, SDL_GetTextureColorMod,
                (SDL_Texture * texture, Uint8* r, Uint8* g, Uint8* b), ());
    MOCK_METHOD(SDL_Texture*, SDL_CreateTexture,
                (SDL_Renderer * renderer, Uint32 format, int access, int w,
                 int h),
                ());
    MOCK_METHOD(int, SDL_SetRenderTarget,
                (SDL_Renderer * renderer, SDL_Texture* texture), ());

    /****** SDL_TTF *********/
    MOCK_METHOD(int, TTF_Init, ());
    MOCK_METHOD(int, TTF_SetFontSize, (TTF_Font * font, int ptsize), ());
    MOCK_METHOD(void, TTF_CloseFont, (TTF_Font * font), ());
    MOCK_METHOD(TTF_Font*, TTF_OpenFont, (const char* file, int ptsize), ());
    MOCK_METHOD(SDL_Surface*, TTF_RenderText_Shaded,
                (TTF_Font * font, const char* text, SDL_Color fg, SDL_Color bg),
                ());
    MOCK_METHOD(SDL_Texture*, SDL_CreateTextureFromSurface,
                (SDL_Renderer * renderer, SDL_Surface* surface), ());
    MOCK_METHOD(int, SDL_QueryTexture,
                (SDL_Texture * texture, Uint32* format, int* access, int* w,
                 int* h),
                ());
    MOCK_METHOD(void, SDL_DestroyTexture, (SDL_Texture * texture), ());
    MOCK_METHOD(void, SDL_FreeSurface, (SDL_Surface * surface), ());
    MOCK_METHOD(int, TTF_SizeText,
                (TTF_Font * font, const char* text, int* w, int* h), ());
};

} // namespace mocks
} // namespace doengine

extern doengine::mocks::SDLMock* sdlMock;
void SetSDLMock(doengine::mocks::SDLMock* newSdlMock);

// int TTF_Init(void);
