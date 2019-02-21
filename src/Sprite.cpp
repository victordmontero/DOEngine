#include "Sprite.h"
#include "Texture.h"
Sprite::Sprite()
{
   
}

Sprite::Sprite(int texture_id)
{
   this->SetTextureID(texture_id);
   if(Texture::getTexture(texture_id))
   {
       rect.x = -1100;
       rect.y = -1100;
       rect.w = Texture::getTexture(texture_id)->getW(); 
       rect.h = Texture::getTexture(texture_id)->getH();
   }
}

Sprite::~Sprite()
{

}

void Sprite::SetTextureID(int id)
{
   this->id  = id;
   if(Texture::getTexture(id))
   {
       rect.x = -1100;
       rect.y = -1100;
       rect.w = Texture::getTexture(id)->getW(); 
       rect.h = Texture::getTexture(id)->getH();
   }
}

void Sprite::SetPosition(int x, int y)
{
  rect.x = x;
  rect.y = y;
}

void Sprite::SetSize(int w, int h)
{
     rect.w= w;
     rect.h= h;
}

void Sprite::Move(int x, int y)
{
   rect.x += x;
   rect.y += y;
}

void Sprite::SetRect(Rect rect)
{
   this->rect.x = rect.x;
   this->rect.y = rect.y;
   this->rect.w = rect.w;
   this->rect.h = rect.h;
}

void Sprite::SetCropRect(Rect rect)
{
   this->clip.x = rect.x;
   this->clip.y = rect.y;
   this->clip.w = rect.w;
   this->clip.h = rect.h;
}