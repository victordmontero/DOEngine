#pragma once 

#include<SDL2/SDL.h>
#include <memory>

#include "FPSManager.h"
#include "GameStateManager.h"
#include "Texture.h"

#include "Canvas.h"

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


    Canvas *canvas1;
    Canvas *canvas2;


    public:

    Window(int w, int h);
    Window();
    ~Window();
 
    const bool    IsRunning()const;
    SDL_Renderer *getRender(){return render;}
    SDL_Window   *getWindow(){return window;}
   
    
    Window*  setFullScreen();
    Window*  setWindowMode();
   
    Window*  PollEvent();
    Window*  Update();
    Window*  Render();
    Window*  Quit();

    int getH(){
        return window_rect.h;
    }
    int getW(){
        return window_rect.w;
    }

    typedef unsigned char ColorT;
    Window *SetWindowPencilColor(ColorT r, ColorT g, ColorT b, ColorT a);

    private:
    void destroy();
};