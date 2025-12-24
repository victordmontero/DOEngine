#include "Application.h"
#include "gmock/gmock.h"
#include "mocks/SDLMock.h"
#include <gtest/gtest.h>


namespace doengine
{

    namespace ut
    {
        class utApplication : public testing::Test
        {
        public:
            utApplication() : xsdlMock()
            {
            }

            Application _sut;
            void SetUp() override
            {
                testing::Test::SetUp();
                SetSDLMock(&xsdlMock);
               /// ON_CALL(xsdlMock, SDL_GetTicks()).WillByDefault(Return(0));
            }

            testing::NiceMock<mocks::SDLMock> xsdlMock;
        };

    }

}