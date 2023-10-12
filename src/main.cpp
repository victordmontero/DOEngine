
#include "Window.h"
// #include "Texture.h"
// #include "Grids.h"
#include <Vector.h>
#include <iostream>
#include <map>
#include <memory>
#include <string>

int main(int argc, char* argv[])
{
    std::shared_ptr<Window> window(new Window(1200, 900));
    while (window->IsRunning() == true)
    {
        window->PollEvent()->Update()->Render();
    }
    return 0;
}
