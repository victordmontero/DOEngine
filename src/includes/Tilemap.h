#pragma once

#include <vector>
#include <string>

#include "Tile.h"
#include "Window.h"


 


class TileMap
{
    Window*  window;
    typedef std::vector<Tile> TilesetLayer;
    std::vector<TilesetLayer> layers;
    int w;
    int h;
    public:

    TileMap(Window* window);

    void LoadMapFromArray(std::string strMap, int w, int h);
   

};