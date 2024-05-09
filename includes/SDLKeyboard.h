#pragma once

#include "abstract/devices/Keyboard.h"

namespace doengine::devices
{
class SDLKeyboard : public Keyboard
{
  public:
    SDLKeyboard();

    const unsigned char* getKeysBitset() const override;
};
} // namespace doengine::devices
