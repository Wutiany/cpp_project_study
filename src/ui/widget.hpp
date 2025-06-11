#ifndef __UI_WIDGET_HPP__
#define __UI_WIDGET_HPP__

#include <QWidget>
#include <QLayout>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QCheckBox>

#include <netinet/in.h>
#include <arpa/inet.h>
#include <ifaddrs.h>
#include <net/if.h>

#include <iostream>
#include <vector>
#include <string>

namespace ui {
class NetSetWidget : public QWidget 
{
    public:
        NetSetWidget(QWidget* parent = nullptr);
        virtual ~NetSetWidget();
        void get_local_ip_address();
        void InitNetSetStyle(QVBoxLayout* layout);

    private:
        QLabel* protocol_type_label_;
        QLabel* local_ip_address_label_;
        QLabel* local_port_label_;

        QComboBox* protocol_type_combo_box_;
        QLineEdit* local_ip_address_line_edit_;
        QLineEdit* local_port_edit_;

        QPushButton* connect_button_;

        std::vector<std::string> ip_address_;
        std::string local_ip_address_;
        uint32_t port_;
};

class RecvEareSetWidget : public QWidget 
{
    public:
        RecvEareWidget(QWidget* parent = nullptr);
        virtual ~RecvEareWidget();
        void InitRecvEareStyle(QVBoxLayout* layout);

    private:
        QCheckBox* recv_to_file_cb_;
        QCheckBox* show_recv_time_cb_;
        QCheckBox* show_hex_data_cb_;
        QCheckBox* stop_recv_display_cb_;

        QLabel* save_data_;
        QLabel* clean_display_;
};
}


#endif