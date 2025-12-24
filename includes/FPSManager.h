#pragma once
#include <stdint.h>
#include <functional>
#include <memory>
#include <vector>

namespace doengine
{
class FpsManager
{
    uint32_t start, elapsed, wait, fps, last_elapsed;
    uint64_t lastCounter;
    uint64_t frequency;
  public:
    FpsManager() : start(0L), elapsed(0L), fps(60L), last_elapsed(0.0f)
    {
    }

    virtual ~FpsManager()
    {
    }

    virtual void setFPS(long fps = 60);
    virtual void Start();
    virtual void Handle();
    virtual uint32_t getDeltaTime();
    virtual float getElapsedTime();
    virtual float getLastElapsedTime();
    void beginFrame();
    double endFrame();
    static double getTicks();
};



 
/*
class TimerManager {
public:
    void update(float deltaSeconds);

    Timer& addTimer(float seconds, Timer::Callback cb, bool repeat = false);
    void clear();

private:
    std::vector<std::unique_ptr<Timer>> m_timers;
};

*/


} // namespace doengine