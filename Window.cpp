
#include <string.h>
#include "Sprite.h"
#include "Window.h"


Window::Window(int w, int h, const char *title, bool gl) :  gsm( new GameStateMachine())
{
    SDL_Init(SDL_INIT_EVERYTHING);
    if(gl==false)
    {
         SDL_CreateWindowAndRenderer(w,h,SDL_WINDOW_SHOWN,&window, &render);
         running = render!=NULL;
         SDL_SetWindowTitle(window, (title!=nullptr)?title:"untitled");
    }
    else
    {


    }
    window_rect.w = w;
    window_rect.h = h;
    window_rect.x = window_rect.y= SDL_WINDOWPOS_CENTERED;
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
