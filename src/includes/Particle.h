#pragma once
#include "Window.h"
#include <SDL2/SDL.h>
#include "Canvas.h"
#include "StandardFuncs.h"
#include "Canvas.h"
struct Particle{
   

   Window *window;
   Particle(Window *window){
     this->window = window;
   }

   void Update(){

   }

   void Draw(){}

};