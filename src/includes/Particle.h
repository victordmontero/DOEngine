#pragma once
#include "Window.h"
#include <SDL2/SDL.h>
#include "Canvas.h"
#include "StandardFuncs.h"
#include "Canvas.h"
struct Particle{
   
   SDL_Rect offset;
   double radius;
   double speedx;
   double speedy;
   Window *window;
   Particle(Window *window, int x, int y){
       offset.x = x;
       offset.y = y;
       offset.w =  getRandomInt(1, 5);
       offset.h =  getRandomInt(1, 5);
       radius = getRandomInt(3,10);
       speedx = getRandomInt(3, 7);
       speedy = getRandomInt(3, 7);
       this->window = window;
   }

   void Update(){
     offset.x += speedx;
     offset.y += speedy;
   }

   void Draw(){
       Color color{0,0,255,255};
       Canvas::fillStyle(color);
       FillCircle(offset.x, offset.y, radius, color, window);
   }

};