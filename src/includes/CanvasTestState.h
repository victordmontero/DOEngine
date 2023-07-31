#pragma once

#include "GameState.h"
#include "GameObject.h"
#include "Canvas.h"
#include "EventHandler.h"
class CanvasTestState : public GameState, MouseEvent
{
  
   int pencil_size =20;
   Canvas *pencil1;

public:
   CanvasTestState(Window *w):GameState(w){
   }
   virtual void OnEnter()override;
   virtual void OnExit()override;
   virtual void Update(float elapsed) override;
   virtual void Render() override;


   virtual void MouseMove(int x, int y);
   virtual void MouseButtonDown(int which);
   virtual void MouseButtonUp(int which){}
};