#include<iostream>
#include "hardware.hpp"
#include "ui.hpp"
#include "widget.hpp"
#include "network.hpp"

using namespace ui;

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    // NetSetWidget* net_set_widget = new NetSetWidget();
    // net_set_widget->show();
    NetAssistUI NetAssistUI;
    NetAssistUI.show();

    return app.exec();
    
}