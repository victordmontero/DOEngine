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

#include <bitset>
#include <cstddef>

#include "v2d_vector.h"
#include <Geometric.h>

namespace doengine
{
namespace devices
{

enum class MouseButton : unsigned char
{
    Left = 1,
    Middle,
    Right,
    X1,
    X2
};

class Mouse
{
  public:
    static const size_t BUTTONS_COUNT = 6u;
    virtual unsigned int getMouseId() const = 0;
    virtual bool isRightClick() const = 0;
    virtual bool isLeftClick() const = 0;
    virtual bool isMiddleClick() const = 0;
    virtual void getPosition(Point&) = 0;
    virtual const Point& getPosition() const = 0;
    virtual const Point& getMotionPosition() const = 0;
    virtual void getButtonStateBitset(std::bitset<BUTTONS_COUNT>&) const = 0;
    virtual const Point& getWheelScroll() const = 0;
    enum  MouseButtonDown : uint8_t{
      Left = 1,
      Right = 2,
      Center = 4
    };
    static Rect getMousePosition();
    static uint8_t getButtonPressed();
};

} // namespace devices
} // namespace doengine