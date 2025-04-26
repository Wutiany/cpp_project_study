#include "hardware.hpp"

namespace hardware {
HardWare::HardWare(){}
HardWare::~HardWare(){}

/* GetHardWareInformation
* @brief: 获取硬件信息
* @param: null
* @return: null
*/
void HardWare::GetHardWareInformation() {}

/* Monitor
* @brief:  监控硬件实时信息
* @param: null
* @return: null
*/
void HardWare::Monitor() {}

CPU::CPU() : cpu_file_path_("/proc/cpuinfo"){}

CPU::CPU(std::string cpu_file) {
    cpu_file_path_ = cpu_file;
}

CPU::~CPU() 
{

}

/* GetHardWareInformation
* @brief: 获取CPU信息
* @param: null
* @return: null
*/
void CPU::GetHardWareInformation() 
{
    FILE *fp = fopen(cpu_file_path_.c_str(), "r");
    if (fp == NULL)
    {
        std::cout << "ERROR: " << cpu_file_path_ << " open error" << std::endl;
        return;
    }

    char tmp[1000];

    std::cout << "============= cpu information ===========" << std::endl;
    while (!feof(fp))
    {
        memset(tmp, sizeof(tmp), 0);
        fgets(tmp, sizeof(tmp) - 1, fp);
        printf("%s", tmp);
    }

    fclose(fp);
    fp = NULL;
}

EthernetCard::EthernetCard() : ifAddrStruct_(NULL) {}

EthernetCard::~EthernetCard() {}

/* GetHardWareInformation
* @brief: 获取网卡信息
* @param: null
* @return: null
*/
void EthernetCard::GetHardWareInformation()
{
    void *tmpAddrPtr = nullptr;

    getifaddrs(&ifAddrStruct_);

    while (ifAddrStruct_ != NULL)
    {   
        // ipv4
        if (ifAddrStruct_->ifa_addr->sa_family == AF_INET)
        {
            tmpAddrPtr = &((struct sockaddr_in*)ifAddrStruct_->ifa_addr)->sin_addr;
            char addressBuffer[INET_ADDRSTRLEN] = {0};
            inet_ntop(AF_INET, tmpAddrPtr, addressBuffer, INET_ADDRSTRLEN);
            std::cout << ifAddrStruct_->ifa_name << "IP Address " << addressBuffer << std::endl;   
        }
        else if (ifAddrStruct_->ifa_addr->sa_family == AF_INET6)
        {
            tmpAddrPtr = &((struct sockaddr_in*)ifAddrStruct_->ifa_addr)->sin_addr;
            char addressBuffer[INET6_ADDRSTRLEN] = {0};
            inet_ntop(AF_INET6, tmpAddrPtr, addressBuffer, INET6_ADDRSTRLEN);
            std::cout << ifAddrStruct_->ifa_name << "IP Address " << addressBuffer << std::endl;
        }
    }
}

}