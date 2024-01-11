#pragma once

#include "Color.h"
#include "abstract/AbstractWindow.h"
#include <SDL2/SDL.h>
#include <string>
#include <vector>

struct CanvasCommand
{
    virtual void Draw(doengine::AbstractWindow* window) = 0;
};

struct CanvasRectCommand : public CanvasCommand
{
    SDL_Rect offset;
    SDL_Color color;
    bool filled;
    virtual void Draw(doengine::AbstractWindow* window) override;
};

struct CanvasPointDrawCommand : public CanvasCommand
{
    SDL_Rect offset;
    SDL_Color color;
    virtual void Draw(doengine::AbstractWindow* window) override;
};

struct CanvasCircleCommand : public CanvasCommand
{

    double radius;
    SDL_Point where;
    SDL_Color color;

    virtual void Draw(doengine::AbstractWindow* window) override;
};

struct CanvasTextDrawerCommand : public CanvasCommand
{

    SDL_Point where;
    doengine::Color color;
    std::string text;
    virtual void Draw(doengine::AbstractWindow* window) override;
};

class Canvas
{

    doengine::AbstractWindow* window;
    SDL_Color _bg;
    SDL_Color _filler;
    SDL_Rect _offset;
    bool clear = false;

    std::vector<CanvasCommand*> commands_to_draw;

  public:
    const static SDL_Color black;

    Canvas(doengine::AbstractWindow* window);

    Canvas* fillColor(SDL_Color color);
    Canvas* setRect(SDL_Rect rect);

    Canvas* DrawRect(int x, int y, int w, int h, bool filled);
    Canvas* DrawPoint(int x, int y);
    Canvas* FillCircle(int x, int y, double rsize = 50);
    Canvas* FillText(const char* str, int x, int y);

    Canvas* setCanvasBackgroundColor(SDL_Color color);
    Canvas* update();
    Canvas* clearCanvas();

    void getColor(SDL_Color* color)
    {
        color = &_filler;
    }

    const SDL_Rect getCanvasSize() const
    {
        return _offset;
    }
};