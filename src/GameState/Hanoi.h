#pragma once
#include <stack>
#include "GameState.h"
#include "../Window/Window.h"
class Window;

class HanoiState : public GameState
{
   

   struct TDisk{
       int size;
       int current_position;
   };

   struct Tower{
        std::stack<TDisk> disk;
        int which;
   };

   Tower towers[3];

  public:
    HanoiState(Window *w):GameState(w){
   }
   virtual void OnEnter();
   virtual void OnExit();
   virtual void Update(float elapsed);
   virtual void Render();
};