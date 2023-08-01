#pragma once
#include <GameState.h>
#include <Canvas.h>
#include <vector>
class SortedState : public GameState{

   struct ColumnEntry{
       SDL_Rect offset;
       int value;
   };

   int width;
   int inner_width;
   int window_width;
   int height;

   std::vector<ColumnEntry *>entries;

   Canvas *ctx;

   public:



   SortedState(Window *w):GameState(w){}
   
   virtual void OnEnter()override;
   virtual void OnExit()override;
   virtual void Update(float elapsed)override;
   virtual void Render()override;

};