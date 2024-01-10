#pragma once

#include "abstract/Font.h"
#include "gmock/gmock.h"
#include <gmock/gmock-function-mocker.h>

namespace doengine::mocks
{

class FontMock : public Font
{
  public:
    MOCK_METHOD(void, init, (), (override));
    MOCK_METHOD(void, destroy, (), (override));
    MOCK_METHOD(void, setColor, (Color), (override));
    MOCK_METHOD(void, setFont, (const std::string&, int), (override));
    MOCK_METHOD(void, drawText, (const std::string&, int x, int y), (override));
};

} // namespace doengine::mocks