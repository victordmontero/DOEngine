
#include <SDL2/SDL.h>

#include "FPSManager.h"

FpsManager::FpsManager(){
    start=elapsed=wait=0;
    fps=60;
}

void FpsManager::setFPS(long fps){
    this->fps=fps;
}
float FpsManager::getElapsedTime(){
    return (float)(elapsed-start);
}

void FpsManager::Start(){
    start = SDL_GetTicks();
}
    
void FpsManager::Handle()
{
    elapsed = SDL_GetTicks();
    float ticks = 1000/fps;
    if(ticks > elapsed - start)
    {
        wait = ticks - (elapsed - start);
        SDL_Log("FPS %ld", wait);
        if(wait>0)
           SDL_Delay(wait);
        else
           SDL_Delay(ticks);
    }
}