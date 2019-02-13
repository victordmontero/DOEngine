#include <SDL2/SDL.h>

#include "Window.h"
#include "GeometricRender.h"

void DrawPoint(const Point& p, const Color& c )
{
    extern Window *window;
    SDL_SetRenderDrawColor(window->getRender(), c.r, c.g, c.b, c.a);
    SDL_RenderDrawPoint(window->getRender(), p.x , p.y);
}

void DrawRect(const Rect &r, const Color &c, bool filled)
{
    extern Window *window;
    SDL_SetRenderDrawColor(window->getRender(), c.r, c.g, c.b, c.a);
    SDL_Rect rect={r.x, r.y, r.w, r.h};
    if(filled)
    {
        SDL_RenderFillRect(window->getRender(), &rect);
    }
    else
    {
        SDL_RenderDrawRect(window->getRender(), &rect);
    }
}