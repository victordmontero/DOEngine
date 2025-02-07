#include "SDLMusicHandler.h"
#include <SDL2/SDL_mixer.h>

namespace doengine::devices
{

constexpr int FRECUENCY = 44100;
constexpr int CHANNEL = 2;
constexpr int CHUNK_SIZE = 2048;

SDLMusicHandler::SDLMusicHandler()
    : musics(), sounds(), isPlayingSound(false), isOk(false)
{
    isOk = SDL_Init(SDL_INIT_AUDIO) == 0;

    if (!isOk)
    {
        SDL_Log("SDL Mixer failed to Init: %s", SDL_GetError());
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

SDLMusicHandler::~SDLMusicHandler()
{
    if (isOk)
    {
        for (auto it = musics.begin(); it != musics.end(); it++)
        {
            Mix_FreeMusic(*it);
        }
        musics.clear();
        Mix_CloseAudio();
    }
}

void SDLMusicHandler::addToList(const std::string& src)
{
    if (isOk)
    {
        Mix_Music* music = Mix_LoadMUS(src.c_str());
        if (music == nullptr)
        {
            SDL_Log("SDL Mixer failed to Load music: %s", Mix_GetError());
        }
        else
        {

            SDL_Log("Saving %s", src.c_str());
            musics.push_back(music);
        }
    }
}

void SDLMusicHandler::playFirst()
{
    if (isOk)
    {
        if (Mix_PlayMusic(musics.front(), static_cast<int>(Repeat::Once)) == -1)
        {
            SDL_Log("Failed to play music: %s", Mix_GetError());
        }
    }
}

void SDLMusicHandler::playLast()
{
    if (isOk)
    {
        if (Mix_PlayMusic(musics.back(), -1) == -1)
        {
            SDL_Log("Failed to play music: %s", Mix_GetError());
        }
    }
}

void SDLMusicHandler::PlayIndex(int index)
{
    if (isOk && (index < musics.size()))
    {
        if (Mix_PlayMusic(musics.at(index), -1) == -1)
        {
            SDL_Log("Failed to play music: %s", Mix_GetError());
        }
    }
}

void SDLMusicHandler::removeIndex(int index)
{
    musics.erase(musics.begin() + index);
}

void SDLMusicHandler::pause()
{
    if (isPlayingMusic())
    {
        Mix_PauseMusic();
    }
}

void SDLMusicHandler::stop()
{
    Mix_HaltMusic();
}

bool SDLMusicHandler::isPlayingMusic() const
{
    return Mix_PlayingMusic();
}

void SDLMusicHandler::setRepeat(Repeat repeat)
{
}

} // namespace doengine::devices
