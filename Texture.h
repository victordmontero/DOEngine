#pragma once
#include <map>
#include <SDL2/SDL.h>
#include "Window.h"
 
struct DrawConfiguration
{
   SDL_Rect  *offset;
   SDL_Rect  *clip;
   SDL_Point *point;
   SDL_Surface *sf;
   SDL_Texture *texture;
   SDL_Renderer *render;
   int id; 
   bool valid;
   DrawConfiguration();
};


class Texture
{
    DrawConfiguration *texture_config;
public:

   Texture(const char *src);
   Texture(const char *src,SDL_Color color);
   ~Texture();
    void Draw(int x, int y, int w, int h);

   static std::map<int, Texture *>texture_ints;
   
};