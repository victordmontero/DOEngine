#ifndef DOENGINE_SDL_INCLUDES_HPP_DEFINED
#define DOENGINE_SDL_INCLUDES_HPP_DEFINED

#ifdef DOENGINE_TESTING
#include "mocks/SDLMock.h"
#else
extern "C"
{
#include <SDL.h>
#include <SDL_error.h>
#include <SDL_events.h>
#include <SDL_image.h>
#include <SDL_joystick.h>
#include <SDL_log.h>
#include <SDL_ttf.h>
}
#endif

#endif