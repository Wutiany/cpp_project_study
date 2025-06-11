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
        QHBoxLayout* main_layout_hb_;      // 主布局
        QVBoxLayout* left_layout_vb_;      // 左侧布局
        QVBoxLayout* right_layout_vb_;     // 右侧布局

        NetSetWidget* net_set_widget_;     // 网络设置布局
    public:

};
}


#endif