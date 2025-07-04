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
#include <QTextEdit>

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

    private slots:
        void get_input_ip_address();
};

class RecvEareSetWidget : public QWidget 
{
    public:
        RecvEareSetWidget(QWidget* parent = nullptr);
        virtual ~RecvEareSetWidget();
        void InitRecvEareStyle(QVBoxLayout* layout);

    private:
        QCheckBox* recv_to_file_cb_;
        QCheckBox* show_recv_time_cb_;
        QCheckBox* show_hex_data_cb_;
        QCheckBox* stop_recv_display_cb_;

        QLabel* save_data_;
        QLabel* clean_display_;
};

class SendEareSetWidget : public QWidget
{
    public:
        SendEareSetWidget(QWidget* parent = nullptr);
        virtual ~SendEareSetWidget();
        void InitSendEareStyle(QVBoxLayout* layout);
        

    private:
        QCheckBox* enable_source_file_data_;
        QCheckBox* auto_send_overhead_bit_;         // 自动发送附加位
        QCheckBox* auto_empty_after_send_final_;
        QCheckBox* send_for_hex_data_;
        QCheckBox* loop_sending_;

        QLabel* sending_interval_l_;
        QLineEdit* sending_interval_edit_;
        QLabel* ms_;

        QLabel* load_file_;
        QLabel* clear_input_;
};

class NetDataRecvWidget : public QWidget
{
    public:
        NetDataRecvWidget(QWidget* parent = nullptr);
        virtual ~NetDataRecvWidget();
        void NetDataRecvStyle(QVBoxLayout* layout);

    private:
        QTextEdit* recv_data_eara_;
};

class NetDataSendWidget : public QWidget
{
    public:
        NetDataSendWidget(QWidget* parent = nullptr);
        virtual ~NetDataSendWidget();
        void NetDataSendStyle(QHBoxLayout* layout);

    private:
        QTextEdit* send_data_eare_;
        QPushButton* send_button_;
};

class DisplayInfoEareWidget : public QWidget
{
    public:
        DisplayInfoEareWidget(QWidget* parent = nullptr);
        virtual ~DisplayInfoEareWidget();
        void DisplayInfoEareStyle(QHBoxLayout* layout);

    private:
        QLabel* display_info_;
        QLabel* send_info_;
        QLabel* recv_info_;

        QPushButton* reset_count_button_;
    
    private:
        std::string send_str_;
        std::string recv_str_;
        int send_count_;
        int recv_count_;

};

class TargetHostWidget : public QWidget
{
    public:
        TargetHostWidget(QWidget* parent = nullptr);
        virtual ~TargetHostWidget();
        void TargetHostStyle(QHBoxLayout* layout);

    private:
        QLabel* target_host_l_;
        QLineEdit* target_host_le_;
        QLabel* target_port_l_;
        QLineEdit* target_port_le_;
};
}


#endif