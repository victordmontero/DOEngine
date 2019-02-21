#pragma once

#include "Event.h"
#include "StateMachine.h"


class SnakeState : public GameState, public KeyboardObserver
{
 
  protected:

  
  
  public:
  
  SnakeState(){}
  virtual ~SnakeState(){}
  virtual void onEnter();
  virtual void onExit();
  virtual void Update();
  virtual void Render();
  virtual void onKeyDown(std::map<SDL_Keycode, bool>keys);
   virtual void onKeyUp(std::map<SDL_Keycode, bool>keys);
};
 

