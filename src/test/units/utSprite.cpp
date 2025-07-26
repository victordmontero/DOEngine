
#include "Geometric.h"
#include "Sprite.h"
#include "Texture.h"
#include "mocks/NativeStructsMock.h"
#include "mocks/SDLMock.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <vector>

namespace doengine
{
namespace ut
{

using testing::_;
using testing::Return;

class utSprite : public testing::Test
{
  public:
    utSprite()
        : _tex("assets/myspritesheet.bmp", &_textureMock), xsdlMock(),
          _textureMock(), _sut(nullptr)

    {
    }

    void SetUp() override
    {
        frames.emplace_back(Rect{0, 0, 4, 4});
        _sut = new Sprite(&_tex, frames, Point{1, 0});
    }

    void TearDown() override
    {
        delete _sut;
    }

    std::vector<Rect> frames;
    Texture _tex;
    testing::NiceMock<mocks::SDLMock> xsdlMock;
    testing::NiceMock<mocks::NativeTextureMock> _textureMock;

    Sprite* _sut;
};

TEST_F(utSprite, DrawSeveralSprites)
{
    EXPECT_CALL(_textureMock, Draw(_, _, _, _));
  //  _sut->Draw(Point{5, 5});
}

} // namespace ut
} // namespace doengine
