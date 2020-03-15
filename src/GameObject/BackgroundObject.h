#pragma once

#include "GameObject.h"
#include "../Texture/Texture.h"


class BackgroundObject : public GameObject
{
   const char *tid;
   float x,y,dx,dy;
   bool loop;   ///replace with AnimatedGameObject

   public:
   virtual ~BackgroundObject(){}
   BackgroundObject(const char *tid,Window *window);
   BackgroundObject(const char *tid,bool loop,Window *window);
   virtual bool isCollide(const GameObject& gameobject);
   virtual void Update(float timer);
   virtual void Render();

};