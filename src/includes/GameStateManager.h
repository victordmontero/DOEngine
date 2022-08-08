#pragma once

#include <map>
#include <string>
#include "Window.h"
#include "GameState.h"

class Window;
class GameState;
class GameStateManager{

  Window *window;
  std::map<int, GameState *>states;
  int current_state;

  public:

  GameStateManager(Window *window);
  void AddState(int state_id, GameState *object);
  void RemoveState(int state_id);
  void SetState(int state_id);

  void Update(float elapsed);
  void Render();
};