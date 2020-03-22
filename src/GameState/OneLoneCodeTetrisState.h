#pragma once

#include "GameState.h"



class OneLoneCodeTetrisState: public GameState
{
    public:
   virtual ~OneLoneCodeTetrisState(){}
   OneLoneCodeTetrisState(Window *w):GameState(w){
   }
   virtual void OnEnter()override;
   virtual void OnExit()override;
   virtual void Update(float elapsed)override;
   virtual void Render()override;
};