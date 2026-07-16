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

#include <string>

namespace doengine
{

class MusicHandler
{

  public:
    virtual int addToList(const std::string& src) = 0;
    virtual void playFirst() = 0;
    virtual void playLast() = 0;
    virtual void playIndex(int index) = 0;
    virtual void removeIndex(const int index) = 0;
    virtual void pause(const int) = 0;
    virtual void stop(const int) = 0;
    virtual bool isPlaying(const int) const = 0;
    virtual std::string getPlayMusicName(){return "";}
    enum class Repeat
    {
        OnlyThis = -1,
        Once,
        All,
    };

    virtual void setRepeat(Repeat repeat) = 0;
    virtual void setChannel(const int) = 0;
};
} // namespace doengine

#if 0

int main(int argc, char* argv[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        std::cout << "SDL initialization failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Initialize SDL_mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cout << "SDL_mixer initialization failed: " << Mix_GetError() << std::endl;
        return 1;
    }

    // Load an MP3 file
    Mix_Music* music = Mix_LoadMUS("./nirv-mix-sitw-by-catanius-revival.mp3");
    if (!music) {
        std::cout << "Failed to load music: " << Mix_GetError() << std::endl;
        return 1;
    }

    // Play the music
    if (Mix_PlayMusic(music, -1) == -1) {
        std::cout << "Failed to play music: " << Mix_GetError() << std::endl;
        return 1;
    }


    // Wait until the music finishes playing
    while (Mix_PlayingMusic()) {
        SDL_Delay(100);
    }

    // Cleanup and quit
    Mix_FreeMusic(music);
    Mix_CloseAudio();
    SDL_Quit();

    return 0;
}

#endif
