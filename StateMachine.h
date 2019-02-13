#pragma once
#include <SDL2/SDL.h>
#include <map>
 



class GameState
{
  protected:

  
  
  public:
  
  GameState(){}
  virtual ~GameState(){}
  virtual void onEnter()=0;
  virtual void onExit()=0;
  virtual void Update(SDL_Event *event)=0;
  virtual void Render(SDL_Renderer *render)=0;
};




class GameStateMachine{
   std::map<int, GameState*>states;
   int current_state;

public:  
    GameStateMachine(){
        current_state = -1;
    }
    void addState(int state_id, GameState *game);
    void removeState(int state_id);
    void setState(int state_id);

    void Update(SDL_Event *event);
    void Render(SDL_Renderer *render);

 };