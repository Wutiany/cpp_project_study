#ifndef __UI_WIDGET_HPP__
#define __UI_WIDGET_HPP__

#include <QWidget>
#include <QLayout>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>

namespace ui {
    class NetSetWidget : public QWidget 
    {
        Q_OBJECT
        public:
            NetSetWidget(QWidget* parent = nullptr);
            virtual ~NetSetWidget();

        private:
            QLabel* ProtocolTypeLabel_;
            QLabel* LocalIpAddressLabel_;
            QLabel* LocalPortLabel_;

            QComboBox* ProtocolTypeCBox_;
            QLineEdit* LocalIpAddressLEdit_;
            QLineEdit* LocalPortLabel_;

            QPushButton* ConnectButton_;



    };
}


#endif