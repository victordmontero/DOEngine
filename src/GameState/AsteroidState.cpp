#include "AsteroidState.h"
#include "../Drawable/Geometric.h"

AsteroidState::AsteroidState(Window *window):GameState(window){}
void AsteroidState::OnEnter()
{
   
   asteroids.push_back({100,100,-1,2,(int)3});


}
void AsteroidState::OnExit(){}
void AsteroidState::Update(float elapsed)
{
   if(elapsed<=0)elapsed = 0.60555;
   for(auto& it: asteroids)
   {
       SDL_Log("x=%d, y=%d", it.x, it.y);
       it.x += it.dx * (elapsed + 0.16);
       it.y += it.dy * (elapsed + 0.16);
   } 
}
void AsteroidState::Render()
{

    FillCircle(100,100, 20, {255,35,100,244},window);
    DrawTriangle(10,100,120,200,230,300,{0,123,123,255},window);
   /// DrawFillRect({100, 100, 100,100}, {255,0,0,255}, window);
  for(auto& it : asteroids)
  {
      DrawFillRect({(int)it.x, (int)it.y, 100,100}, {255,0,0,255}, window);
  }
}