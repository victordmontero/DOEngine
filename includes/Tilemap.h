#pragma once

#include <cstddef>
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
    void LoadMapFromArray(std::vector<unsigned> uMap, int w, int h);
};