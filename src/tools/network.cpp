#include "network.hpp"


namespace tools {
bool TcpFileSender::initialize()
{
    // 创建socket
    server_fd_ = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd_ == -1) {
        perror("socket创建失败");
        return false;
    }

    // 设置端口重用
    int opt = 1;
    setsockopt(server_fd_, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // 绑定地址
    sockaddr_in address{};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port_);

    if (bind(server_fd_, (sockaddr*)&address, sizeof(address)) < 0) {
        perror("bind失败");
        return false;
    }

    // 监听
    if (listen(server_fd_, 1) < 0) {
        perror("listen失败");
        return false;
    }

    std::cout << "等待客户端连接..." << std::endl;

    // 接受连接
    client_socket_ = accept(server_fd_, nullptr, nullptr);
    if (client_socket_ < 0) {
        perror("accept失败");
        return false;
    }

    // 设置发送超时
    timeval timeout{.tv_sec = 5, .tv_usec = 0}; // 5秒超时
    setsockopt(client_socket_, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout));

    std::cout << "客户端已连接，准备发送数据..." << std::endl;
    return true;
}

bool TcpFileSender::sendData(const char* data, size_t length)
 {
    size_t total_sent = 0;
    
    while (total_sent < length) {
        ssize_t sent = ::send(client_socket_, data + total_sent, length - total_sent, MSG_NOSIGNAL);
        if (sent <= 0) {
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                std::cerr << "发送超时，网络可能阻塞" << std::endl;
            } else {
                perror("发送错误");
            }
            return false;
        }
        total_sent += sent;
    }
    return true;
}

void TcpFileSender::closeConnection()
{
    if (client_socket_ != -1) {
        close(client_socket_);
        client_socket_ = -1;
    }
    if (server_fd_ != -1) {
        close(server_fd_);
        server_fd_ = -1;
    }
}

TcpFileSender::~TcpFileSender()
{
    closeConnection();
}

}