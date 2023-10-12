#pragma once

#define NETWORK

class UDPPacket
{
  public:
   
   typedef unsigned char packet;

  virtual int ReceivedPacket(const char *url, short port); 
  virtual int SendPacket(const char *buffer, int max_len,const char *url, short port );
  
 protected:
     packet *packet_buffer;
     int     length;
     int     socket_option;
};