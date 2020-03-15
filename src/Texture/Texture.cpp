#include "Texture.h"
///#include <SDL2/SDL_image.h>


std::map<std::string, SDL_Texture*>Texture::textures;


bool Texture::IsloadThisTexture(std::string id){
    if(id.length()>0)
       return textures[id]!=NULL;
    return false;
}


int Texture::LoadTexture(std::string path, std::string id, SDL_Renderer *render){
    if(path.length()>0&& id.length()>0)
    {
         if(IsloadThisTexture(id)==true)
           return 2;
        SDL_Surface *surface = SDL_LoadBMP(path.c_str());
        if(surface!=NULL)
        {
               /*
                  WHITE IS TRANSPARENT.
                  @todo please optimize this, and add SDL_Img
               
               */
            SDL_SetColorKey(surface,SDL_TRUE ,SDL_MapRGB(surface->format, 255,255,255));
            textures[id]= SDL_CreateTextureFromSurface(render, surface);
        }
    }
    return -1;
}


void Texture::DrawImage(std::string id, int x, int y, int w, int h, SDL_Renderer *render)
{
    if(IsloadThisTexture(id))
    {
        SDL_Rect offset={x,y,w,h};
        SDL_Rect clipset={0,0,0,0};
        SDL_RenderCopy(render, textures[id], NULL, &offset);
    }
}