#pragma once

#include <SDL2/SDL_ttf.h>
#include <string>

class TTFText
{

    TTFText(){
        color.r = 0xAA;
        color.g = 0xFF;
        color.b = 0xBB;
        color.a = 255;
    }
    static TTFText *singleton;
    
    TTF_Font *font;
    SDL_Color color;

    public:

    static TTFText* get(){
        if(singleton==nullptr)
           singleton = new TTFText();
        return singleton;
    }

    inline void setColor(SDL_Color color){this->color = color;}
    void setFont(const std::string& path, int fntsize= 23);
    SDL_Texture *createText(const std::string& text, SDL_Renderer *render);
    void DrawText(const char *text, int x, int y, SDL_Renderer *render);

};