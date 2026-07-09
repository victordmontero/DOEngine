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


#include "UI.h"
#include "Mouse.h"
#include "Application.h"

#include "DOEngine_SDL_includes.h"

namespace doengine
{

MouseBtn ToMouseBtn(Uint8 sdlButton)
{
    switch (sdlButton)
    {
        case SDL_BUTTON_LEFT:   return MouseBtn::Left;
        case SDL_BUTTON_RIGHT:  return MouseBtn::Right;
        case SDL_BUTTON_MIDDLE: return MouseBtn::Middle;
        default:                return MouseBtn::None;
    }
}

BorderPress GetBorderPressState(
    const SDL_Rect& r,
    int             thickness = 2
)
{
    BorderPress result{};
    result.pressed = false;
    result.border  = Border::None;
    result.button  = MouseBtn::None;

    int mx, my;
    Uint32 buttons = SDL_GetMouseState(&mx, &my);

    // No button pressed at all
    if (buttons == 0)
        return result;

    // Inside rectangle?
    if (mx < r.x || mx > r.x + r.w ||
        my < r.y || my > r.y + r.h)
        return result;

    bool left   = mx >= r.x && mx <= r.x + thickness;
    bool right  = mx >= r.x + r.w - thickness && mx <= r.x + r.w;
    bool top    = my >= r.y && my <= r.y + thickness;
    bool bottom = my >= r.y + r.h - thickness && my <= r.y + r.h;

    // Optional: exclude corners
    if ((left || right) && (top || bottom))
        return result;

    if (left)        result.border = Border::Left;
    else if (right)  result.border = Border::Right;
    else if (top)    result.border = Border::Top;
    else if (bottom) result.border = Border::Bottom;
    else             return result;

    // Detect which button is pressed
    if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
        result.button = MouseBtn::Left;
    else if (buttons & SDL_BUTTON(SDL_BUTTON_RIGHT))
        result.button = MouseBtn::Right;
    else if (buttons & SDL_BUTTON(SDL_BUTTON_MIDDLE))
        result.button = MouseBtn::Middle;
    else
        return result;

    result.pressed = true;
    result.x = mx;
    result.y = my;

    return result;
}


UIPanel::UIPanel()
{
    backgroundColor.r = 0x43;
    backgroundColor.g = 0x43;
    backgroundColor.b = 0x43;
    backgroundColor.a = 255;
    this->size.w = 200;
    this->size.h = 200;
    renderer = Application::getApplication()->getRender();
}

UIPanel::~UIPanel()
{

}

void UIPanel::Draw()
{
    renderer->DrawFillRect(size, backgroundColor);
    if(mouseOverPanelBorder){
        getRenderer()->DrawFillRect(size, doengine::Colors::yellow1);
        getRenderer()->DrawRect(size, doengine::Colors::red);
    }
}

void UIPanel::Update()
{
    mouseOverPanelBorder = false;
}

}