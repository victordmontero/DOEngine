#include "Texture.h"


std::map<int, Texture *> Texture::texture_ints;

 DrawConfiguration::DrawConfiguration()
 {
    offset  = nullptr;
    clip    = nullptr;
    point   = nullptr;
    sf      = nullptr;
    texture = nullptr;
    render  = nullptr;
 }

Texture::Texture(const char *src)
{
   this->texture_config = new DrawConfiguration();
   extern Window* window;
   this->texture_config->texture = SDL_CreateTextureFromSurface(window->getRender(),SDL_LoadBMP(src));
   this->texture_config->valid = texture_config->texture!=nullptr;
   SDL_Log("valid = %d, SDL_GetError()=%s", texture_config->valid, SDL_GetError());
}

Texture::Texture(const char *src,SDL_Color color)
{
   this->texture_config = new DrawConfiguration();
   extern Window* window;
   texture_config->sf = SDL_LoadBMP(src);
   SDL_SetColorKey(texture_config->sf, SDL_TRUE, SDL_MapRGB(texture_config->sf->format, color.r, color.g, color.b));
   this->texture_config->texture = SDL_CreateTextureFromSurface(window->getRender(),texture_config->sf);
   this->texture_config->valid = texture_config->texture!=nullptr;
   SDL_Log("valid = %d, SDL_GetError()=%s", texture_config->valid, SDL_GetError());
}

Texture::~Texture()
{
}
void Texture::Draw(int x, int y, int w, int h)
{
    extern Window* window;
    SDL_Rect rect ={x,y,w,h};
    SDL_RenderCopy(window->getRender(), texture_config->texture, NULL, &rect);
}