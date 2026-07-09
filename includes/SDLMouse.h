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

#include "Mouse.h"

namespace doengine
{
namespace devices
{
class SDLMouse : public Mouse
{
  public:
    SDLMouse(unsigned int which, unsigned int buttonMask, Point p);
    unsigned int getMouseId() const override;
    bool isRightClick() const override;
    bool isLeftClick() const override;
    bool isMiddleClick() const override;
    void getPosition(Point&) override;
    const Point& getMotionPosition() const override;
    const Point& getPosition() const override;
    void getButtonStateBitset(
        std::bitset<Mouse::BUTTONS_COUNT>&) const override;
    virtual const Point& getWheelScroll() const override;
    void updateValues();
    void setScroll(int x, int y);
    Point motion;
  private:
    unsigned int buttonMask;
    unsigned int which;
    Point position;
    
    Point scroll;
};
} // namespace devices
} // namespace doengine