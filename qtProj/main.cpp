#include <QApplication>
#include <QPushButton>
#include "MyWidget.h"
#include <QLabel>
#include <QMainWindow>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MyWidget *w = new MyWidget();
    w->drawPic("testpic2.png");
    w->show();
    return QApplication::exec();
}
