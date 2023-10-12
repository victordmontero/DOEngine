#pragma once 

#include <memory>
extern "C" {
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
}

#include "abstract/AbstractWindow.h"

#include "FPSManager.h"
#include "GameStateManager.h"
#include "Texture.h"

#include "Canvas.h"

class GameStateManager;

class Window : public doengine::AbstractWindow
{
    SDL_Window   *window;
    doengine::gfx::Renderer* render;
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
 
    const bool    IsRunning() const override;
    doengine::gfx::Renderer* getRender() const override {return render;}
    SDL_Window   *getWindow() {return window;}
   
    
    doengine::AbstractWindow*  setFullScreen() override;
    doengine::AbstractWindow*  setWindowMode() override;
   
    doengine::AbstractWindow*  PollEvent() override;
    doengine::AbstractWindow*  Update() override;
    doengine::AbstractWindow*  Render() override;
    doengine::AbstractWindow*  Quit() override;

    int getH() override {
        return window_rect.h;
    }
    int getW() override {
        return window_rect.w;
    }

    typedef unsigned char ColorT;
    doengine::AbstractWindow *SetWindowPencilColor(doengine::Color color) override;

    private:
    void destroy();
};