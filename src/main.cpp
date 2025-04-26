#include<iostream>
#include "hardware.hpp"

int main()
{
    hardware::EthernetCard ethernetCard;
    ethernetCard.GetHardWareInformation();
    return 0;
}