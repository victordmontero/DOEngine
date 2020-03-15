#pragma once 
#include <SDL2/SDL.h>
#include <string>
#include <map>

class Texture
{
   static std::map<std::string, SDL_Texture*>textures;

   public:

   static bool IsloadThisTexture(std::string id);
   static int LoadTexture(std::string path, std::string id, SDL_Renderer *render);
   static void DrawImage(std::string id, int x, int y, int w, int h, SDL_Renderer *render);
};