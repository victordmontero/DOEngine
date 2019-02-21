#pragma once
#include "Event.h"
#include "StateMachine.h"


struct OneLoneCoder : public GameState ,public KeyboardObserver
{

  OneLoneCoder(){}
  virtual ~OneLoneCoder(){}
  virtual void onEnter() override;
  virtual void onExit() override;
  virtual void Update() override;
  virtual void Render() override;

   virtual void onKeyDown(std::map<SDL_Keycode, bool>keys);
   virtual void onKeyUp(std::map<SDL_Keycode, bool>keys);

};