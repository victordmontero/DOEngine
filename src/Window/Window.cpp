
#include <vector>
#include <sstream>

extern "C" {
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
}

#include "DOEngine.h"
#include <TTFText.h>


#include <CanvasTestState.h>
#include <MatrixTestState.h>
#include <SortedState.h>
#include <TileMapTestState.h>

#include <iostream>
#include <source_location>
#include <string_view>
 
// Create a gradient color between two colors at a specific position
SDL_Color GradientColor(SDL_Color startColor, SDL_Color endColor, float position) {
    SDL_Color result;
    result.r = startColor.r + (endColor.r - startColor.r) * position;
    result.g = startColor.g + (endColor.g - startColor.g) * position;
    result.b = startColor.b + (endColor.b - startColor.b) * position;
    result.a = startColor.a + (endColor.a - startColor.a) * position;
    return result;
}

// Draw a horizontal line on the renderer with a gradient
void DrawGradientHorizontalLine(SDL_Renderer* renderer, int x, int y, int width, SDL_Color startColor, SDL_Color endColor) {
    for (int i = 0; i < width; i++) {
        float position = (float)i / (float)(width - 1); // Normalized position for the gradient
        SDL_Color color = GradientColor(startColor, endColor, position);
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_RenderDrawPoint(renderer, x + i, y);
    }
}

// Draw a gradient-filled rectangle on the renderer
void DrawGradientRect(SDL_Renderer* renderer, int x, int y, int width, int height, SDL_Color startColor, SDL_Color endColor) {
    for (int i = 0; i < height; i++) {
        float position = (float)i / (float)(height - 1); // Normalized position for the gradient
        SDL_Color color = GradientColor(startColor, endColor, position);
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_RenderDrawLine(renderer, x, y + i, x + width - 1, y + i);
    }
}

// Draw a gradient-filled circle on the renderer
void DrawGradientCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius, SDL_Color startColor, SDL_Color endColor) {
    for (int y = centerY - radius; y <= centerY + radius; y++) {
        for (int x = centerX - radius; x <= centerX + radius; x++) {
            float distance = sqrtf((x - centerX) * (x - centerX) + (y - centerY) * (y - centerY));
            if (distance <= radius) {
                float position = distance / radius; // Normalized position for the gradient
                SDL_Color color = GradientColor(startColor, endColor, position);
                SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
                SDL_RenderDrawPoint(renderer, x, y);
            }
        }
    }
}

void Window::_CreateNeededInstance()
{
      fps_handler.reset(new FpsManager());
      gsm.reset(new GameStateManager(this));
      fps_handler.get()->setFPS(30);
      gsm.get()->AddState(1, new CanvasTestState(this));
      gsm.get()->AddState(2, new MatrixTestState(this));
      gsm.get()->AddState(3, new SortedState(this));
      gsm.get()->AddState(4, new TileMapTestState(this));
      
      gsm.get()->SetState(1);
      dirty = true;
      const char *font_name_path = "/home/afl/Desktop/doengine/Carlito-Bold.ttf";
      SDL_Log("remember change font path");
      
      TTFText::get()->setFont(font_name_path, 25);

 
}



Window::Window(int w, int h)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    int flags = IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_TIF | IMG_INIT_WEBP;
    int res = IMG_Init(flags);
    SDL_Log("sdl_img_flags= %x, IMG_Init result set =%x", flags, res);
    flags = 0x00;
    
    SDL_GetCurrentDisplayMode(1, &mode);
    window = SDL_CreateWindow("", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w,h,SDL_WINDOW_SHOWN|SDL_WINDOW_BORDERLESS);
    render = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC|SDL_RENDERER_ACCELERATED);
    run = render != NULL;
    window_rect.w = w;
    window_rect.h = h;
    Texture::setRender(render);
    _CreateNeededInstance();
}
Window::Window()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_GetCurrentDisplayMode(0, &mode);
    window = SDL_CreateWindow("", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, mode.w,mode.h,SDL_WINDOW_SHOWN|SDL_WINDOW_BORDERLESS|SDL_WINDOW_FULLSCREEN);
    render = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC|SDL_RENDERER_ACCELERATED);
    run = render != NULL;
    window_rect.w = mode.w;
    window_rect.h = mode.h;
    _CreateNeededInstance();
}

void Window::destroy(){
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    render = nullptr;
    window = nullptr;
}

Window::~Window()
{
  destroy();
}

Window*  Window::setFullScreen()
{
   SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
   return this;
}

Window*  Window::setWindowMode()
{
   SDL_SetWindowFullscreen(window, 0);
   return this;
}
Window* Window::PollEvent()
{
    fps_handler->Start();
    Event::PollEvent(this);
    return this;
}
Window*  Window::Update(){
  gsm.get()->Update(Event::timeElapsed);
  return this;
}
int size = 1;
Window*  Window::Render()
{
 
     SDL_SetRenderDrawColor(render, 0,0,0,255);
     SDL_RenderClear(render);
    
       gsm.get()->Render();
    //    DrawGradientRect(render, 100, 100, 200,48, {0,0,255,255}, {0,0,100,255});
    //  DrawGradientCircle(render, 400, 400,   ::size, {0,0,255,255}, {100,132,12,255});
    
    
    
      SDL_RenderPresent(render);
     fps_handler->Handle();
     return this;
}


Window*  Window::Quit()
{
  ///SDL_Log("running will be toggle to false");

  ///destroy();

  this->run = false;
  return this;
}

const bool Window::IsRunning()const{
   //// SDL_Log("is Running %ld", (long int)run);
   
    return this->run;
}


Window *Window::SetWindowPencilColor(ColorT r, ColorT g, ColorT b, ColorT a){
    SDL_SetRenderDrawColor(render, r,g,b,a);
    return this;
}