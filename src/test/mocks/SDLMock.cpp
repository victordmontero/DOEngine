#include "SDLMock.h"
#include <cstddef>

using namespace doengine::mocks;

SDLMock* sdlMock = nullptr;

void SetSDLMock(SDLMock* newSdlMock)
{
    sdlMock = newSdlMock;
}

int SDL_Init(Uint32 flags)
{
    return sdlMock->SDL_Init(flags);
}

SDL_Window* SDL_CreateWindow(const char* title, int x, int y, int w, int h,
                             Uint32 flags)
{
    return sdlMock->SDL_CreateWindow(title, x, y, w, h, flags);
}

SDL_Renderer* SDL_CreateRenderer(SDL_Window* window, int index, Uint32 flags)
{
    return sdlMock->SDL_CreateRenderer(window, index, flags);
}

int SDL_SetRenderDrawColor(SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b,
                           Uint8 a)
{
    return sdlMock->SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void SDL_RenderPresent(SDL_Renderer* renderer)
{
    sdlMock->SDL_RenderPresent(renderer);
}

int SDL_RenderClear(SDL_Renderer* renderer)
{
    return sdlMock->SDL_RenderClear(renderer);
}

int SDL_SetWindowFullscreen(SDL_Window* window, Uint32 flags)
{
    return sdlMock->SDL_SetWindowFullscreen(window, flags);
}

void SDL_SetWindowSize(SDL_Window* window, int w, int h)
{
}

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

const Uint8* SDL_GetKeyboardState(int* numkeys)
{
    return sdlMock->SDL_GetKeyboardState(numkeys);
}

SDL_JoystickID SDL_JoystickGetDeviceInstanceID(int index)
{
    return sdlMock->SDL_JoystickGetDeviceInstanceID(index);
}

SDL_JoystickID SDL_JoystickInstanceID(SDL_Joystick* joystick)
{
    return sdlMock->SDL_JoystickInstanceID(joystick);
}

SDL_bool SDL_JoystickHasLED(SDL_Joystick* Joystick)
{
    return sdlMock->SDL_JoystickHasLED(Joystick);
}

SDL_bool SDL_JoystickHasRumble(SDL_Joystick* Joystick)
{
    return sdlMock->SDL_JoystickHasRumble(Joystick);
}

int SDL_JoystickGetPlayerIndex(SDL_Joystick* joystick)
{
    return sdlMock->SDL_JoystickGetPlayerIndex(joystick);
}

Sint16 SDL_JoystickGetAxis(SDL_Joystick* joystick, int axis)
{
    return sdlMock->SDL_JoystickGetAxis(joystick, axis);
}

Uint8 SDL_JoystickGetButton(SDL_Joystick* joystick, int button)
{
    return sdlMock->SDL_JoystickGetButton(joystick, button);
}

int SDL_JoystickNumAxes(SDL_Joystick* joystick)
{
    return sdlMock->SDL_JoystickNumAxes(joystick);
}

int SDL_JoystickNumButtons(SDL_Joystick* joystick)
{
    return sdlMock->SDL_JoystickNumButtons(joystick);
}

SDL_JoystickPowerLevel SDL_JoystickCurrentPowerLevel(SDL_Joystick* joystick)
{
    return sdlMock->SDL_JoystickCurrentPowerLevel(joystick);
}

int SDL_JoystickRumble(SDL_Joystick* joystick, Uint16 left, Uint16 right,
                       Uint32 duration_ms)
{
    return sdlMock->SDL_JoystickRumble(joystick, left, right, duration_ms);
}

void SDL_JoystickSetPlayerIndex(SDL_Joystick* joystick, int player_index)
{
    sdlMock->SDL_JoystickSetPlayerIndex(joystick, player_index);
}

int SDL_JoystickSetLED(SDL_Joystick* joystick, Uint8 red, Uint8 green,
                       Uint8 blue)
{
    return sdlMock->SDL_JoystickSetLED(joystick, red, green, blue);
}

const char* SDL_JoystickNameForIndex(int device_index)
{
    return sdlMock->SDL_JoystickNameForIndex(device_index);
}

const char* SDL_JoystickName(SDL_Joystick* joystick)
{
    return sdlMock->SDL_JoystickName(joystick);
}

SDL_Joystick* SDL_JoystickOpen(int device_index)
{
    return sdlMock->SDL_JoystickOpen(device_index);
}

void SDL_JoystickClose(SDL_Joystick* joystick)
{
    return sdlMock->SDL_JoystickClose(joystick);
}

const char* SDL_GetError(void)
{
    return sdlMock->SDL_GetError();
}

int SDL_RenderCopyEx(SDL_Renderer* renderer, SDL_Texture* texture,
                     const SDL_Rect* srcrect, const SDL_Rect* dstrect,
                     const double angle, const SDL_Point* center,
                     const SDL_RendererFlip flip)
{
    return sdlMock->SDL_RenderCopyEx(renderer, texture, srcrect, dstrect, angle,
                                     center, flip);
}

int SDL_RenderCopy(SDL_Renderer* renderer, SDL_Texture* texture,
                   const SDL_Rect* srcrect, const SDL_Rect* dstrect)
{
    return sdlMock->SDL_RenderCopy(renderer, texture, srcrect, dstrect);
}

int SDL_GetCurrentDisplayMode(int displayIndex, SDL_DisplayMode* mode)
{
    return sdlMock->SDL_GetCurrentDisplayMode(displayIndex, mode);
}

void SDL_DestroyRenderer(SDL_Renderer* renderer)
{
    sdlMock->SDL_DestroyRenderer(renderer);
}

int SDL_RenderDrawPoint(SDL_Renderer* renderer, int x, int y)
{
    return sdlMock->SDL_RenderDrawPoint(renderer, x, y);
}

int SDL_RenderDrawLine(SDL_Renderer* renderer, int x1, int y1, int x2, int y2)
{
    return sdlMock->SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

int SDL_RenderDrawRect(SDL_Renderer* renderer, const SDL_Rect* rect)
{
    return sdlMock->SDL_RenderDrawRect(renderer, rect);
}

int SDL_RenderFillRect(SDL_Renderer* renderer, const SDL_Rect* rect)
{
    return sdlMock->SDL_RenderFillRect(renderer, rect);
}

SDL_RWops* SDL_RWFromFile(const char* file, const char* mode)
{
    return sdlMock->SDL_RWFromFile(file, mode);
}

SDL_Surface* SDL_LoadBMP_RW(SDL_RWops* src, int freesrc)
{
    return sdlMock->SDL_LoadBMP_RW(src, freesrc);
}

SDL_Surface* SDL_ConvertSurface(SDL_Surface* src, const SDL_PixelFormat* fmt,
                                Uint32 flags)
{
    return sdlMock->SDL_ConvertSurface(src, fmt, flags);
}

int SDL_GetTextureColorMod(SDL_Texture* texture, Uint8* r, Uint8* g, Uint8* b)
{
    return sdlMock->SDL_GetTextureColorMod(texture, r, g, b);
}

SDL_Texture* SDL_CreateTexture(SDL_Renderer* renderer, Uint32 format,
                               int access, int w, int h)
{
    return sdlMock->SDL_CreateTexture(renderer, format, access, w, h);
}

int SDL_SetRenderTarget(SDL_Renderer* renderer, SDL_Texture* texture)
{
    return sdlMock->SDL_SetRenderTarget(renderer, texture);
}

/****** SDL_TTF *********/

int TTF_Init(void)
{
    return sdlMock->TTF_Init();
}

int TTF_SetFontSize(TTF_Font* font, int ptsize)
{
    return sdlMock->TTF_SetFontSize(font, ptsize);
}

void TTF_CloseFont(TTF_Font* font)
{
    sdlMock->TTF_CloseFont(font);
}

TTF_Font* TTF_OpenFont(const char* file, int ptsize)
{
    return sdlMock->TTF_OpenFont(file, ptsize);
}

SDL_Surface* TTF_RenderText_Shaded(TTF_Font* font, const char* text,
                                   SDL_Color fg, SDL_Color bg)
{
    return sdlMock->TTF_RenderText_Shaded(font, text, fg, bg);
}

SDL_Texture* SDL_CreateTextureFromSurface(SDL_Renderer* renderer,
                                          SDL_Surface* surface)
{
    return sdlMock->SDL_CreateTextureFromSurface(renderer, surface);
}

int SDL_QueryTexture(SDL_Texture* texture, Uint32* format, int* access, int* w,
                     int* h)
{
    return sdlMock->SDL_QueryTexture(texture, format, access, w, h);
}

void SDL_DestroyTexture(SDL_Texture* texture)
{
    sdlMock->SDL_DestroyTexture(texture);
}

void SDL_FreeSurface(SDL_Surface* surface)
{
    sdlMock->SDL_FreeSurface(surface);
}

int TTF_SizeText(TTF_Font* font, const char* text, int* w, int* h)
{
    return sdlMock->TTF_SizeText(font, text, w, h);
}
