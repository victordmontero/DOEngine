#pragma once

namespace doengine
{

typedef unsigned char ColorT;

union Color {
    struct
    {
        ColorT r;
        ColorT g;
        ColorT b;
        ColorT a;
    };
    unsigned int rgba;
};

} // namespace doengine