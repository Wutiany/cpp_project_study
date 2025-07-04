#ifndef __SIGNALS_SIGNAL_COMMON_HPP__
#define __SIGNALS_SIGNAL_COMMON_HPP__

#include <iostream>
#include <stdio.h>

namespace signal {
struct alignas(1) SignalInterface 
{
    double duration;        // 信号时常
    double fc;              // 载波频率
    int sample_rate;        // 采样率
    uint8_t signal_type;    // 调制信号类型: 0 PSK，1 QPSK，2 FSK
}SignalInterface;


}
#endif