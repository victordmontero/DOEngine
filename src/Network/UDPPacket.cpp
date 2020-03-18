#ifdef __WIN32__
#include <winsock2.h>
#include <windows.h>
struct winsocket_initializer{
    winsocket_initializer(){
        WSAData data;
        WSAStartup(MAKEWORD(2,2), &data);
       //// MessageBox(NULL,"INIT CORRE", "FIIFFI", MB_OK);
    }
};
static winsocket_initializer init__in;
#endif