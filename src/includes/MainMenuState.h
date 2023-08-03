#pragma once 
#include <GameState.h>
#include <Canvas.h>

class MainMenuState : public GameState{

   public:
   MainMenuState(Window *w):GameState(w){}
   virtual void OnEnter();
   virtual void OnExit();
   virtual void Update(float elapsed);
   virtual void Render();
 
};