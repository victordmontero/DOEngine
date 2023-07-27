#include <SDL2/SDL.h>
#include "PrimitivesGraphics.h"


void DrawRect(SDL_Renderer *render, SDL_Rect rect){
    SDL_RenderDrawRect(render, &rect);
}

void DrawRect(Window *window, SDL_Rect rect){
    SDL_RenderDrawRect(window->getRender(), &rect);
}