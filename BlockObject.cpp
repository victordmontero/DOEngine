#include "BlockObject.h"

BlockObject::BlockObject() : Object()
{
  this->texture =new Texture("C:\\Aneury\\2D-ENGINE\\bin\\Debug\\block.bmp", {0,0,0,0});
  this->offset.x = 100;
  this->offset.y = 100;
  this->offset.w = 100;
  this->offset.h = 100;
}

void BlockObject::Move(int pos)
{
    dx =0;
    dy =0;
   if(pos == Object::Position::DOWN)
    {
        dx = 0;
        dy = 10;
    }
      if(pos == Object::Position::LEFT)
    {
        dx = -10;
        dy = 0;
    }
      if(pos == Object::Position::UP)
    {
        dx = 0;
        dy = -10;
    }
    if(pos == Object::Position::RIGHT)
    {
        dx = 10;
        dy = 0;
    }
}

void BlockObject::Draw()
{
   texture->Draw(offset.x, offset.y, offset.w, offset.h);
}

void BlockObject::Update()
{
    offset.x += dx;
    offset.y += dy;
}