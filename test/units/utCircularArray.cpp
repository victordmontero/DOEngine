#include "CircularArray.h"

#include "gmock/gmock.h"
#include <gtest/gtest.h>

namespace doengine
{
namespace ut
{

using testing::_;
using testing::Return;


class utCircularArray : public testing::Test
{
  public:
    utCircularArray() 
    {
    }
    void SetUp() override
    {
        testing::Test::SetUp();
    }
};

TEST(utCircularArray, Testing_outbound_elements_not_fails)
{
    CircularArray<int, 3> _testObject;
    
    for(int i=0;i<4;i++)
    {
        _testObject[i]=20 * i;
    }
}


}

}