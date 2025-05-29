#include "ui.hpp"

namespace ui {
    BesUI::BesUI() : QMainWindow()
    {
        button = new QPushButton("button");
        button->show();
    }

    BesUI::~BesUI() 
    {      
        delete button;
    }

}