#pragma once 
#include <random>

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




