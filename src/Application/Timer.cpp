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


#include "Timer.h"

namespace doengine
{
Timer::Timer(float length)
{
    current_time = 0;
    len = length;
    timeout_callback = nullptr;
}
Timer::~Timer()
{

}
int Timer::getLength()
{
    return len;
}
bool Timer::isTimeout()
{
    return timeout;
}
void Timer::Update(float t)
{
    current_time += t;
    if(current_time >= len)
    {
        current_time -= len;
        timeout = true;
        if(timeout_callback)
            timeout_callback();
    }
}
void Timer::reset()
{
    current_time = 0;
    timeout = false;
}
float Timer::getTime()
{
    return current_time;
}
void Timer::addTimerCallback(std::function<void()> cb)
{
    timeout_callback = cb;
}

float Timer::getElapsedTime()
{
    return current_time;
}


} // namespace doengine