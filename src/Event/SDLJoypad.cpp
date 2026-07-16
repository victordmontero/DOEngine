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


#include "SDLJoypad.h"
#include <cstddef>

namespace doengine
{
namespace devices
{

const std::string SDLJoypad::DEFAULT_JOYPAD_NAME = "NOT_FOUND";

SDLJoypad::SDLJoypad(SDL_Joystick* joystick) : joystick(joystick), index(255)
{
}

int SDLJoypad::getId() const
{
    return static_cast<int>(SDL_JoystickInstanceID(joystick));
}

void SDLJoypad::getName(std::string& name)
{
    const char* strName = SDL_JoystickName(joystick);
    if (strName != nullptr)
    {
        name = strName;
    }
    else
    {
        name = DEFAULT_JOYPAD_NAME;
    }
}

PowerLevel SDLJoypad::getPowerLevel() const
{
    SDL_JoystickPowerLevel powerLevel = SDL_JoystickCurrentPowerLevel(joystick);

    return static_cast<PowerLevel>(powerLevel);
}

std::size_t SDLJoypad::getNumberOfButtons() const
{
    return SDL_JoystickNumButtons(joystick);
}

std::size_t SDLJoypad::getNumberOfAxes() const
{
    return SDL_JoystickNumAxes(joystick);
}

int SDLJoypad::getPlayerIndex() const
{
    return SDL_JoystickGetPlayerIndex(joystick);
}

bool SDLJoypad::hasLED() const
{
    return static_cast<bool>(SDL_JoystickHasLED(joystick));
}

bool SDLJoypad::hasRumble() const
{
    return static_cast<bool>(SDL_JoystickHasRumble(joystick));
}

void SDLJoypad::getJoypadButtonsPressed(std::vector<bool>& buttonsPressed)
{
    buttonsPressed.clear();
    const int btns = getNumberOfButtons();
    for (int i = 0; i < btns; i++)
    {
        buttonsPressed.push_back(SDL_JoystickGetButton(joystick, i));
    }
}

short SDLJoypad::getAxisValue(int axis) const
{
    return SDL_JoystickGetAxis(joystick, axis);
}

void SDLJoypad::startRumble(unsigned short left, unsigned short right,
                            unsigned int duration_ms)
{
    if (hasRumble())
    {
        SDL_JoystickRumble(joystick, left, right, duration_ms);
    }
}

void SDLJoypad::setLEDColor(const Color& color)
{
    if (hasLED())
    {
        SDL_JoystickSetLED(joystick, color.r, color.g, color.b);
    }
}

void SDLJoypad::setPlayerIndex(int index)
{
    SDL_JoystickSetPlayerIndex(joystick, index);
    this->index = index;
}

SDL_Joystick* SDLJoypad::getNativeJoystick() const
{
    return joystick;
}

} // namespace devices
} // namespace doengine