#ifndef __UI_UI_HPP__
#define __UI_UI_HPP__

#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QLayout>

namespace ui {  
    class NetAssistUI : public QMainWindow
    {
        Q_OBJECT
        public:
            NetAssistUI(QWidget* parent = nullptr);
            virtual ~NetAssistUI();
            void getLocalIP();

        private:

        public:
            QVBoxLayout* NetSet_;           // 网络设置布局
            QVBoxLayout* RecvAreaSet_;      // 接收区域设置布局
            QVBoxLayout* SendAreaSet_;      // 发送区域设置布局
            QVBoxLayout* NetDataRecv_;      // 网络数据接收布局

            QPushButton* ConnectButton_;    // 连接按钮
            QPushButton* SendButton_;       // 发送按钮
    };
}


#endif