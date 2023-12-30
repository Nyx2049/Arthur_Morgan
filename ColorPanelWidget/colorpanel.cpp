//
// Created by 风雨不知味 on 2023/10/21.
//

#include "colorpanel.h"

Color::Color() :m_red(0), m_green(0), m_blue(0)
{

}

Color::Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t index):m_red(red), m_green(green), m_blue(blue), m_index(index){

}

ColorPanel::ColorPanel(const std::vector<Color>& colors, const QSize& size, QWidget *parent) : QWidget(parent), m_size(size), m_colors(colors)
{
    layout = new QGridLayout;
    setFixedSize(1080, 720);
    setLayout(layout);
    initbtns();
}

void ColorPanel::initbtns() const{
    int count = 10;
    int index = 0;
    int row = 0;
    for (;index < m_colors.size(); ++index)
    {
        QPushButton* btn = new QPushButton();
        auto c = m_colors[index].getColorString();
        auto c1 = c.toStdString();
        btn->setStyleSheet(QString("QPushButton { background-color: rgb(%1) }").arg(m_colors[index].getColorString()));
        btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        int row = index / count;
        int b = index % count;
        layout->addWidget(btn, index / count, index % count);
    }
}

void test() {
    std::vector<Color> a;
    a.emplace_back(10, 10, 10, 100);
    a.emplace_back(10, 100, 10, 100);
    a.emplace_back(10, 10, 100, 100);
    a.emplace_back(10, 100, 100, 100);
    a.emplace_back(10, 200, 10, 100);

    a.emplace_back(10, 10, 10, 100);
    a.emplace_back(10, 100, 10, 100);
    a.emplace_back(10, 10, 100, 100);
    a.emplace_back(10, 100, 100, 100);
    a.emplace_back(10, 200, 10, 100);
    a.emplace_back(10, 10, 210, 100);
    a.emplace_back(10, 210, 210, 100);
    a.emplace_back(210, 110, 10, 100);
    a.emplace_back(210, 10, 10, 100);
    a.emplace_back(210, 10, 10, 100);

    a.emplace_back(10, 10, 10, 100);
    a.emplace_back(10, 100, 10, 100);
    a.emplace_back(10, 10, 100, 100);
    a.emplace_back(10, 100, 100, 100);
    a.emplace_back(10, 200, 10, 100);
    a.emplace_back(10, 10, 10, 100);
    a.emplace_back(10, 100, 10, 100);
    a.emplace_back(10, 10, 100, 100);
    a.emplace_back(10, 100, 100, 100);
    a.emplace_back(10, 200, 10, 100);
    a.emplace_back(10, 10, 10, 100);
    a.emplace_back(10, 100, 10, 100);
    a.emplace_back(10, 10, 100, 100);
    a.emplace_back(10, 100, 100, 100);
    a.emplace_back(10, 200, 10, 100);
    a.emplace_back(10, 10, 210, 100);
    a.emplace_back(10, 210, 210, 100);
    a.emplace_back(210, 110, 10, 100);
    a.emplace_back(210, 10, 10, 100);
    a.emplace_back(210, 10, 10, 100);

    a.emplace_back(130, 10, 10, 100);
    a.emplace_back(10, 100, 10, 100);
    a.emplace_back(410, 10, 100, 100);
    a.emplace_back(10, 100, 100, 100);
    a.emplace_back(10, 2100, 410, 100);
    a.emplace_back(10, 10, 210, 100);
    a.emplace_back(10, 210, 210, 100);
    a.emplace_back(210, 110, 10, 100);
    a.emplace_back(210, 10, 10, 100);
    a.emplace_back(210, 10, 10, 100);
    a.emplace_back(10, 10, 210, 100);
    a.emplace_back(10, 210, 210, 100);
    a.emplace_back(210, 110, 10, 100);
    a.emplace_back(210, 10, 10, 100);
    a.emplace_back(210, 10, 10, 100);

    auto *b =new ColorPanel(a, QSize(0, 0));
    b->show();
}
