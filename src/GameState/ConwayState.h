
#pragma once

#include "GameState.h"

#include "../Drawable/Grids.h"

class ConwayState : public GameState{

    Grid2D<32,32,bool> network;
  public:

   ConwayState(Window *w):GameState(w){
   }
   virtual void OnEnter();
   virtual void OnExit();
   virtual void Update(float elapsed);
   virtual void Render();

};