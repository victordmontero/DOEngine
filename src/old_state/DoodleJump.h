#pragma once

#include "StateMachine.h"
#include "Window.h"
#include "Texture.h"
#include "GeometricRender.h"



class DoodleState : public GameState,public KeyboardObserver
{
  protected:
  public:
  
  DoodleState(){}
  virtual ~DoodleState(){}
  virtual void onEnter();
  virtual void onExit();
  virtual void Update();
  virtual void Render();
  virtual void onKeyDown(std::map<SDL_Keycode, bool>keys);
   virtual void onKeyUp(std::map<SDL_Keycode, bool>keys);
};
