#include <vector>

#include "PlatformState.h"
#include "PrimitivesGraphics.h"
#include "Geometric.h"
#include "Canvas.h"
#include "StandardFuncs.h"
#include "TTFText.h"


struct Circle{
  SDL_Rect rect;
  double radius;
};
Circle circle;
std::vector<Circle> circles;

void DrawCircle(Window *window, const Circle& circle){
    Canvas::fillStyle({0,0,255,255});
    SDL_Color blue={0,0,255,255};
    std::cout <<"x: "<< circle.rect.x<<" Y: "<< circle.rect.y <<"\n";
    FillCircle(circle.rect.x, circle.rect.y, circle.radius, blue, window);
}


void PlatformState::OnEnter(){ 

    Canvas::begin(window);
   
    Event::AddMouseEvent(this);
    TTFText::get()->setFont("/home/afl/Desktop/doengine/Carlito-Bold.ttf");    
    
}
void PlatformState::OnExit(){ 
    Canvas::end(window);
}
void PlatformState::Update(float elapsed){}

#include <sstream>

void PlatformState::Render(){
    // this->window->SetWindowPencilColor(255,0,0,255);
    // SDL_Rect rect={10,10,100,100};
    // DrawRect(window->getRender(), rect);
 
  
    
    //  std::stringstream stream;
    //  stream << "Random Value "<< getRandomInt(1, 3);
    //    Color color;
    //  color.r = 255;
    //  color.g = 255;
    //  color.b = 255;
    //  color.a = 255;
    //   Canvas::fillStyle(color);
   ///  TTFText::get()->DrawText(stream.str().c_str(), 100,300, window->getRender());


  ///  for(auto circle : circles)
       DrawCircle(window, circle);


 /*
    color.r = 255;
    color.g = 0;
    color.b = 100;
    color.a = 255;
    Canvas::fillStyle(color);
    FillCircle(100,100, 60, color, window);
    Canvas::setCurrentCanvasPosition(100,200);
    Canvas::setCurrentCanvasSize(400,400);
    color.r = 0;
    color.g = 255;
    color.b = 0;
    Canvas::fillStyle(color);
    Canvas::DrawRect(window, 10,10, 0,0);
    color.r =255;
    color.g = 255;
    color.b = 255;
    Canvas::fillRect(window, 10,10,40,40);
    color.b = 255;
    color.g = 0;
    Canvas::fillStyle(color);
    Canvas::arc(window, 100,100,50,120, 3.123 * 2);*/

}

void PlatformState::MouseMove(int x, int y){
      /// TTFText::get()->setColor({255,0,0,255});
     //  TTFText::get()->DrawText("Event Catched ", 100,300, window->getRender());
     ///SDL_Log("SDL_MOUSEMOTION x: %ld,  y:%ld", x,  y);
     ///Circle circle;
     circle.rect.x = x;
     circle.rect.y = y;
     circle.rect.w = 20;
     circle.rect.h = 30;
     circle.radius = 25;
     SDL_Log("moving event");
     ///circles.emplace_back(circle);
}