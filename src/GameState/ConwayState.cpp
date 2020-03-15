
#include "../Drawable/Geometric.h"
#include "ConwayState.h"

void ConwayState::OnEnter()
{
    for(int i=0;i<network.getRow();i++)
    {
        for(int j=0;j<network.getCol();j++)
        {
            network.setValue(j, i, false);
        }
    }

}


void ConwayState::OnExit()
{

}

void ConwayState::Update(float elapsed)
{
   int iter=0;
}


void ConwayState::Render()
{
     
   for(int i=0;i<network.getRow();i++)
   {
       for(int j=0;j<network.getCol();j++)
       {
           Rect rect;
           rect.x = j * 16;
           rect.y = i * 16;
           rect.w = 16;
           rect.h = 16;
           Color color;
           color.a = 255;
           color.r = 255;
           color.g = 255;
           color.b = 255;
           DrawRect(rect, color, window);
       }
   }
}