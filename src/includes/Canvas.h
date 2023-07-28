#pragma once


#include <SDL2/SDL.h>
#include "Window.h"
#include <vector>

struct CanvasCommand{
    virtual void Draw(Window *window) = 0;
};

struct CanvasRectCommand : public CanvasCommand{
     SDL_Rect offset;
     SDL_Color color;
     bool filled;
     virtual void Draw(Window *window) override;
};

// struct CanvasCircleCommand : public CanvasCommand{

// };


class Canvas{

   Window       *window;
   SDL_Color     _bg;
   SDL_Color     _filler;
   SDL_Rect      _offset;
   bool          clear=false;

   std::vector<CanvasCommand *> commands_to_draw;


 

   public:
   
   
   Canvas(Window *window);  

   Canvas* fillColor(SDL_Color color);
   Canvas* setPosition(SDL_Rect rect);

   Canvas* DrawRect(int x, int y, int w, int h);

   Canvas* setCanvasBackgroundColor(SDL_Color color);
   Canvas* update(); 
};