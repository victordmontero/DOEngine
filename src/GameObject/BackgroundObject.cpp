
#include <SDL.h>

#include "BackgroundObject.h"


BackgroundObject::BackgroundObject(const char *tid,Window *window):GameObject(window),tid(tid)
{
    x=y=0;
    dx=0.5;
    dy=0;
}
BackgroundObject::BackgroundObject(const char *tid,bool loop,Window *window):GameObject(window),tid(tid)
{
    x=y=0;
    dx=0.5;
    dy=0;
}
bool BackgroundObject::isCollide(const GameObject& gameobject){
    return false;
}
void BackgroundObject::Update(float timer=0){
    if(loop){

    }
}
void BackgroundObject::Render(){
  if(Texture::IsloadThisTexture(tid)){
      Texture::DrawImage(tid,x,y,window->getW(), window->getH(), window->getRender());
  }
}