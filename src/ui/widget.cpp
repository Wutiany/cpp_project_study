#include "widget.hpp"

namespace ui {
    /* construct 
    * @brief: 用来初始化网络设置部分布局
    * @param parent: 父布局
    * @return: null
    */
    NetSetWidget::NetSetWidget(QWidget* parent) : QWidget(parent)
    {
        // 初始化其中的部件
        QVBoxLayout* layout = new QVBoxLayout(this);

        protocol_type_label_ = new QLabel("(1) 协议类型");
        local_ip_address_label_ = new QLabel("(2) 本地IP地址");
        local_port_label_ = new QLabel("(3) 本地端口号");

        protocol_type_combo_box_ = new QComboBox();
        local_ip_address_line_edit_ = new QLineEdit();
        local_port_edit_ = new QLineEdit();

        // TODO: 后续修改成图片
        connect_button_ = new QPushButton("连接");

        InitNetSetStyle(layout);
        get_local_ip_address();
        port_ = 8080;
    }

    NetSetWidget::~NetSetWidget()
    {
    }

    /* get_local_ip_address
    * @brief: 获取本地ip地址
    * @param: null
    * @return: null
    */
    void NetSetWidget::get_local_ip_address()
    {
        struct ifaddrs* interfaces = nullptr;
        struct ifaddrs* temp_ip_addrs = nullptr;

        if (getifaddrs(&interfaces) != -1)
        {
            std::cout << "get interfaces error" << std::endl;
            return ;
        }

        for (temp_ip_addrs = interfaces; temp_ip_addrs != nullptr; temp_ip_addrs = temp_ip_addrs->ifa_next)
        {
            if ((temp_ip_addrs->ifa_addr != NULL) && (temp_ip_addrs->ifa_flags & IFF_UP) && (temp_ip_addrs->ifa_flags & IFF_RUNNING) && temp_ip_addrs->ifa_addr->sa_family == AF_INET)
            {
                char ip[INET_ADDRSTRLEN] = { 0 };
                if (inet_ntop(AF_INET, &((struct sockaddr_in*)temp_ip_addrs->ifa_addr)->sin_addr, ip, sizeof(ip)))
                {
                    ip_address_.push_back(ip);
                }
            }
        }
        freeifaddrs(interfaces);

        local_ip_address_ = ip_address_[0]; 
    }

    /* InitNetSetStyle
    * @brief: 初始化网络设置窗口的风格(布局大小等)
    * @param layout: 当前布局
    * @return: null
    */
    void NetSetWidget::InitNetSetStyle(QVBoxLayout* layout)
    {
        // 初始化协议类型
        protocol_type_combo_box_->addItem("UDP");
        protocol_type_combo_box_->addItem("TCP Client");
        protocol_type_combo_box_->addItem("TCP Server");

        // 设置 ip edit 的掩码与验证
        local_ip_address_line_edit_->setInputMask("255.255.255.255;_");

        // TODO: validator


        // 设置端口的验证
        local_port_edit_->setInputMask("99999");

        layout->addWidget(protocol_type_label_);
        layout->addWidget(protocol_type_combo_box_);
        layout->addWidget(local_ip_address_label_);
        layout->addWidget(local_ip_address_line_edit_);
        layout->addWidget(local_port_label_);
        layout->addWidget(local_port_edit_);
        layout->addWidget(connect_button_);
    }
}