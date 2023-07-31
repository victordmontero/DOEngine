#include "CanvasTestState.h"
#include "Event.h"
#include "StandardFuncs.h"


#include <vector>

struct Particle{
   SDL_Point rect;
   Canvas *ctx;
   double size;

   double sx;
   double sy;

   Particle(Canvas *canvas)
   {
   
        sx = getRandomInt(1, 4);
        sy = getRandomInt(1, 4);

       ctx = canvas;
       ///rect.x = getRandomInt(10, canvas->getCanvasSize().w );
       //rect.y = getRandomInt(10, canvas->getCanvasSize().h );
       size = getRandomInt(10, 32 );
   }

   void Draw(){
      
       SDL_Color penColor = {255,255,255,255};
       
       if(size > 24)
       {
        penColor.r = 255;
        penColor.g = 0;
        penColor.b = 0;
       }
       else if( size > 20)
       {
          penColor.r = 255;
          penColor.g =50;
          penColor.b = 0;
       }else
       {
                    penColor.r = 255;
          penColor.g =100;
          penColor.b = 120;
       }
       ctx->fillColor(penColor);
      
       ctx->FillCircle(rect.x, rect.y,size);
   }

   void update(){
 
    if(size > 0.2)
        size -= 0.3;


     rect.x += sx;
     rect.y += sy;


   }
};


std::vector<Particle *> particles;


void CanvasTestState::OnEnter(){
    pencil1 = new Canvas(this->window);
    pencil1->fillColor({255,0,0,255});
    pencil1->setCanvasBackgroundColor({0,0,0,255});

    Event::AddMouseEvent(this);

    // for(int i=0;i<10;i++)
    // {
    //     particles.emplace_back(new Particle(pencil1));
    // }
}
void CanvasTestState::OnExit(){}
void CanvasTestState::Update(float elapsed) {

  ////  SDL_Log("Particle Size = %ld", particles.size());
   
        for(auto it : particles)
         {
            it->update();
         }

 

}
void CanvasTestState::Render() {
    for(auto it : particles)
    {
        if(it->size<0.3)
        {
            SDL_Log("thIS SHOULD BE REMOVED");
            ///particles.erase(*it);
            ///std::remove(particles.begin(), particles.end(), it);
           // particles.erase();
          /// auto it = std::find(v.begin(), v.end(), 5);
         // if(it != v.end())
          //  v.erase(it);
        }
        else
        {
            it->Draw();
        }
    }
    pencil1->update();
    pencil1->clearCanvas();
}

void CanvasTestState::MouseMove(int x, int y)
{
   ///int x= 0;
  /// int y=0;
  /// Event::getMousePosition(&x,&y);

   for(int i=0;i<10;i++){
      Particle *particle = new Particle(this->pencil1);
      particle->size   = getRandomInt(20,30);
      particle->rect.x = getRandomInt(x-5, x + 5);
      particle->rect.y = getRandomInt(y-5, y + 5);
      int sx = getRandomInt(1,2)==2? -1 : 1;
      int sy = getRandomInt(1,2)==2? -1 : 1;
      particle->sx *= sx;
      particle->sy *= sy;

      particles.emplace_back(particle);
   }

}
void CanvasTestState::MouseButtonDown(int which)
{
   SDL_Log("Button down");
   int x= 0;
   int y=0;
   Event::getMousePosition(&x,&y);

   for(int i=0;i<10;i++){
      Particle *particle = new Particle(this->pencil1);
      particle->size   = getRandomInt(20,30);
      particle->rect.x = getRandomInt(x-5, x + 5);
      particle->rect.y = getRandomInt(y-5, y + 5);
      int sx = getRandomInt(1,2)==2? -1 : 1;
      int sy = getRandomInt(1,2)==2? -1 : 1;
      particle->sx *= sx;
      particle->sy *= sy;

      particles.emplace_back(particle);
   }
}