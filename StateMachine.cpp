
#include "StateMachine.h"

void GameStateMachine::addState(int state_id, GameState *game)
{
    if(!this->states[state_id])
        this->states[state_id] = game;
}
void GameStateMachine::removeState(int state_id)
{
    GameState *get = states[state_id];
    if(get)
    {
        ///std::map remove or other iterator remove function.
    }
}
void GameStateMachine::setState(int state_id)
{
    if(current_state != -1)
    {
        if(states[current_state] && states[state_id])
        {
              states[current_state]->onExit();
              current_state = state_id;
              states[current_state]->onEnter();
        }
    }
}
void GameStateMachine::Update(SDL_Event *event)
{
   if(current_state!=-1 && states[current_state])
       states[current_state]->Update(event);
}
void GameStateMachine::Render(SDL_Renderer *render)
{
       if(current_state!=-1 && states[current_state])
       states[current_state]->Render(render);
}