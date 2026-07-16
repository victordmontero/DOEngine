/*
 * ============================================================================
 * DOEngine
 * Copyright (c) 2026 Victor D. Montero, Aneury Perez
 * All Rights Reserved.
 *
 * Licensed under the MIT License.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * 1. The above copyright notice, this license notice, and this disclaimer
 *    MUST be included in all copies or substantial portions of the Software.
 *
 * 2. This notice may not be removed from the original source files distributed
 *    as part of this project.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES, OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * ============================================================================
 */


#include "SDLMouse.h"
#include "DOEngine_SDL_includes.h"

namespace doengine
{
namespace devices
{

SDLMouse::SDLMouse(unsigned int which, unsigned int bMask, Point p)
    : buttonMask(bMask), which(which), position{p}
{
    updateValues();
}

unsigned int SDLMouse::getMouseId() const
{
    return which;
}

bool SDLMouse::isRightClick() const
{
    return (buttonMask & SDL_BUTTON_RMASK) == SDL_BUTTON_RMASK;
}

bool SDLMouse::isLeftClick() const
{
    return (buttonMask & SDL_BUTTON_LMASK) == SDL_BUTTON_LMASK;
}

bool SDLMouse::isMiddleClick() const
{
    return (buttonMask & SDL_BUTTON_MMASK) == SDL_BUTTON_MMASK;
}

void SDLMouse::getPosition(Point& point)
{
    point.x = position.x;
    point.y = position.y;
}

const Point& SDLMouse::getMotionPosition()const
{
    return motion;
}

const Point& SDLMouse::getPosition() const
{
    return position;
}

void SDLMouse::getButtonStateBitset(
    std::bitset<Mouse::BUTTONS_COUNT>& buttonsState) const
{
    buttonsState.set(buttonMask);
}

void SDLMouse::updateValues()
{
    buttonMask = SDL_GetMouseState(&position.x, &position.y);
}

const Point& SDLMouse::getWheelScroll() const
{
    return scroll;
}

void SDLMouse::setScroll(int x, int y)
{
    scroll.x =x;
    scroll.y =y;
}

Rect Mouse::getMousePosition()
{
    Rect rect;
    rect.w = 1;
    rect.h = 1;
    SDL_GetMouseState(&rect.x, &rect.y);
    return rect;
}

uint8_t Mouse::getButtonPressed()
{
    unsigned char ret = 0x00;
    Rect rect;
    rect.w = 1;
    rect.h = 1;
    auto mouse = SDL_GetMouseState(&rect.x, &rect.y);
    if(mouse&SDL_BUTTON(SDL_BUTTON_LEFT))
        ret |= (uint8_t)Mouse::MouseButtonDown::Left;
    if(mouse&SDL_BUTTON(SDL_BUTTON_RIGHT))
        ret |= (uint8_t)Mouse::MouseButtonDown::Right;
    if(mouse&SDL_BUTTON(SDL_BUTTON_MIDDLE))
        ret |= (uint8_t)Mouse::MouseButtonDown::Center;

    return ret;
}


} // namespace devices
} // namespace doengine