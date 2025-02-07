#pragma once

#include "DOEngine_SDL_includes.h"
#include "MusicHandler.h"
#include <vector>

namespace doengine::devices
{
class SDLMusicHandler : public doengine::MusicHandler
{
  public:
    SDLMusicHandler();
    ~SDLMusicHandler();
    virtual void addToList(const std::string& src) override;
    virtual void playFirst() override;
    virtual void playLast() override;
    virtual void PlayIndex(int index) override;
    virtual void removeIndex(int index) override;
    virtual void pause() override;
    virtual void stop() override;
    virtual void setRepeat(Repeat repeat) override;
    virtual bool isPlayingMusic() const override;

  private:
    std::vector<Mix_Music*> musics;
    std::vector<Mix_Chunk*> sounds;

//    bool isPlayingMusic;
    bool isPlayingSound;
    bool isOk;
};
} // namespace doengine::devices
