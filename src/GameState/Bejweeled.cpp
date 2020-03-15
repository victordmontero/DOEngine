#include "Bejweeled.h"
#include "../Drawable/Geometric.h"
#include "../Font/TTFText.h"
#include "../Event/Event.h"
#include <stdlib.h>
#include <time.h>

BejweeledState::BejweeledState(Window *window):GameState(window){

}

SDL_Color getColor(int i)
{
    switch(i)
    {
       case 0:return SDL_Color{255,255,255,255};
       case 1:return SDL_Color{255,0,255,255};
       case 2:return SDL_Color{0,255,255,255};
       case 3:return SDL_Color{255,255,0,255};
       case 4:return SDL_Color{100,125,255,255};
       case 5:return SDL_Color{100,0,205,255};
       case 6:return SDL_Color{100,205,15,255};
       case 7:return SDL_Color{25,155,155,255};
       default:return SDL_Color{0xFF, 0xfa, 0xfa,255};

    };
}


void BejweeledState::OnEnter(){
   srand(time(NULL));
 
   for(int i=1;i<=8;i++)
    for(int j=1;j<=8;j++)
    {
        grid[i][j].kind=rand()%7;
        grid[i][j].col = j;
        grid[i][j].row = i;
        grid[i][j].x   = j * ts;
        grid[i][j].y   = i * ts;
    }

}
void BejweeledState::OnExit(){

}
void BejweeledState::Update(float elapsed){
   if(Event::mousePressed)
   {

   }
}
void BejweeledState::Render(){

   
   for(int i=1;i<=8;i++)
    for(int j=1;j<=8;j++)
    {
        piece gem = grid[i][j];
        SDL_Color color= getColor(gem.kind);
        Rect rect={gem.x, gem.y, ts, ts};
        
         DrawFillRect(rect, color,window);
         DrawRect(rect, SDL_Color{0,0,0,244}, window);
    }


}