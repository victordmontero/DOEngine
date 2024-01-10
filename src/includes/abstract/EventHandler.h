#pragma once

// #include "DOEngine.h"

class KeyDownEvent
{

  public:
    ~KeyDownEvent()
    {
    }

    virtual void OnKeydown(int code) = 0;
};

class KeyUpEvent
{

  public:
    ~KeyUpEvent()
    {
    }

    virtual void OnKeyup(int code) = 0;
};

class MouseMovementEvent
{

  public:
    ~MouseMovementEvent()
    {
    }

    virtual void OnMouseMovement(int x, int y) = 0;
};

class MouseStopEvent
{

  public:
    ~MouseStopEvent()
    {
    }

    virtual void OnMouseMovement(int x, int y) = 0;
};

class TouchEventDown
{

  public:
    ~TouchEventDown()
    {
    }

    virtual void OnTouchDown(int x, int y) = 0;
};

class TouchUpDown
{

  public:
    ~TouchUpDown()
    {
    }

    virtual void OnTouchUp(int x, int y) = 0;
};

class OnMessageQueue
{
  public:
    ~OnMessageQueue()
    {
    }

    virtual void HandleByDescriptor(int fd, void* buffer) = 0;
};

struct MouseEvent
{

    virtual ~MouseEvent()
    {
    }

    virtual void MouseMove(int x, int y) = 0;

    virtual void MouseButtonDown(int which) = 0;

    virtual void MouseButtonUp(int which) = 0;
};