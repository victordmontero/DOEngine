#pragma once

#include <string>
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

struct CanvasPointDrawCommand : public CanvasCommand{
     SDL_Rect offset;
     SDL_Color color;
    virtual void Draw(Window *window) override;
};

struct CanvasCircleCommand : public CanvasCommand{

      double radius;
      SDL_Point where;
      SDL_Color color;

      virtual void Draw(Window *window) override;
};


struct CanvasTextDrawerCommand : public CanvasCommand{

    SDL_Point where;
    SDL_Color color;
    std::string text;
    virtual void Draw(Window *window) override;

};




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
   Canvas* setRect(SDL_Rect rect);

   Canvas* DrawRect(int x, int y, int w, int h);
   Canvas* DrawPoint(int x, int y);
   Canvas* FillCircle(int x, int y, double rsize=50);
   Canvas* FillText(const char *str, int x, int y);

   Canvas* setCanvasBackgroundColor(SDL_Color color);
   Canvas* update(); 
   Canvas* clearCanvas();


    SDL_Color getColor(SDL_Color *color){
        color = &_filler;
    }


    const SDL_Rect getCanvasSize()const {
    return _offset;
   }
};