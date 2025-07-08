#include<iostream>
#include "hardware.hpp"
#include "ui.hpp"
#include "widget.hpp"
#include "network.hpp"

using namespace ui;

int main(int argc, char** argv)
{
#if 1 // netassit
    QApplication app(argc, argv);

    NetAssistUI* net_assit_ui = new NetAssistUI();

    net_assit_ui->InitLayout();
    net_assit_ui->show();

    return app.exec();
#endif
    

}