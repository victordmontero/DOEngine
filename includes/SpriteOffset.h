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

#ifndef SPRITE_OFFSET_H_DEFINED
#define SPRITE_OFFSET_H_DEFINED
#include <vector>
#include "Geometric.h"
#include "Logger.h"


namespace doengine
{

struct SpriteAnimationOffset
{
    int id;
    std::vector<doengine::Rect> spriteOffset;

    int current = 0;
    bool ended = false;
    bool rewind = true;

    double frameDuration = 0.1;   // seconds per frame
    double accumulator = 0.0;

    SpriteAnimationOffset(int id): id{id}
    {
    }

    explicit SpriteAnimationOffset(int id, std::vector<doengine::Rect> offsets)
        : id{id},
          spriteOffset{std::move(offsets)}
    {
    }

    const int getSizeOfOffset()const
    {
        return spriteOffset.size();
    }

    void update(double deltaTime)
    {
        doengine::LogOuput(doengine::logger_type::Information, "detal Time %lf", deltaTime);
        if ((ended && !rewind) || spriteOffset.empty())
            return;
        if(ended && rewind)
            reset();

        accumulator += deltaTime;

        while (accumulator >= frameDuration)
        {
            accumulator -= frameDuration;
            current++;

            if (current >= static_cast<int>(spriteOffset.size()))
            {
                current = static_cast<int>(spriteOffset.size()) - 1;
                ended = true;
                break;
            }
        }
    }

    doengine::Rect getCurrentOffset() const
    {
        return spriteOffset[current];
    }

    void reset()
    {
        current = 0;
        accumulator = 0.0;
        ended = false;
    }

    bool finish() const
    {
        return ended;
    }
};


}


#endif
