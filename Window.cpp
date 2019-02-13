
#include <string.h>

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
    gsm->Render(render);
    SDL_RenderPresent(render);
}
void Window::PollEvent(SDL_Event *ev )
{
    if(ev==nullptr)
    {
        memset(&event, 0x00, sizeof(event));
        while(SDL_PollEvent(&this->event))
        {
            if(this->event.type==SDL_QUIT)
                running =false;
        }
        gsm->Update(&event);
    }
    else
    {
        while(SDL_PollEvent(ev))
        {
            if(ev->type==SDL_QUIT)
                running =false;
        }
        gsm->Update(ev);
    }
}