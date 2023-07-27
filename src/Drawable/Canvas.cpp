#include "Geometric.h"
 
#include "Window.h"
#include "Canvas.h"

namespace Canvas{
namespace {
    SDL_Color _color={0,0,0,255};
    SDL_Rect  _offset={0,0,800,800};
}
void begin(Window *window){
    window->dontClear();
}
void end(Window *window){
    window->setClear();
}

void setCurrentCanvasPosition(int x, int y){
   _offset.x = x;
   _offset.y = y;
}
void setCurrentCanvasSize(int w, int h){
    _offset.w = w;
    _offset.h = h;
}

void fillStyle(SDL_Color color){
    _color.r = color.r;
    _color.g = color.g;
    _color.b = color.b;
    _color.a = color.a;
}
void fillRect(Window *window, int x, int y, int w, int h){
    SDL_Rect rect{_offset.x + x, _offset.y+ y,w,h};
    DrawFillRect(rect,_color,window);
}

void DrawRect(Window *window, int x, int y, int w, int h){
    SDL_Rect rect{_offset.x + x, _offset.y+ y,_offset.w,_offset.h};
    DrawRect(rect,_color,window);
}
void arc(Window *window, int x, int y, int radius, double startAngle, double endAngle ) {
    
  
    const int NUM_SEGMENTS = 100; // Number of line segments to approximate the arc
    SDL_SetRenderDrawColor(window->getRender(), _color.r, _color.g, _color.b, _color.a);
 
    for (int i = 0; i <= NUM_SEGMENTS; ++i) 
    {
        double angle = startAngle + (endAngle - startAngle) * i / NUM_SEGMENTS;
        int x1 = x + static_cast<int>(radius * cos(angle));
        int y1 = y + static_cast<int>(radius * sin(angle));
        
          SDL_RenderDrawPoint(window->getRender(), _offset.x+x1, _offset.y+ y1);
 
    }
 
}


};