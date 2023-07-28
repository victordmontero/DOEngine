
#include <vector>
#include <sstream>

extern "C" {
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
}

#include "DOEngine.h"
#include <TestState.h>
#include <PlatformState.h>
void Window::_CreateNeededInstance()
{
      fps_handler.reset(new FpsManager());
      gsm.reset(new GameStateManager(this));
   
 
      gsm.get()->SetState(2);
      dirty = true;

    canvas1 = new Canvas(this);
    canvas2 = new Canvas(this);
  
    canvas1->setPosition({100,500, 100,100})
           ->fillColor({0,0,255,255})
           ->setCanvasBackgroundColor({255,255,0,255});
 

    canvas2->setPosition({400,100, 200,300})
            ->fillColor({0,0,255,255});
 

}



Window::Window(int w, int h)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    int flags = IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_TIF | IMG_INIT_WEBP;
    int res = IMG_Init(flags);
    SDL_Log("sdl_img_flags= %x, IMG_Init result set =%x", flags, res);
    flags = 0x00;
    
    SDL_GetCurrentDisplayMode(1, &mode);
    window = SDL_CreateWindow("", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, mode.w,mode.h,SDL_WINDOW_SHOWN|SDL_WINDOW_BORDERLESS);
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
    SDL_GetCurrentDisplayMode(0, &mode);
    window = SDL_CreateWindow("", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, mode.w,mode.h,SDL_WINDOW_SHOWN|SDL_WINDOW_BORDERLESS|SDL_WINDOW_FULLSCREEN);
    render = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC|SDL_RENDERER_ACCELERATED);
    run = render != NULL;
    window_rect.w = mode.w;
    window_rect.h = mode.h;
    _CreateNeededInstance();
}

void Window::destroy(){
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    render = nullptr;
    window = nullptr;
}

Window::~Window()
{
  destroy();
}

void Window::setFullScreen()
{
   SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
}

void Window::setWindowMode()
{
   SDL_SetWindowFullscreen(window, 0);
}
void Window::PollEvent()
{
    fps_handler->Start();
    Event::PollEvent(this);
}
void Window::Update(){
  /// gsm.get()->Update(Event::timeElapsed);


   canvas1->fillColor({0,0,255,255});
   canvas1->DrawRect(0,0,20,20);
   canvas1->fillColor({0,255,255,255});
   canvas1->DrawRect(30,30,20,20);

   canvas2->fillColor({0,0,255,255});
   canvas2->DrawRect(0,0,20,20);
   canvas2->fillColor({0,255,255,255});
   canvas2->DrawRect(30,30,20,20);
}
void Window::Render()
{
 
     SDL_SetRenderDrawColor(render, 0,0,0,255);
     SDL_RenderClear(render);
    
     canvas1->update();

     canvas2->update();


     SDL_RenderPresent(render);
     fps_handler->Handle();
}


void Window::Quit()
{
  ///SDL_Log("running will be toggle to false");

  ///destroy();

  this->run = false;
}

const bool Window::IsRunning()const{
   //// SDL_Log("is Running %ld", (long int)run);
   
    return this->run;
}


Window *Window::SetWindowPencilColor(ColorT r, ColorT g, ColorT b, ColorT a){
    SDL_SetRenderDrawColor(render, r,g,b,a);
    return this;
}