
#include "GameState.h"

constexpr int ts = 54;

class BejweeledState : public GameState
{
   struct piece{
       int kind;
       int x;
       int y;
       int row;
       int col;
       int match;
       piece(){
           match=0;
       }
   };
   piece grid[10][10];
   void SwapPiece(piece p1, piece p2)
   {
       std::swap(p1.col, p2.col);
       std::swap(p1.row, p2.row);

       grid[p1.row][p1.col]=p1;
       grid[p2.row][p2.col]=p2;


   }


public:
   BejweeledState(Window *window);
   virtual void OnEnter();
   virtual void OnExit();
   virtual void Update(float elapsed);
   virtual void Render();

};