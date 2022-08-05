#pragma once

#include "Geometric.h"

class Window;

template<const int W, const int H, const int bw,const Window *w>
struct DrawableMatrix
{
   void drawDebugAndWhiteElement(int col, int row)
   {
       Rect rect{ x,y,bw,bw };
   }
};
