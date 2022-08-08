#pragma once 
#include "Window.h"

class Window;

class GameState
{
   protected:
   Window *window;
   public:
   GameState(Window *w):window(w){
   }
   virtual void OnEnter()=0;
   virtual void OnExit()=0;
   virtual void Update(float elapsed) = 0;
   virtual void Render() = 0;
};