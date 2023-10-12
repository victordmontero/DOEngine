#pragma once
#include "abstract/Renderer.h"
#include <gmock/gmock-function-mocker.h>

namespace doengine::mocks
{

class RendererMock : public gfx::Renderer
{
  public:
    MOCK_METHOD(bool, isRenderOk, (), (override));
    MOCK_METHOD(void*, getNativeRenderer, (), (override));
    MOCK_METHOD(void, destroy, (), (override));
};

} // namespace doengine::mocks