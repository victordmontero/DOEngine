#pragma once
#include "Object.h"
struct BlockObject: public Object
{

   BlockObject();
   virtual void Move(int pos);
   virtual void Draw();
   virtual void Update();
};