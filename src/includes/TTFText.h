#pragma once

#include "DOEngine.h"
#include "Geometric.h"
#include "abstract/Font.h"
#include <string>

using doengine::Font;

class TTFText : public Font
{

    TTFText() : font(NULL)
    {
        color.r = 0xAA;
        color.g = 0xFF;
        color.b = 0xBB;
        color.a = 255;
    }
    static TTFText* singleton;

    TTF_Font* font;
    SDL_Color color;

  public:
    static TTFText* get()
    {
        if (singleton == nullptr)
            singleton = new TTFText();
        return singleton;
    }

    void setColor(doengine::Color color) override
    {
        this->color = static_cast<SDL_Color>(color.rgba);
    }

    void init() override
    {
    }
    void destroy() override
    {
    }

    void setFont(const std::string& path, int fntsize = 23) override;
    SDL_Texture* createText(const std::string& text, SDL_Renderer* render);
    void DrawText(const char* text, int x, int y, SDL_Renderer* render);

    void drawText(const std::string&, int, int) override
    {
    }
};