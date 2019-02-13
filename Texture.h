#pragma once
#include <map>
#include <SDL2/SDL.h>
#include "Window.h"
 
struct DrawConfiguration
{
   SDL_Rect  offset;
   SDL_Rect  clip;
   SDL_Point point;
   SDL_Surface *sf;
   SDL_Texture *texture;
   SDL_Renderer *render;
   SDL_Color original_color;
   SDL_Color mod_color;
   float angle;
   int id; 
   bool valid;
   DrawConfiguration();
};


class Texture
{
    DrawConfiguration *texture_config;

    void extract_orginal_mod();

public:

    Texture(const char *src);
    Texture(const char *src,SDL_Color color);
   ~Texture();
    void Draw(int x, int y, int w, int h);
    void Draw(int x, int y, int w, int h, int cx, int cy, int cw, int ch);

   static std::map<int, Texture *>texture_ints;
   static bool LoadTexture(int id, const char *path);
};