//
// Created by 风雨不知味 on 2023/4/2.
//

#ifndef QTPROJ_MYWIDGET_H
#define QTPROJ_MYWIDGET_H

#include <QWidget>

class MyWidget : public QWidget {
Q_OBJECT
public:
    MyWidget(QWidget * = nullptr);

    ~MyWidget();

    void drawPic(const QString &);
};


#endif //QTPROJ_MYWIDGET_H
