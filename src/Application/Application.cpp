
#include <iostream>
#include <sstream>
#include <string_view>
#include <vector>

#include "Application.h"
#include "Event.h"

namespace doengine
{
Application* Application::applicationObject = nullptr;

Application::Application()
{
    windowManager = WindowManager::getWindowManager();
    gsm = new GameStateManager();
    fps_handler = new FpsManager();
    fps_handler->setFPS(60);
}

void Application::destroy()
{
    // render->destroy();
    // SDL_DestroyWindow(window);
    // render = nullptr;
    // window = nullptr;
}

Application::~Application()
{
    destroy();
}

void Application::_internalResize()
{
    windowManager->setSize(Rect{window_rect.w, window_rect.h});
}

void Application::setFullScreen()
{
    windowManager->setFullScreen();
}

void Application::setWindowMode()
{
    windowManager->setFullScreen();
}
void Application::PollEvent()
{
    fps_handler->Start();
    Event::PollEvent();
}

void Application::Update()
{
    gsm->Update(Event::timeElapsed);
}

void Application::Render()
{
    gsm->Render();
    windowManager->updateScreen();
    fps_handler->Handle();
}

void Application::Quit()
{
    run = false;
}
WindowManager* Application::getWindow()
{
    return windowManager;
}
Renderer* Application::getRender() const
{
    return windowManager->getRenderer();
}

const bool Application::IsRunning() const
{
    return run;
}

void Application::SetWindowPencilColor(const Color& color)
{
    windowManager->setPincelColor(color);
}
void Application::clearScreen(const Color& color)
{
    windowManager->clearScreen(color);
}

void Application::createWindow(const Rect& rect)
{
    run = windowManager->createWindow(rect);
}

} // namespace doengine