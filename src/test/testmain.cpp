#include "FPSManager.h"
#include "mocks/AbstractWindowMock.h"
#include "mocks/CameraMock.h"
#include "mocks/EventHandlerMock.h"
#include "mocks/FontMock.h"
#include "mocks/GameObjectMock.h"
#include "mocks/GameStateManagerMock.h"
#include "mocks/MusicHandlerMock.h"
#include "mocks/ParticleMock.h"
#include "mocks/RendererMock.h"
#include <gmock/gmock-actions.h>
#include <gmock/gmock-nice-strict.h>
#include <gmock/gmock-spec-builders.h>
#include <gtest/gtest.h>

using namespace doengine::mocks;
using namespace testing;

TEST(mocks_test, get_music_from_mars_test)
{
    NiceMock<CameraMock> cameraMock;
    NiceMock<MusicHandlerMock> musicHandlerMock;
    NiceMock<ParticleMock> particleMock;
    NiceMock<RendererMock> rendererMock;
    NiceMock<FontMock> fontMock;
    NiceMock<KeyDownEventMock> keyDownEventMock;
    NiceMock<KeyUpEventMock> keyUpEventMock;
    NiceMock<AbstractWindowMock> abstractWindowMock;
    NiceMock<GameObjectMock> gameObjectMock;

    ON_CALL(musicHandlerMock, getPlayMusicName()).WillByDefault(Return("Mars"));
    ASSERT_EQ(1, 1);
    EXPECT_EQ(musicHandlerMock.getPlayMusicName(), "Mars");
}
