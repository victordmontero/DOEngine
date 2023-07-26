#pragma once 

#include<SDL2/SDL.h>
#include <memory>

#include "FPSManager.h"
#include "GameStateManager.h"
#include "Texture.h"


class GameStateManager;

class Window
{
    SDL_Window   *window;
    SDL_Renderer *render;
    SDL_Rect      window_rect;
    SDL_DisplayMode mode;
    std::shared_ptr<FpsManager> fps_handler;
    std::shared_ptr<GameStateManager> gsm;
    bool run;
    bool dirty;
    void _CreateNeededInstance();
    public:

    Window(int w, int h);
    Window();
    ~Window();
 
    const bool IsRunning()const;
    SDL_Renderer *getRender(){return render;}
    SDL_Window   *getWindow(){return window;}
    void PollEvent();
    void Update();
    void Render();
    void Quit();

    int getH(){
        return window_rect.h;
    }
    int getW(){
        return window_rect.w;
    }

    typedef unsigned char ColorT;
    Window *SetWindowPencilColor(ColorT r, ColorT g, ColorT b, ColorT a);

    void dontClear(){dirty=false;}
    void setClear(){dirty=true;}
    private:
    void destroy();
};