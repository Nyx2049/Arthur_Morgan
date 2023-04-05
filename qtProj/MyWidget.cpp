//
// Created by 风雨不知味 on 2023/4/2.
//

#include "MyWidget.h"
#include <QIcon>
#include <QPixmap>
#include <QImageReader>
#include <QPainter>
#include <QLabel>

MyWidget::~MyWidget() {

}

MyWidget::MyWidget(QWidget *) {
    setWindowTitle("方案正向设计平台");
    resize(1080, 1100);
//    QPushButton *w2 = new QPushButton("图例", this);
//    connect(w2, &QPushButton::clicked, w2, &QPushButton::hide);
//    QWidget *w2 = new QWidget(this);
//    w2->setGeometry(0, 0, 100, 200);
//    w2->
//
//    w2->show();
}

void MyWidget::drawPic(const QString &path) {
    QLabel *L = new QLabel(this);
    QImage img(path);
    L->setPixmap(QPixmap::fromImage(img));
    this->show();
}
