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
    // TODO: 目标主机

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

    right_layout_vb_->addWidget(net_data_recv_widget_);
    right_layout_vb_->addWidget(net_data_send_widget_);

    centre_layout_hb_->addLayout(left_layout_vb_);
    centre_layout_hb_->addLayout(right_layout_vb_);

    buttom_layout_vb_->addWidget(display_info_eare_widget_);

    main_layout_vb_->addLayout(centre_layout_hb_);
    main_layout_vb_->addLayout(buttom_layout_vb_);

    this->setLayout(main_layout_vb_);
}

}