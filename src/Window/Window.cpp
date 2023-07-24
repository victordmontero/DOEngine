
#include <vector>
#include <sstream>

extern "C" {
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
}

#include "DOEngine.h"
#include <TestState.h>

void Window::_CreateNeededInstance()
{
      fps_handler.reset(new FpsManager());
      gsm.reset(new GameStateManager(this));
      gsm.get()->AddState(1, new TestState(this));
      gsm.get()->SetState(1);
}



Window::Window(int w, int h)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    int flags = IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_TIF | IMG_INIT_WEBP;
    int res = IMG_Init(flags);
    SDL_Log("sdl_img_flags= %x, IMG_Init result set =%x", flags, res);
    flags = 0x00;
    SDL_DisplayMode mode;
    SDL_GetCurrentDisplayMode(1, &mode);
    window = SDL_CreateWindow("", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w,h,SDL_WINDOW_SHOWN|SDL_WINDOW_BORDERLESS);
    render = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC|SDL_RENDERER_ACCELERATED);
    run = render != NULL;
    window_rect.w = w;
    window_rect.h = h;
    Texture::setRender(render);
    _CreateNeededInstance();
}
Window::Window()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_DisplayMode mode;
    SDL_GetCurrentDisplayMode(0, &mode);
    window = SDL_CreateWindow("", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, mode.w,mode.h,SDL_WINDOW_SHOWN|SDL_WINDOW_BORDERLESS);
    render = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC|SDL_RENDERER_ACCELERATED);
    run = render != NULL;
    window_rect.w = mode.w;
    window_rect.h = mode.h;
    _CreateNeededInstance();
}
Window::~Window()
{
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
}

void Window::PollEvent()
{
    fps_handler->Start();
    Event::PollEvent(this);
}
void Window::Update(){
   /// gsm.get()->Update(Event::timeElapsed);
}
void Window::Render()
{
     SDL_SetRenderDrawColor(render, 255,255,0,255);
     SDL_RenderClear(render);
   ////  gsm.get()->Render();
     SDL_RenderPresent(render);
     fps_handler->Handle();
}
