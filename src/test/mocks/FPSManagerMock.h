#pragma once

#include "FPSManager.h"
#include <gmock/gmock.h>

namespace doengine::mocks
{

class FpsManagerMock : public FpsManager
{
  public:
    MOCK_METHOD(void, setFPS, (long fps), (override));
    MOCK_METHOD(void, Start, (), (override));
    MOCK_METHOD(void, Handle, (), (override));
    MOCK_METHOD(float, getElapsedTime, (), (override));
};

} // namespace doengine::mocks