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
        local_port_edit_->setText("8080");

        layout->addWidget(protocol_type_label_);
        layout->addWidget(protocol_type_combo_box_);
        layout->addWidget(local_ip_address_label_);
        layout->addWidget(local_ip_address_line_edit_);
        layout->addWidget(local_port_label_);
        layout->addWidget(local_port_edit_);
        layout->addWidget(connect_button_);
    }


    RecvEareSetWidget::RecvEareSetWidget(QWidget* parent): QWidget(parent)
    {
        // 设置布局
        QVBoxLayout* main_layout = new QVBoxLayout(this);

        recv_to_file_cb_ = new QCheckBox("接收转向文件");
        show_recv_time_cb_ = new QCheckBox("显示接收时间");
        show_hex_data_cb_ = new QCheckBox("十六进制显示");
        stop_recv_display_cb_ = new QCheckBox("暂停接收显示");

        save_data_ = new QLabel("保存数据");
        clean_display_ = new QLabel("清除显示");


        InitRecvEareStyle(main_layout);
    }

    RecvEareSetWidget::~RecvEareSetWidget()
    {

    }

    /* InitRecvEareStyle
    * @brief: 初始化布局
    * @param layout: 接收区设置布局
    * @return: null
    */
    void RecvEareSetWidget::InitRecvEareStyle(QVBoxLayout* layout)
    {
        show_recv_time_cb_->setChecked(true);
        show_hex_data_cb_->setChecked(true);

        QHBoxLayout* label_layout = new QHBoxLayout();
        label_layout->addWidget(save_data_);
        label_layout->addWidget(clean_display_);

        layout->addWidget(recv_to_file_cb_);
        layout->addWidget(show_recv_time_cb_);
        layout->addWidget(show_hex_data_cb_);
        layout->addWidget(stop_recv_display_cb_);

        layout->addLayout(label_layout);        
    }

    SendEareSetWidget::SendEareSetWidget(QWidget* parent) : QWidget(parent)
    {
        QVBoxLayout* main_layout = new QVBoxLayout(this);

        enable_source_file_data_ = new QCheckBox("启用文件数据源");
        auto_send_overhead_bit_ = new QCheckBox("自动发送附加位");
        auto_empty_after_send_final_ = new QCheckBox("发送完自动清空");
        send_for_hex_data_ = new QCheckBox("按十六进制发送");
        loop_sending_ = new QCheckBox("数据流循环发送");

        sending_interval_l_ = new QLabel("发送间隔");
        sending_interval_edit_ = new QLineEdit("1000");
        ms_ = new QLabel("毫秒");


        load_file_ = new QLabel("文件载入");
        clear_input_ = new QLabel("清除输入");

        InitSendEareStyle(main_layout);
    }

    SendEareSetWidget::~SendEareSetWidget()
    {

    }

    /* InitSendEareStyle
    * @brief: 初始化发送去设置布局
    * @param layout: 主布局
    * @return: null
    */
    void SendEareSetWidget::InitSendEareStyle(QVBoxLayout* layout)
    {
        QHBoxLayout* sending_interval_layout = new QHBoxLayout();
        QHBoxLayout* label_layout = new QHBoxLayout();

        sending_interval_layout->addWidget(sending_interval_l_);
        sending_interval_layout->addWidget(sending_interval_edit_);
        sending_interval_layout->addWidget(ms_);

        label_layout->addWidget(load_file_);
        label_layout->addWidget(clear_input_);

        layout->addLayout(sending_interval_layout);
        layout->addLayout(label_layout);
    }

    NetDataRecvWidget::NetDataRecvWidget(QWidget* parent) : QWidget(parent)
    {
        QVBoxLayout* main_layout = new QVBoxLayout(this);

        recv_data_eara_ = new QTextEdit();

        NetDataRecvStyle(main_layout);
    }

    NetDataRecvWidget::~NetDataRecvWidget()
    {

    }

    /* NetDataRecvStyle
    * @brief: 初始化网络数据接收去布局
    * @param layout: 网络接收区布局
    * @return: null
    */
    void NetDataRecvWidget::NetDataRecvStyle(QVBoxLayout* layout)
    {
        layout->addWidget(recv_data_eara_);
    }

    NetDataSendWidget::NetDataSendWidget(QWidget* parent) : QWidget(parent)
    {
        QHBoxLayout* main_layout = new QHBoxLayout(this);

        send_data_eare_ = new QTextEdit();
        send_button_ = new QPushButton("发送");

        NetDataSendStyle(main_layout);
    }

    NetDataSendWidget::~NetDataSendWidget()
    {

    }

    /* NetDataSendStyle
    * @brief: 网络数据发送区初始化布局
    * @param layout: 布局
    * @return: null
    */
    void NetDataSendWidget::NetDataSendStyle(QHBoxLayout* layout)
    {
        layout->addWidget(send_data_eare_);
        layout->addWidget(send_button_);
    }

    DisplayInfoEareWidget::DisplayInfoEareWidget(QWidget* parent) : 
        QWidget(parent), send_str_("发送："), recv_str_("接收：")
    {
        QHBoxLayout* main_layout = new QHBoxLayout(this);

        display_info_ = new QLabel("就绪！");
        send_info_ = new QLabel("发送：0");
        recv_info_ = new QLabel("接收：0");
        reset_count_button_ = new QPushButton("复位计数");

        recv_count_ = 0;
        send_count_ = 0;

        DisplayInfoEareStyle(main_layout);
    }

    DisplayInfoEareWidget::~DisplayInfoEareWidget()
    {

    }

    /* DisplayInfoEareStyle
    * @brief:   信息显示区布局
    * @param layout: 布局
    * @return: null
    */
    void DisplayInfoEareWidget::DisplayInfoEareStyle(QHBoxLayout* layout)
    {
        layout->addWidget(display_info_);
        layout->addWidget(send_info_);
        layout->addWidget(recv_info_);
        layout->addWidget(reset_count_button_);
    }
}