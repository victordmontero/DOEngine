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


#pragma once

#include "DOEngine_SDL_includes.h"
#include "Joypad.h"

using doengine::devices::Joypad;
using doengine::devices::PowerLevel;

namespace doengine
{
namespace devices
{

class SDLJoypad : public Joypad
{
  public:
    static const std::string DEFAULT_JOYPAD_NAME;

    SDLJoypad(SDL_Joystick* joystick);

    virtual ~SDLJoypad() = default;

    virtual int getId() const override;
    virtual void getName(std::string& name) override;
    virtual PowerLevel getPowerLevel() const override;
    virtual std::size_t getNumberOfButtons() const override;
    virtual std::size_t getNumberOfAxes() const override;
    virtual int getPlayerIndex() const override;

    virtual bool hasLED() const override;
    virtual bool hasRumble() const override;
    virtual void getJoypadButtonsPressed(std::vector<bool>&) override;
    virtual short getAxisValue(int axis) const override;

    virtual void startRumble(unsigned short left, unsigned short right,
                             unsigned int duration_ms) override;
    virtual void setLEDColor(const Color&) override;
    virtual void setPlayerIndex(int index) override;

    SDL_Joystick* getNativeJoystick() const;

  private:
    SDL_Joystick* joystick;
    unsigned char index;
};

} // namespace devices
} // namespace doengine