#pragma once 

#include "GameState.h"
#include<vector>

class AsteroidState : public GameState
{


    struct spaceObject
    {
        float x,y,dx,dy;
        int size;
        /* data */
    };
     
     std::vector<spaceObject> asteroids;
 
 
public:
   AsteroidState(Window *window);
   virtual void OnEnter();
   virtual void OnExit();
   virtual void Update(float elapsed);
   virtual void Render();

};