#ifndef __SIGNALS_SIGNALS_HPP__
#define __SIGNALS_SIGNALS_HPP__

#include <iostream>
#include <vector>

#include "signal_common.hpp"


namespace signal {

/* GenerateBitStream
* @brief: 生成用来产生相位的比特流
* @param length[in]: 生成的长度
* @param bits[out]: 用来存储生成的bit流
* @return: 是否生成成功
*/
bool GenerateBitStream(int length, std::vector<int> &bits);

/* Map2Bipolar
* @brief: 比特流映射生成两极的相位信号
* @param bits[in]: 需要映射的比特流
* @param symbols[out]: 生成的符号
* @return: 是否映射成功 
*/
bool Map2Bipolar(std::vector<int> &bits, std::vector<double>& symbols);

/* GenerateCarrier
* @brief: 生成载波信号
* @param interface[in]: 用来生成数据的参数
* @param carrier[out]: 生成的载波信号
* @return: 是否生成成功
*/
bool GenerateCarrier(struct SignalInterface& interface, std::vector<double>& carrier);

/* Modulate
* @brief: 调制类型
* @param interface[in]: 用来生成数据的参数
* @param symbols[in]: 载波信号数据
* @param modulate_signal[out]: 生成的调制信号
*/
bool Modulate(struct SignalInterface& interface, std::vector<double>& symbols, std::vector<double>& modulate_signal);
}
#endif