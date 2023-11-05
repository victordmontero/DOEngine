#pragma once

#include "UDPPacket.h"
#include "gmock/gmock.h"

namespace doengine::mocks
{

using doengine::net::UDPPacket;

class UDPPacketMock : public UDPPacket
{
    MOCK_METHOD(int, ReceivedPacket, (const char*, short), (override));
    MOCK_METHOD(int, SendPacket, (const char*, int, const char*, short),
                (override));
};
} // namespace doengine::mocks