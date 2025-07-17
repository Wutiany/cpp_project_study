#ifndef __UI_UI_COMMON_HPP__
#define __UI_UI_COMMON_HPP__

#include <stdio.h>

namespace ui {
typedef enum class ProtocolType 
{
    UDP = 0,
    TCP_CLIENT = 1,
    TCP_SERVER = 2,
    INVALIED = 0xFF,
}ProtocolType;


}



#endif
