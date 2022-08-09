#include <fstream>
#include <SDL.h>
#include <stdio.h>
#include "Tilemap.h"


#define VALUE_IN_ARRAY(X,Y,W,A) A[Y*W+X]

 
TileMap::TileMap(Window* window)
{
	this->window = (window);
}

void TileMap::LoadMapFromArray(std::string strMap, int w, int h)
{

}