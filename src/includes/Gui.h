#pragma once 
#include <SDL2/SDL.h>
#include <Window.h>
#include <Canvas.h>

struct UIObject{
   protected:
     Canvas *canvas;
     Window *ref;
     SDL_Rect position_size;
     int padding;
   public:

   virtual ~UIObject(){}
};