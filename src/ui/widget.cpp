#include "widget.hpp"

namespace ui {
    /* construct 
    * @brief: 用来初始化网络设置部分布局
    * @param parent: 子布局
    * @return: null
    */
    NetSetWidget::NetSetWidget(QWidget* parent) : QWidget(parent)
    {
        // 初始化其中的部件
        QVBoxLayout* layout = new QVBoxLayout(this);


    }
}