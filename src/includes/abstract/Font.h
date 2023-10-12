#pragma once

#include "Color.h"
#include <string>

namespace doengine
{

class Font
{
  public:
    virtual void setColor(Color color) = 0;
    virtual void setFont(const std::string& path, int fntsize = 23) = 0;
};

} // namespace doengine