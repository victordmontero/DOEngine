#include "Window.h"
#include "GameState.h"
#include "GameObject.h"
#include "Canvas.h"
#include "abstract/EventHandler.h"
#include "Canvas.h"

class MatrixTestState : public GameState 
{
   Canvas *canvas;
   int pencil_size =20;
   Canvas *pencil1;

public:
   MatrixTestState(doengine::AbstractWindow *w):window(w){
   }
   virtual void OnEnter()override;
   virtual void OnExit()override;
   virtual void Update(float elapsed) override;
   virtual void Render() override;

private:
   doengine::AbstractWindow* window;

};