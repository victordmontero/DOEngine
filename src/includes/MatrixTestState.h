#include "GameState.h"
#include "GameObject.h"
#include "Canvas.h"
#include "EventHandler.h"
#include "Canvas.h"
class MatrixTestState : public GameState 
{
   Canvas *canvas;
   int pencil_size =20;
   Canvas *pencil1;

public:
   MatrixTestState(Window *w):GameState(w){
   }
   virtual void OnEnter()override;
   virtual void OnExit()override;
   virtual void Update(float elapsed) override;
   virtual void Render() override;


  
};