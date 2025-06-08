#ifndef __TOOLS_NETOWORK_HPP__
#define __TOOLS_NETOWORK_HPP__

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>
#include <cerrno>

namespace tools {
class TcpFileSender {
public:
    TcpFileSender(int port) : port_(port) {}

    bool initialize(); 

    // 核心发送接口
    bool sendData(const char* data, size_t length);

    void closeConnection();

    ~TcpFileSender();

private:
    int port_;
    int server_fd_ = -1;
    int client_socket_ = -1;
};

}


#endif