#pragma once
#include "Application.h"
#include "GameObject.h"
#include "Timer.h"
#include <vector>
namespace doengine
{
class Background : public GameObject
{
  public:
    Background()
    {
    }
    virtual ~Background()
    {
    }
    virtual void Update(long timestamp) = 0;
    virtual void Draw() = 0;
};

class ParallaxBackground : public Background
{
  Timer *timer;
  std::vector<std::variant<std::string, int>> texture_ids;
  public:
    ParallaxBackground();
    virtual ~ParallaxBackground();
    virtual void Update(long timestamp);
    virtual void Draw();
};

}