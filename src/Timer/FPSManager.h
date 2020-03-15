#pragma once


class FpsManager{
    long start,elapsed,wait, fps;
    public:
      FpsManager();
      void setFPS(long fps=60);
      void Start();
      void Handle();
      float getElapsedTime();
};