#pragma once

#include <string>
#include <vector>

#include "Tile.h"
#include "abstract/AbstractWindow.h"

using doengine::AbstractWindow;

class TileMap
{
    AbstractWindow* window;
    typedef std::vector<Tile> TilesetLayer;
    std::vector<TilesetLayer> layers;
    int w;
    int h;

  public:
    TileMap(AbstractWindow* window);

    void LoadMapFromArray(std::string strMap, int w, int h);
};