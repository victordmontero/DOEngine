#include "Texture.h"


std::map<int, Texture *> Texture::texture_ints;

 DrawConfiguration::DrawConfiguration()
 {
    sf      = nullptr;
    texture = nullptr;
    render  = nullptr;
 }

void Texture::extract_orginal_mod()
{
   if(this->texture_config)
   {
      SDL_GetTextureColorMod(texture_config->texture,
                             &texture_config->original_color.r,
                             &texture_config->original_color.g,
                             &texture_config->original_color.b
                             );
   }
}

    int Texture::getW(){
        if(texture_config->texture)
        {
           SDL_Log("GetW()=%d",this->texture_config->sf->w);
           return  this->texture_config->sf->w;
        }
        return -1;
    }
    int Texture::getH(){
        if(texture_config->texture)
        {
           SDL_Log("GetH()=%d",this->texture_config->sf->h);
           return this->texture_config->sf->h;
        }
        return -1;
    }
Texture::Texture(const char *src)
{
   this->texture_config = new DrawConfiguration();
   extern Window* window;
   texture_config->sf = SDL_LoadBMP(src);
   SDL_SetColorKey(texture_config->sf, SDL_TRUE, SDL_MapRGB(texture_config->sf->format, 0, 0, 0));
   this->texture_config->offset.x = 0;
   this->texture_config->offset.y = 0;
   this->texture_config->offset.w = texture_config->sf->w;
   this->texture_config->offset.h = texture_config->sf->h;
   SDL_Log("Width %d , Height %d",this->texture_config->offset.w ,this->texture_config->offset.h );
   this->texture_config->texture = SDL_CreateTextureFromSurface(window->getRender(),texture_config->sf);
   this->texture_config->valid = texture_config->texture!=nullptr;
   SDL_Log("valid = %d, SDL_GetError()=%s", texture_config->valid, SDL_GetError());
}

Texture::Texture(const char *src,SDL_Color color)
{
   this->texture_config = new DrawConfiguration();
   extern Window* window;
   texture_config->sf = SDL_LoadBMP(src);
   this->texture_config->offset.x = 0;
   this->texture_config->offset.y = 0;
   this->texture_config->offset.w = texture_config->sf->w;
   this->texture_config->offset.h = texture_config->sf->h;
   SDL_Log("Width %d , Height %d",this->texture_config->offset.w ,this->texture_config->offset.h );
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

void Texture::Draw(int x, int y, int w, int h, int cx, int cy, int cw, int ch)
{
    extern Window* window;
    SDL_Rect rect ={x,y,w,h};
    SDL_Rect clip ={cx, cy, cw, ch};
    SDL_RenderCopy(window->getRender(), texture_config->texture, &clip, &rect);
}

void Texture::DrawTexture(int id, Rect offset, Rect clip, float *angle, Point *point, bool flipped)
{
    ///SDL_Log("Texture id %d", id);
    extern Window* window;
    Texture *texture = Texture::texture_ints[id];
    if(texture && texture->texture_config->texture)
    {
       SDL_Rect clip_ = { clip.x , clip.y, clip.w, clip.h};
       SDL_Rect offset_ = { offset.x, offset.y, offset.w, offset.h};
       SDL_Point *point_ =nullptr;
       if(point)
       {
          point_ = new SDL_Point;
          point_->x = point->x;
          point_->y = point->y;
       }
     
        
       ///SDL_Log("Render Copy ex =%d",
       SDL_RenderCopyEx( window->getRender() ,
                         texture->texture_config->texture,
                         &clip_, 
                         &offset_,
                         ((angle!=nullptr)?*angle:0),
                          point_,
                         (flipped?SDL_FLIP_HORIZONTAL:SDL_FLIP_NONE)
         );
         
         delete point_;
         point_ = nullptr;
    }
    else{
       SDL_Log("Texture is null sad but true");
    }
}


bool Texture::LoadTexture(int id, const char *path)
{
  Texture::texture_ints[id] = new Texture(path);
  return Texture::texture_ints[id]!=NULL;
}