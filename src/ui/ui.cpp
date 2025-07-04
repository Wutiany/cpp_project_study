#include "ui.hpp"

namespace ui {
NetAssistUI::NetAssistUI(QWidget* parent) : QWidget(parent)
{
    // 初始化个分区组件
    net_set_widget_ = new NetSetWidget();
    recv_eare_set_widget_ = new RecvEareSetWidget();
    send_eare_set_widget_ = new SendEareSetWidget();
    net_data_recv_widget_ = new NetDataRecvWidget();
    net_data_send_widget_ = new NetDataSendWidget();
    target_host_widget_ = new TargetHostWidget();
    display_info_eare_widget_ = new DisplayInfoEareWidget();
    


    main_layout_vb_ = new QVBoxLayout();
    centre_layout_hb_ = new QHBoxLayout();
    left_layout_vb_ = new QVBoxLayout();
    right_layout_vb_ = new QVBoxLayout();
    buttom_layout_vb_ = new QVBoxLayout();
}

NetAssistUI::~NetAssistUI()
{
    
}

void NetAssistUI::InitLayout()
{
    left_layout_vb_->addWidget(net_set_widget_);
    left_layout_vb_->addWidget(recv_eare_set_widget_);
    left_layout_vb_->addWidget(send_eare_set_widget_);

    right_layout_vb_->addWidget(net_data_recv_widget_, 1);
    right_layout_vb_->addWidget(target_host_widget_);
    right_layout_vb_->addWidget(net_data_send_widget_);

    // 右侧布局调整排列，网络数据接收区在上面，其余的在下面
    right_layout_vb_->setAlignment(net_data_recv_widget_, Qt::AlignTop);
    right_layout_vb_->setAlignment(Qt::AlignBottom);

    centre_layout_hb_->addLayout(left_layout_vb_);
    centre_layout_hb_->addLayout(right_layout_vb_);

    buttom_layout_vb_->addWidget(display_info_eare_widget_);

    main_layout_vb_->addLayout(centre_layout_hb_);
    main_layout_vb_->addLayout(buttom_layout_vb_);

    target_host_widget_->hide();

    this->setLayout(main_layout_vb_);

    
    left_layout_vb_->setContentsMargins(10, 10, 0, 10);
    left_layout_vb_->setSpacing(2);
    right_layout_vb_->setContentsMargins(0, 10, 10, 10);
    right_layout_vb_->setSpacing(2);
    centre_layout_hb_->setContentsMargins(0, 0, 0, 0);
    centre_layout_hb_->setSpacing(2);
    buttom_layout_vb_->setContentsMargins(10, 0, 10, 10);
    buttom_layout_vb_->setSpacing(2);
    main_layout_vb_->setContentsMargins(0, 0, 0, 0);
    main_layout_vb_->setSpacing(2);

}

}