#pragma once

#include "GameState.h"
#include <gmock/gmock.h>

namespace doengine::mocks
{

class GameStateMock : public GameState
{
  public:
    MOCK_METHOD(void, OnEnter, (), (override));
    MOCK_METHOD(void, OnExit, (), (override));
    MOCK_METHOD(void, Update, (float elapsed), (override));
    MOCK_METHOD(void, Render, (), (override));
};

} // namespace doengine::mocks