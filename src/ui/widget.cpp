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

        connect(local_ip_address_line_edit_, &QLineEdit::editingFinished, this, &NetSetWidget::get_input_ip_address);

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
        this->setFixedSize(160, 200);
        this->setContentsMargins(0, 0, 0, 0);

        // 初始化协议类型
        protocol_type_combo_box_->addItem("UDP");
        protocol_type_combo_box_->addItem("TCP Client");
        protocol_type_combo_box_->addItem("TCP Server");

        // 设置 ip edit 的掩码与验证
        local_ip_address_line_edit_->setInputMask("000.000.000.000;_");

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

        // 初始化组件大小
        protocol_type_label_->setFixedSize(130, 20);
        protocol_type_combo_box_->setFixedSize(130, 20);
        local_ip_address_label_->setFixedSize(130, 20);
        local_ip_address_line_edit_->setFixedSize(130, 20);
        local_port_label_->setFixedSize(130, 20);
        local_port_edit_->setFixedSize(130, 20);
        connect_button_->setFixedSize(130, 30);

        layout->setContentsMargins(0, 0, 0, 0);
        layout->setSpacing(0);
    }

    /* get_input_ip_address
    * @brief: 槽函数，获取输入的ip地址
    * @param: null
    * @return: null
    */
    void NetSetWidget::get_input_ip_address()
    {
        QString ip_text = local_ip_address_line_edit_->text();
        

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
        this->setFixedSize(160, 150);
        this->setContentsMargins(0, 0, 0, 0);

        show_recv_time_cb_->setChecked(true);
        show_hex_data_cb_->setChecked(true);

        QHBoxLayout* label_layout = new QHBoxLayout();
        label_layout->addWidget(save_data_, 0, Qt::AlignLeft);
        label_layout->addWidget(clean_display_, 0, Qt::AlignRight);

        layout->addWidget(recv_to_file_cb_);
        layout->addWidget(show_recv_time_cb_);
        layout->addWidget(show_hex_data_cb_);
        layout->addWidget(stop_recv_display_cb_);

        // 设置组件大小
        recv_to_file_cb_->setFixedSize(130, 20);
        show_recv_time_cb_->setFixedSize(130, 20);
        show_hex_data_cb_->setFixedSize(130, 20);
        stop_recv_display_cb_->setFixedSize(130, 20);

        save_data_->setFixedSize(70, 20);
        clean_display_->setFixedSize(70, 20);

        layout->addLayout(label_layout); 

        layout->setContentsMargins(0, 0, 0, 0);
        layout->setSpacing(0);       
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
        this->setFixedSize(160, 200);
        this->setContentsMargins(0, 0, 0, 0);

        QHBoxLayout* sending_interval_layout = new QHBoxLayout();
        QHBoxLayout* label_layout = new QHBoxLayout();

        sending_interval_layout->addWidget(sending_interval_l_);
        sending_interval_layout->addWidget(sending_interval_edit_);
        sending_interval_layout->addWidget(ms_);
        
        label_layout->addWidget(load_file_, 0, Qt::AlignLeft);
        label_layout->addWidget(clear_input_, 0, Qt::AlignRight);

        layout->addWidget(enable_source_file_data_);
        layout->addWidget(auto_send_overhead_bit_);
        layout->addWidget(auto_empty_after_send_final_);
        layout->addWidget(send_for_hex_data_);
        layout->addWidget(loop_sending_);

        // 设置组件大小
        enable_source_file_data_->setFixedSize(130, 20);
        auto_send_overhead_bit_->setFixedSize(130, 20);
        auto_empty_after_send_final_->setFixedSize(130, 20);
        send_for_hex_data_->setFixedSize(130, 20);
        loop_sending_->setFixedSize(130, 20);

        load_file_->setFixedSize(70, 20);
        clear_input_->setFixedSize(70, 20);

        sending_interval_l_->setFixedSize(60, 20);
        sending_interval_edit_->setFixedSize(40, 20);
        ms_->setFixedSize(40, 20);

        layout->addLayout(sending_interval_layout);
        layout->addLayout(label_layout);
        
        sending_interval_layout->setContentsMargins(0, 0, 0, 0);
        sending_interval_layout->setSpacing(0);
        label_layout->setContentsMargins(0, 0, 0, 0);
        label_layout->setSpacing(0);
        layout->setContentsMargins(0, 0, 0, 0);
        layout->setSpacing(0);
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
        this->setContentsMargins(0, 0, 0, 0);

        layout->addWidget(recv_data_eara_);
        recv_data_eara_->setMinimumHeight(300);
        recv_data_eara_->setMinimumWidth(550);
        recv_data_eara_->resize(550, 450);

        layout->setContentsMargins(0, 0, 0, 0);
        layout->setSpacing(0);

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
        this->setFixedHeight(130);
        this->setContentsMargins(0, 0, 0, 0);

        layout->addWidget(send_data_eare_);
        layout->addWidget(send_button_);

        send_data_eare_->setFixedHeight(70);
        send_data_eare_->setMinimumWidth(370);
        send_button_->setFixedSize(80, 70);

        layout->setContentsMargins(0, 0, 0, 0);
        layout->setSpacing(0);
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
        this->setFixedHeight(30);
        this->setContentsMargins(0, 0, 0, 0);

        layout->addWidget(display_info_, 1); // 设置拉伸因子
        layout->addWidget(send_info_);
        layout->addWidget(recv_info_);
        layout->addWidget(reset_count_button_);

        send_info_->setFixedSize(70, 20);
        recv_info_->setFixedSize(70, 20);
        reset_count_button_->setFixedSize(50,20);

        layout->setAlignment(display_info_, Qt::AlignLeft);
        layout->setAlignment(Qt::AlignRight);

        layout->setContentsMargins(0, 0, 0, 0);
        layout->setSpacing(0);
    }

    TargetHostWidget::TargetHostWidget(QWidget* parent) : QWidget(parent)
    {
        QHBoxLayout* main_layout = new QHBoxLayout(this);

        target_host_l_ = new QLabel("目标主机：");
        target_host_le_ = new QLineEdit();
        target_port_l_ = new QLabel("目标端口：");
        target_port_le_ = new QLineEdit();

        TargetHostStyle(main_layout);
    }

    TargetHostWidget::~TargetHostWidget()
    {}

    /* TargetHostStyle
    * @brief: 初始化目标主机信息
    * @param layout: 布局
    * @return: null
    */
    void TargetHostWidget::TargetHostStyle(QHBoxLayout* layout)
    {
        this->setFixedHeight(30);
        this->setContentsMargins(0, 0, 0, 0);

        layout->addWidget(target_host_l_);
        layout->addWidget(target_host_le_);
        layout->addWidget(target_port_l_);
        layout->addWidget(target_port_le_);

        target_host_le_->setInputMask("255.255.255.255;_");

        // TODO: validation 验证输入

        target_port_le_->setInputMask("99999");
        target_port_le_->setText("8080");

        target_host_l_->setFixedSize(65, 20);
        target_host_le_->setFixedSize(130, 20);
        target_port_l_->setFixedSize(65, 20);
        target_port_le_->setFixedSize(90, 20);

        layout->setAlignment(Qt::AlignLeft);

        layout->setContentsMargins(0, 0, 0, 0);
        layout->setSpacing(0);
    }
}