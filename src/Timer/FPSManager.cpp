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



#include "DOEngine_SDL_includes.h"

#include "FPSManager.h"

namespace doengine
{

void FpsManager::setFPS(long fps)
{
    this->fps = fps;
}

uint32_t FpsManager::getDeltaTime()
{
    return (uint32_t)(elapsed - start);
}

float FpsManager::getElapsedTime()
{
    last_elapsed = (float)(elapsed - start);
    return last_elapsed;
}

float FpsManager::getLastElapsedTime()
{
    return static_cast<float>(last_elapsed);
}

void FpsManager::Start()
{
    start = SDL_GetTicks();
    frequency = SDL_GetPerformanceFrequency();
    lastCounter = SDL_GetPerformanceCounter();
}

void FpsManager::Handle()
{
    const uint32_t frameDelay = 1000 / fps;

    uint32_t frameTime = SDL_GetTicks() - start;

    if (frameTime < frameDelay)
    {
        SDL_Delay(frameDelay - frameTime);
    }

    start = SDL_GetTicks();
}

void FpsManager::beginFrame()
{
    lastCounter = SDL_GetPerformanceCounter();
}

double FpsManager::endFrame()
{
    uint64_t now = SDL_GetPerformanceCounter();
    double deltaTime = static_cast<double>(now - lastCounter) / frequency;

    const double targetFrameTime = 1.0 / fps;

    if (deltaTime < targetFrameTime)
    {
        SDL_Delay(static_cast<Uint32>((targetFrameTime - deltaTime) * 1000.0));

        now = SDL_GetPerformanceCounter();
        deltaTime = static_cast<double>(now - lastCounter) / frequency;
    }

    return deltaTime;
}

double FpsManager::getTicks()
{
    return SDL_GetTicks();
}
}