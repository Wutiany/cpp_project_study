#ifndef __TOOLS_HARDWARED_HPP__
#define __TOOLS_HARDWARED_HPP__

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cerrno>
#include <cstring>

namespace hardware
{
    class HardWare {
        public:
            HardWare();
            virtual ~HardWare();
            virtual void GetHardWareInformation();
            virtual void Monitor();
    };

    class EthernetCard : public HardWare {
        public:
            EthernetCard();
            ~EthernetCard();
            virtual void GetHardWareInformation() override;
        private:
            struct ifaddrs* ifAddrStruct_;
            
    };

    class CPU : public HardWare {
        public:
            CPU();
            CPU(std::string cpu_file);
            ~CPU();
            virtual void GetHardWareInformation() override;
        
        private:
            std::string cpu_file_path_;
    };

} // namespace hardware




#endif
