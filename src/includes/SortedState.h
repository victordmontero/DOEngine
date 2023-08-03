#pragma once
#include <GameState.h>
#include <Canvas.h>
#include <vector>
#include <EventHandler.h>
class SortedState : public GameState, KeyDownEvent{

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


   int current_index = 0;
   bool next = false;

   public:


   void OnKeydown(int code)override;
   SortedState(Window *w):GameState(w){}
   
   virtual void OnEnter()override;
   virtual void OnExit()override;
   virtual void Update(float elapsed)override;
   virtual void Render()override;

};