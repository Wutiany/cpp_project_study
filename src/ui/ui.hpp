#ifndef __UI_UI_HPP__
#define __UI_UI_HPP__

#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QLayout>

#include "widget.hpp"

namespace ui {  
class NetAssistUI : public NetSetWidget
{
    public:
        NetAssistUI(QWidget* parent = nullptr);
        virtual ~NetAssistUI();

    private:

    public:
        NetSetWidget* net_set_widget_;     // 网络设置布局
        QVBoxLayout* recv_erea_set_;      // 接收区域设置布局
        QVBoxLayout* send_area_set_;      // 发送区域设置布局
        QVBoxLayout* net_data_recv_;      // 网络数据接收布局

        QPushButton* connect_button_;    // 连接按钮
        QPushButton* send_button_;       // 发送按钮
};
}


#endif