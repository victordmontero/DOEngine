#include <fstream>
#include <SDL2/SDL.h>
#include <stdio.h>
#include "Tilemap.h"


TileMap::TileMap(int tilesize, Window *window){
    this->tilesize = tilesize;
    numColToDraw = window->getH() / tilesize + 2;
    numRowToDraw = window->getW() / tilesize + 2;
    tween = 0.07;
}

 void TileMap::LoadTile(const char *image, const char *id){
     SDL_Log("TO do: Implement this routine");
 }

  void TileMap::LoadMap(const char *map, const char *id)
  {
    
      std::fstream fsmap(map, std::ios::in);
      fsmap >> rows;
      fsmap >> cols;
      SDL_Log("load map %s[%d][%d]",map, rows,cols);

       for(int i=0;i<rows;i++)
       {
           for(int j=0;j<cols;j++)
           {
               int c;
               fsmap >> c;
               printf("%d", c);


           }
           printf("\n");
       }



      fsmap.close();
  }