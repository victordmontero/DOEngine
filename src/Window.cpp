
#include <string.h>
#include "Sprite.h"
#include "Window.h"

///\ brief: Default Constructor for window in the application if the application is android it will ignore first parameters.
Window::Window(int w, int h, const char *title ) :  gsm( new GameStateMachine())
{
    SDL_Init(SDL_INIT_EVERYTHING);
#ifndef __android__    
         SDL_CreateWindowAndRenderer(w,h,SDL_WINDOW_SHOWN,&window, &render);
         running = render!=NULL;
         SDL_SetWindowTitle(window, (title!=nullptr)?title:"untitled");
         window_rect.w = w;
         window_rect.h = h;
         window_rect.x = window_rect.y= SDL_WINDOWPOS_CENTERED;
#else
         SDL_DisplayMode mode;
         SDL_GetCurrentDisplayMode(0, &mode);
         window_rect.w = mode.w;
         window_rect.h = mode.h;
         window_rect.x = window_rect.y = SDL_WINDOWPOS_UNDEFINED;
         window = SDL_CreateWindow((title!=nullptr)?title:"untitled",
                                  window_rect.x, 
                                  window_rect.y,
                                  window_rect.w, 
                                  window_rect.h, 
                                  SDL_WINDOW_SHOWN);
         render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
         running = render!=nullptr;
#endif

    gsm = new GameStateMachine();

}
Window::~Window()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(render);
}
bool Window::isRunning(){return running;}
void Window::setClearColor(Uint8 r, Uint8 g, Uint8 b)
{
    SDL_SetRenderDrawColor(render, (int)r,(int)g,(int)b,255);
}
void Window::Clear()
{
    SDL_RenderClear(render);
}
void Window::UpdateScreen()
{
    gsm->Render();
    SDL_RenderPresent(render);
}
void Window::PollEvent(  )
{
    Event::getEventHandler()->PollEvent();
   gsm->Update();
}

 void Window::DrawSprite(Sprite* sprite)
 {
    Texture::DrawTexture(sprite->getTextureID(), sprite->getRect(), sprite->getCropRect());
 }
