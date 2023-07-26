#pragma once

#include "DOEngine.h"
#include "Geometric.h"


class GameObject{
  
   protected:
     Window *window;
     bool   renderable;
     bool   solid;
     int    layer;
 
     std::string sprite_id;
     std::string texture_id;

   public:

   GameObject(Window *window);
   virtual ~GameObject(){}
   virtual void Update(float timer=0) = 0;
   virtual void Render() = 0;

};