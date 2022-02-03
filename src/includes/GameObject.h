#pragma once

#include "DOEngine.h"
#include "Geometric.h"

class Rect;
class GameObject{
  
   protected:
     Window *window;
     bool   renderable;
     bool   solid;
     int    layer;
     Rect   *rect;
	 Rect    collide_rect;
     Sprite *sprite;
     std::string sprite_id;
     std::string texture_id;

   public:
   GameObject(Window *window);
   virtual ~GameObject(){}

   virtual bool isCollide(const GameObject& gameobject) = 0;
   virtual void Update(float timer=0) = 0;
   virtual void Render() = 0;

};