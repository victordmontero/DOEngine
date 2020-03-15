
#include<SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Window.h"
#include "../Texture/Texture.h"
#include "../Font/TTFText.h"
#include "../Event/Event.h"


#include "../GameState/Bejweeled.h"
#include "../GameState/Hanoi.h"
#include "../GameState/AsteroidState.h"
#include "../GameState/ConwayState.h" 


void Window::_CreateNeededInstance()
{
  fps_handler = new FpsManager();
  game_state_manager = new GameStateManager(this);
  TTFText::get()->setFont("./NirmalaB.ttf", 34);
  game_state_manager->AddState(1, new ConwayState(this));
  game_state_manager->SetState(1);
}



Window::Window(int w, int h)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    window = SDL_CreateWindow("", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w,h,SDL_WINDOW_SHOWN|SDL_WINDOW_BORDERLESS);
    render = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC|SDL_RENDERER_ACCELERATED);
    run = render != NULL;
    window_rect.w = w;
    window_rect.h = h;
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
  // SDL_Event event;
   fps_handler->Start();
  /* while(SDL_PollEvent(&event))
   {
       if(event.type==SDL_KEYDOWN)
        {
            if(event.key.keysym.sym==SDLK_q)
               run= false;
        }
   }
   */

   Event::PollEvent(this);


}
void Window::Update(){
    game_state_manager->Update(fps_handler->getElapsedTime());
}
void Window::Render()
{
     SDL_SetRenderDrawColor(render, 0,0,0,255);
     SDL_RenderClear(render);
     game_state_manager->Render();
     SDL_RenderPresent(render);
////       fps_handler->Handle();
    
}
