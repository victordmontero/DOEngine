#pragma once
#include "GeometricRender.h"


enum class TypeOfApp{
    Platform,
    SideScrolled,
    RPG,
    ActionRPG,
    MultimediaApp,
    CustomApp
};


struct EngineInfo{

    TypeOfApp type;
    Rect      window_rect;
    bool      debug_mode;

};
