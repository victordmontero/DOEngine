#ifndef _LOGGER_H_DEFINED
#define _LOGGER_H_DEFINED

#include <stdio.h>

namespace doengine
{

enum class logger_type{
   Warning,
   Error
};


void log(const logger_type& type, char *msg, ...);



}


#endif