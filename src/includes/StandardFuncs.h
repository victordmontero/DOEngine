#pragma once 
#include <SDL2/SDL.h>
#include <random>
#include <iostream>
template<typename V1, typename V2>
struct Optional{
   V1 v1;
   V2 v2;
};

inline int getRandomInt(int startRange, int endRange){
  std::random_device rd;
  std::uniform_int_distribution<int>dist(startRange, endRange);
  auto ret = dist(rd);
  return ret;
}

inline int getPercentageFrom(int currentValue, int maxValue){
  
  return currentValue;
}


