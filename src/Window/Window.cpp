
#include <vector>
#include <sstream>

extern "C" {
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
}

#include "DOEngine.h"

namespace {

    std::vector<SDL_Point> points;
    Texture* texture;

};

void Window::_CreateNeededInstance()
{
      fps_handler = new FpsManager();
///   game_state_manager = new GameStateManager(this);
      TTFText::get()->setFont("C:\\aneury\\DOEngine-master\\bin\\Debug\\NirmalaB.ttf", 34);
////  game_state_manager->AddState(1, new ConwayState(this));
///  game_state_manager->SetState(1);
      Texture::LoadTexture("C:\\aneury\\DOEngine-master\\bin\\Debug\\DominoRD1024x576.png","logo1");


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

    if (Event::mousePressed)
    {
        SDL_Log("Mousd Pressend");
        SDL_Point point;
        SDL_GetMouseState(&point.x, &point.y);
        points.emplace_back(point);
    }

    if (Event::keyDown)
    {
        SDL_Log("Keydown");
    }

}
void Window::Update(){
 ///   game_state_manager->Update(fps_handler->getElapsedTime());
}
void Window::Render()
{
     SDL_SetRenderDrawColor(render, 0,0,0,255);
     SDL_RenderClear(render);
  ///   game_state_manager->Render();
     ///TTFText::get()->DrawText("Victor this works as is",100,100, render);
     
     for (auto it : points)
     {
         Point point{ it.x, it.y };
         Color color{ 255,255,0,255 };
         DrawPoint(point, color, this);
     }
     
     Texture::DrawImage("logo1", 0, 0, getW(), getH());
     
     
     SDL_RenderPresent(render);
     fps_handler->Handle();
    
}
