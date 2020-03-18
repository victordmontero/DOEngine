#include "Hanoi.h"
#include  "../Drawable/Geometric.h"


void HanoiState::OnEnter()
{
    for(int i=0;i<3;i++)
    {
        towers[0].which = i;
        SDL_Log("towe =%d",towers[0].which);
    }



}
void HanoiState::OnExit(){}
void HanoiState::Update(float elapsed){}
void HanoiState::Render()
{
    
   
                DrawRect({20,300,50,400},{0xFF,0 ,0,0xff},window);
 
                DrawFillRect({20+10+50,300,50,400},{0xFF,0xff ,0,0xff},window);
      DrawFillRect({20+10+50+50,300,50,400},{0x11,0xff ,0,0xff},window);


}