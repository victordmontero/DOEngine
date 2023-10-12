#include "Tilemap.h"
#include "abstract/AbstractWindow.h"
#include <SDL2/SDL.h>
#include <fstream>
#include <stdio.h>

#define VALUE_IN_ARRAY(X, Y, W, A) A[Y * W + X]

TileMap::TileMap(doengine::AbstractWindow* window)
{
    this->window = (window);
}

void TileMap::LoadMapFromArray(std::string strMap, int w, int h)
{
}