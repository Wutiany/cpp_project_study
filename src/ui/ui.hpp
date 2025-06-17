#ifndef __UI_UI_HPP__
#define __UI_UI_HPP__

#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QLayout>

#include "widget.hpp"

namespace ui {  
class NetAssistUI : public QWidget
{
    public:
        NetAssistUI(QWidget* parent = nullptr);
        virtual ~NetAssistUI();
        void InitLayout();

    private:
        QVBoxLayout* main_layout_vb_;           // 主布局(垂直布局)
        QHBoxLayout* centre_layout_hb_;         // 中间布局
        QVBoxLayout* left_layout_vb_;           // 左侧布局
        QVBoxLayout* right_layout_vb_;          // 右侧布局
        QVBoxLayout* buttom_layout_vb_;         // 底部布局

        NetSetWidget* net_set_widget_;     // 网络设置布局
        RecvEareSetWidget* recv_eare_set_widget_;   // 接收区设置布局
        SendEareSetWidget* send_eare_set_widget_;   // 接收区设置布局
        NetDataRecvWidget* net_data_recv_widget_;   // 网络数据接收区
        NetDataSendWidget* net_data_send_widget_;   // 网络数据发送区
        TargetHostWidget* target_host_widget_;      // 目标主机信息
        DisplayInfoEareWidget* display_info_eare_widget_;   // 数据显示区




    public:
        
};
}


#endif