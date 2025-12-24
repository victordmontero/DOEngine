#ifndef TIMER_H_DEFINED
#define TIMER_H_DEFINED
#include <functional>
namespace doengine
{

class Timer
{
  private:
    bool pause = false;
    bool timeout = false;
    float len = 0;
    float current_time = 0;
    std::function<void()> timeout_callback;

  public:
    Timer(float length);
    ~Timer();
    virtual int getLength();
    virtual float getTime();
    virtual bool isTimeout();
    virtual void Update(float t);
    virtual void reset();
    virtual void addTimerCallback(std::function<void()> cb);
    virtual float getElapsedTime();
};

}; // namespace doengine

#endif