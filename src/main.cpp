#include<iostream>
#include "tools/hardware.hpp"

int main()
{
    std::cout << "this is main cpp file" << std::endl;
    hardware::CPU cpu_information;
    cpu_information.GetHardWareInformation();

    return 0;
}