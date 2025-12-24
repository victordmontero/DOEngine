#pragma once

#include "Timer.h"
#include "gmock/gmock.h"
#include <cstddef>

namespace doengine::mocks
{

using doengine::Timer;

class TimerMock : public Timer
{
    MOCK_METHOD(int, getLength(), (override));
    MOCK_METHOD(float getTime(), (override));
    MOCK_METHOD(bool isTimeout(), (override));
    MOCK_METHOD(void Update(float t), (override));
    MOCK_METHOD(void reset(), (override));
    MOCK_METHOD(void addTimerCallback(std::function<void()>) , (override));
    MOCK_METHOD(inline float getElapsedTime(), (override));
};


} // namespace doengine::mocks