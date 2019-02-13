#pragma once
#include <SDL2/SDL.h>
#include <memory>
#include "StateMachine.h"
 


class Window
{
   bool enable_opengl;
   SDL_Window   *window;
   SDL_Renderer *render;
   SDL_Rect      window_rect;
   SDL_Event     event;
   Uint8        *keystate;
   GameStateMachine* gsm;
   bool running;

   public:

   Window(int w, int h, const char *title, bool gl=false);
   ~Window();
   bool isRunning();
   void setClearColor(Uint8 r, Uint8 g, Uint8 b);
   void Clear();
   void UpdateScreen();
   void PollEvent(SDL_Event *event=nullptr);
   SDL_Renderer *getRender(){return render;}
   void addState(int state_id, GameState *ptr){
       gsm->addState(state_id, ptr);
   }
};
extern Window *window;