#pragma once

#include "Tile.h"
#include "Window.h"


class TileMap
{
    double camera_x;
    double camera_y;
    int rows;
    int cols;


    int xmin,ymin;
    int xmax,ymax;

    double tween;

    
    Tile *map1;
    int numTileAcross;
    char tileset_id[64];

    int rowOffset;
    int colOffset;
    int numColToDraw;
    int numRowToDraw;

    int tilesize;

    public:

        TileMap(int tilesize, Window *window);
        void LoadTile(const char *image, const char *id);
        void LoadMap(const char *map, const char *id);

};