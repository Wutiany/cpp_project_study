#include<iostream>
#include "hardware.hpp"
#include "ui.hpp"
#include "network.hpp"

int main(int argc, char** argv)
{
    tools::TcpFileSender sender(8080);
    
    if (!sender.initialize())
    {
        std::cerr << "初始化失败" << std::endl;
        return 1;
    }
    sleep(60);
    char buffer[1024] = {0};
    for (int i = 0; i < 10; i++)
    {
        sender.sendData(buffer, sizeof(buffer));
    }

    // QApplication app(argc, argv);
    // return app.exec();
    
}