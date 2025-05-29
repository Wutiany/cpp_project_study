#ifndef __UI_UI_HPP__
#define __UI_UI_HPP__

#include <QApplication>
#include <QMainWindow>
#include <QPushButton>

namespace ui {  
    class BesUI : public QMainWindow {
        public:
        BesUI();
        ~BesUI();
        public:
        QPushButton* button;
    };
}


#endif