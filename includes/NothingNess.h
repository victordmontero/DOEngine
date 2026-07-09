#pragma once
#include <GameObject.h>
#include <Rect.h>
namespace doengine{

struct NothingNessObject : public GameObject{
    Rect rect;
    NothingNessObject(const Rect& offset): rect{offset}{}
    virtual void Update(float timer = 0)
    {
    
    }
    virtual void Render()
    {
        ///Does nothing
    }
};

}