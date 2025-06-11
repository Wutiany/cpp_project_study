#include<iostream>
#include "hardware.hpp"
#include "ui.hpp"
#include "widget.hpp"
#include "network.hpp"

using namespace ui;

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

#if 0   // 模板
    QWidget* main_windows = new QWidget();

    // 各 widget 组件
    NetSetWidget* net_set_widget = new NetSetWidget();

    // Layout 水平布局，放置两个垂直布局的分块
    QHBoxLayout* main_layout_hb = new QHBoxLayout();
    QVBoxLayout* left_layout_vb = new QVBoxLayout(net_set_widget);
    QVBoxLayout* right_layout_vb = new QVBoxLayout();


    // 设置布局
    left_layout_vb->addWidget(net_set_widget);

    main_layout_hb->addLayout(left_layout_vb);
    main_layout_hb->addLayout(right_layout_vb);

    main_windows->setLayout(main_layout_hb);
    main_windows->show();
#endif
    NetAssistUI* net_assit_ui = new NetAssistUI();

    net_assit_ui->InitLayout();
    net_assit_ui->show();

    return app.exec();
    
}