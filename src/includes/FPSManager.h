#pragma once

class FpsManager
{
    long start, elapsed, wait, fps;

  public:
    FpsManager();
    virtual void setFPS(long fps = 60);
    virtual void Start();
    virtual void Handle();
    virtual float getElapsedTime();
};