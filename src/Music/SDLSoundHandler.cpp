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


#include "SDLSoundHandler.h"

namespace doengine
{

constexpr int FRECUENCY = 44100;
constexpr int CHANNEL = 2;
constexpr int CHUNK_SIZE = 2048;

SDLSoundHandler::SDLSoundHandler()
    : sounds(), channel(-1), repeatTimes(Repeat::Once), isOk(false)
{
    if (SDL_WasInit(SDL_INIT_AUDIO) == 0)
    {
        isOk = SDL_Init(SDL_INIT_AUDIO) == 0;
    }
    else
    {
        isOk = true;
    }

    if (!isOk)
    {
        SDL_Log("SDL Audio failed to Init: %s", SDL_GetError());
    }
    else
    {
        isOk = Mix_OpenAudio(FRECUENCY, MIX_DEFAULT_FORMAT, CHANNEL,
                             CHUNK_SIZE) == 0;

        if (!isOk)
        {
            SDL_Log("SDL Mixer failed to OpenAudio: %s", Mix_GetError());
        }
    }
}

SDLSoundHandler::~SDLSoundHandler()
{
    if (isOk)
    {
        stop(-1); // Stops all channels
        for (auto it = sounds.begin(); it != sounds.end(); it++)
        {
            Mix_FreeChunk(*it);
        }
        sounds.clear();
        Mix_CloseAudio();
    }
}

int SDLSoundHandler::addToList(const std::string& src)
{
    if (isOk)
    {
        Mix_Chunk* music = Mix_LoadWAV(src.c_str());
        if (music == nullptr)
        {
            SDL_Log("SDL Mixer failed to Load music: %s", Mix_GetError());
        }
        else
        {
            SDL_Log("Adding %s", src.c_str());
            sounds.push_back(music);
            return sounds.size() - 1;
        }
    }
    return -1;
}

void SDLSoundHandler::playFirst()
{
    if (isOk)
    {
        play(sounds.front());
    }
}

void SDLSoundHandler::playLast()
{
    if (isOk)
    {
        play(sounds.back());
    }
}

void SDLSoundHandler::playIndex(const int index)
{
    if (isOk && ((size_t)index < sounds.size()))
    {
        play(sounds.at(index));
    }
}

void SDLSoundHandler::removeIndex(const int index)
{
    sounds.erase(sounds.begin() + index);
}

void SDLSoundHandler::pause(const int index)
{
    if (isPlaying(index))
    {
        Mix_Pause(index);
    }
}

void SDLSoundHandler::stop(const int index)
{
    Mix_HaltChannel(index);
}

bool SDLSoundHandler::isPlaying(const int index) const
{
    return Mix_Playing(index);
}

void SDLSoundHandler::setRepeat(Repeat repeat)
{
    repeatTimes = repeat;
}

void SDLSoundHandler::setChannel(const int ch)
{
    channel = ch;
}

void SDLSoundHandler::play(Mix_Chunk* chunk)
{
    if (Mix_PlayChannel(channel, chunk, static_cast<int>(repeatTimes)) == -1)
    {
        SDL_Log("Failed to play music: %s", Mix_GetError());
    }
}

} // namespace doengine
