#pragma once

#include "abstract/Font.h"
#include <gmock/gmock-function-mocker.h>

namespace doengine::mocks
{

class FontMock : public Font
{
  public:
    MOCK_METHOD(void, setColor, (Color), (override));
    MOCK_METHOD(void, setFont, (const std::string&, int), (override));
};

} // namespace doengine::mocks