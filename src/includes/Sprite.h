#pragma once
#include <vector>
#include <map>

enum class DefaultSpritePosition{
	Idle,
	walkingLeft,
	walkingRight,
	walkingUp,
	walkingDown,
	runningLeft,
	runningRight,
	runningUp,
	runningDown,
};


class Sprite{
  
   protected:
   
   std::vector<DefaultSpritePosition> position;
  
   DefaultSpritePosition current_position;
  
   int current_number;
   
   public:
   
   
};