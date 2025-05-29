#include<iostream>
#include "hardware.hpp"
#include "ui.hpp"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    ui::BesUI bes;
    return app.exec();
}