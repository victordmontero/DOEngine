
#include "Application.h"
#include "GameState.h"
#include "SDLMusicHandler.h"
#include <algorithm>
#include <memory>
#include <string>

using doengine::devices::SDLMusicHandler;

class MusicState : public doengine::GameState
{
  public:
    virtual void OnEnter()
    {
        auto app = doengine::Application::getApplication();
        SDL_Log("Entering state");
        const std::string MUSIC_NAME =
            "/home/phenom/Music/gymnopedie-1-erik-satie.mp3";
        musicHandler = new SDLMusicHandler;
        musicHandler->addToList(MUSIC_NAME);
        musicHandler->playFirst();

        timeInSecs = 60;
    }
    virtual void OnExit()
    {
        SDL_Log("Exiting\n");
        delete musicHandler;
        musicHandler = nullptr;
        SDL_Quit();
    }
    virtual void Update(float elapsed)
    {
        auto app = doengine::Application::getApplication();
        SDL_Log("Time elapsed %ld\n", app->getElapsedTime());

        SDL_Log("Time remaining %ld\n", timeInSecs);

        if (timeInSecs-- <= 0)
        {
            musicHandler->stop();
            app->Quit();
        }

        SDL_Delay(1000);

    }
    virtual void Render()
    {
    }

  private:
    SDLMusicHandler* musicHandler;
    unsigned long timeInSecs;
};

enum SampleStateId : int
{
    pongStateID = 1
};

int main(int argc, char* argv[])
{
    auto app = doengine::Application::getApplication();
    // app->setSize(800, 600);
    auto pongState = new MusicState();
    app->addState(pongState, pongStateID);
    app->setState(pongStateID);
    while (app->IsRunning())
    {
        app->PollEvent();
        app->Update();
        app->Render();
    }
    app->Quit();
    return 0;
}
