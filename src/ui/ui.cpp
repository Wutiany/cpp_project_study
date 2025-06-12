#include "ui.hpp"

namespace ui {
NetAssistUI::NetAssistUI(QWidget* parent) : QWidget(parent)
{
    // 初始化个分区组件
    net_set_widget_ = new NetSetWidget();
    recv_eare_set_widget_ = new RecvEareSetWidget();
    send_eare_set_widget_ = new SendEareSetWidget();

    main_layout_hb_ = new QHBoxLayout();
    left_layout_vb_ = new QVBoxLayout(net_set_widget_);
    right_layout_vb_ = new QVBoxLayout();
}

NetAssistUI::~NetAssistUI()
{
    
}

void NetAssistUI::InitLayout()
{
    left_layout_vb_->addWidget(net_set_widget_);
    left_layout_vb_->addWidget(recv_eare_set_widget_);
    left_layout_vb_->addWidget(send_eare_set_widget_);

    main_layout_hb_->addLayout(left_layout_vb_);
    main_layout_hb_->addLayout(right_layout_vb_);

    this->setLayout(main_layout_hb_);
}

}