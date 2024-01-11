
#include <sstream>
#include <vector>

#include <iostream>
#include <string_view>

extern "C"
{
#include <SDL.h>
#include <SDLRenderer.h>
#include <SDL_error.h>
}

#include "TTFText.h"

#include "CanvasTestState.h"
#include "MatrixTestState.h"
#include "SortedState.h"

// Create a gradient color between two colors at a specific position
SDL_Color GradientColor(SDL_Color startColor, SDL_Color endColor,
                        float position)
{
    SDL_Color result;
    result.r = startColor.r + (endColor.r - startColor.r) * position;
    result.g = startColor.g + (endColor.g - startColor.g) * position;
    result.b = startColor.b + (endColor.b - startColor.b) * position;
    result.a = startColor.a + (endColor.a - startColor.a) * position;
    return result;
}

// Draw a horizontal line on the renderer with a gradient
void DrawGradientHorizontalLine(SDL_Renderer* renderer, int x, int y, int width,
                                SDL_Color startColor, SDL_Color endColor)
{
    for (int i = 0; i < width; i++)
    {
        float position =
            (float)i /
            (float)(width - 1); // Normalized position for the gradient
        SDL_Color color = GradientColor(startColor, endColor, position);
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_RenderDrawPoint(renderer, x + i, y);
    }
}

// Draw a gradient-filled rectangle on the renderer
void DrawGradientRect(SDL_Renderer* renderer, int x, int y, int width,
                      int height, SDL_Color startColor, SDL_Color endColor)
{
    for (int i = 0; i < height; i++)
    {
        float position =
            (float)i /
            (float)(height - 1); // Normalized position for the gradient
        SDL_Color color = GradientColor(startColor, endColor, position);
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_RenderDrawLine(renderer, x, y + i, x + width - 1, y + i);
    }
}

// Draw a gradient-filled circle on the renderer
void DrawGradientCircle(SDL_Renderer* renderer, int centerX, int centerY,
                        int radius, SDL_Color startColor, SDL_Color endColor)
{
    for (int y = centerY - radius; y <= centerY + radius; y++)
    {
        for (int x = centerX - radius; x <= centerX + radius; x++)
        {
            float distance = sqrtf((x - centerX) * (x - centerX) +
                                   (y - centerY) * (y - centerY));
            if (distance <= radius)
            {
                float position =
                    distance / radius; // Normalized position for the gradient
                SDL_Color color = GradientColor(startColor, endColor, position);
                SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b,
                                       color.a);
                SDL_RenderDrawPoint(renderer, x, y);
            }
        }
    }
}

void Window::_CreateNeededInstance()
{
    const auto window = static_cast<doengine::AbstractWindow*>(this);

    fps_handler.reset(new FpsManager());
    gsm.reset(new GameStateManager(this));
    fps_handler.get()->setFPS(30);

    gsm.get()->AddState(1, new CanvasTestState(window));
    gsm.get()->AddState(2, new MatrixTestState(window));
    gsm.get()->AddState(3, new SortedState(window));

    gsm.get()->SetState(3);
    dirty = true;

    TTFText::get()->setFont(
        "/home/phenom/Projects/DOEngine/assets/fonts/NirmalaB.ttf", 25);
}

Window::Window(int w, int h)
{
    // const int rc =
    //     SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER |
    //     SDL_INIT_JOYSTICK);

    const int rc = SDL_Init(SDL_INIT_EVERYTHING);

    if (rc != 0)
    {
        SDL_Log("SDL_Init Error: %s", SDL_GetError());
        return;
    }

    TTF_Init();
    int flags = IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_TIF | IMG_INIT_WEBP;
    int res = IMG_Init(flags);
    SDL_Log("sdl_img_flags= %x, IMG_Init result set =%x", flags, res);
    flags = 0x00;

    SDL_GetCurrentDisplayMode(1, &mode);
    window = SDL_CreateWindow("", SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
    render = new SDLRenderer(SDL_CreateRenderer(
        window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED));
    run = render->isRenderOk();
    window_rect.w = w;
    window_rect.h = h;
    Texture::setRender(render);
    _CreateNeededInstance();

    auto* joyStick = SDL_JoystickOpen(1);
    auto* controller = SDL_GameControllerOpen(1);

    if (joyStick != nullptr)
    {
        SDL_Log("joystick error = [%s]", SDL_GetError());
    }
    else
    {
        SDL_Log("joystick opened");
    }

    joyStick = SDL_JoystickOpen(0);
    controller = SDL_GameControllerOpen(0);

    if (joyStick != nullptr)
    {
        SDL_Log("joystick error = [%s]", SDL_GetError());
    }
    else
    {
        SDL_Log("joystick opened");
    }
}

Window::Window()
{
    const int rc = SDL_Init(SDL_INIT_EVERYTHING);

    if (rc != 0)
    {
        SDL_Log("SDL_Init Error: %s", SDL_GetError());
        return;
    }

    SDL_GetCurrentDisplayMode(0, &mode);
    window = SDL_CreateWindow(
        "", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, mode.w, mode.h,
        SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS | SDL_WINDOW_FULLSCREEN);
    render = new SDLRenderer(SDL_CreateRenderer(
        window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED));
    run = render->isRenderOk();
    window_rect.w = mode.w;
    window_rect.h = mode.h;
    _CreateNeededInstance();
}

void Window::destroy()
{
    render->destroy();
    SDL_DestroyWindow(window);
    render = nullptr;
    window = nullptr;
}

Window::~Window()
{
    destroy();
}

doengine::AbstractWindow* Window::setFullScreen()
{
    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
    return this;
}

doengine::AbstractWindow* Window::setWindowMode()
{
    SDL_SetWindowFullscreen(window, 0);
    return this;
}
doengine::AbstractWindow* Window::PollEvent()
{
    fps_handler->Start();
    Event::PollEvent(this);
    return this;
}

doengine::AbstractWindow* Window::Update()
{
    gsm.get()->Update(Event::timeElapsed);
    return this;
}

int size = 1;
doengine::AbstractWindow* Window::Render()
{
    // SDL_Renderer* renderer =
    //     static_cast<SDL_Renderer*>(render->getNativeRenderer());
    render->setDrawColor({0, 0, 0, 255});
    render->clear();

    gsm.get()->Render();
    //    DrawGradientRect(render, 100, 100, 200,48, {0,0,255,255},
    //    {0,0,100,255});
    //  DrawGradientCircle(render, 400, 400,   ::size, {0,0,255,255},
    //  {100,132,12,255});

    render->present();
    fps_handler->Handle();
    return this;
}

doengine::AbstractWindow* Window::Quit()
{
    /// SDL_Log("running will be toggle to false");

    /// destroy();

    this->run = false;
    return this;
}

const bool Window::IsRunning() const
{
    //// SDL_Log("is Running %ld", (long int)run);

    return this->run;
}

doengine::AbstractWindow* Window::SetWindowPencilColor(doengine::Color color)
{
    SDL_SetRenderDrawColor(
        static_cast<SDL_Renderer*>(render->getNativeRenderer()), color.r,
        color.g, color.b, color.a);
    return this;
}