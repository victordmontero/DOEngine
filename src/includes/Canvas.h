#include <SDL2/SDL.h>
#include "Window.h"



namespace Canvas{

void begin(Window *window);
void end(Window *window);
void setCurrentCanvasPosition(int x, int y);
void setCurrentCanvasSize(int w, int h);
void fillStyle(SDL_Color color);
void fillRect(Window *window, int x, int y, int w, int h);
void DrawRect(Window *window, int x, int y, int w, int h);
void arc(Window *window, int x, int y, int radius, double startAngle, double endAngle);
};