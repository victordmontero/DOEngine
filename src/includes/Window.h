#pragma once 

#include <SDL.h>


#include "FPSManager.h"
#include "GameStateManager.h"
#include "Texture.h"


class GameStateManager;

class Window
{
    SDL_Window   *window;
    SDL_Renderer *render;
    SDL_Rect      window_rect;
    FpsManager   *fps_handler;
    GameStateManager *game_state_manager;
    bool run;


    void _CreateNeededInstance();

    public:

    Window(int w, int h);
    Window();
    ~Window();
 
    inline bool IsRunning(){ return run;}
    SDL_Renderer *getRender(){return render;}
    SDL_Window   *getWindow(){return window;}
    Window* PollEvent();
    Window* Update();
     Window*  Render();
     Window*  Quit(){run =false;}

    int getH(){
        return window_rect.h;
    }
    int getW(){
        return window_rect.w;
    }
};