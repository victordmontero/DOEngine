#include "Map.h"
#include "Texture.h"

Tile::Tile(int x, int y, int w, int h, int t, int l)
{
   this->type  = t;
   this->layer = l;
   offset.x= x;
   offset.y= y;
   offset.w= w;
   offset.h= h;
}
Tile::Tile()
{
   this->type  = 0;
   this->layer = 0;
   offset.x= -110;
   offset.y= -100;
   offset.w= 0;
   offset.h= 0;
}
Tile::Tile(SDL_Rect rect, int t, int l)
{
   this->type  = t;
   this->layer = l;
   offset.x= rect.x;
   offset.y= rect.y;
   offset.w= rect.w;
   offset.h= rect.h;
}
void Tile::Draw()
{
    Texture *texture = Texture::texture_ints[type];
    if(texture)
       texture->Draw(offset.x, offset.y, offset.w, offset.h);
}
void Tile::Update()
{


}


Tileset::Tileset(int r, int c, int *array, int tilesize)
{
   if(array)
   {
       for(int row =0; row<r;row++)
       {
           for(int col=0; col<c; col++ )
           {
               this->layer0.push_back(new Tile(col *tilesize, row *tilesize,tilesize,tilesize, array[row*col], 0));
           }
       }
   }
}

void Tileset::Draw()
{
    for(auto it : layer0)
        it->Draw();
}