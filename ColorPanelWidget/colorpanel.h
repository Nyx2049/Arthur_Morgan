//
// Created by 风雨不知味 on 2023/10/21.
//

#ifndef COLORPANELWIDGET_COLORPANEL_H
#define COLORPANELWIDGET_COLORPANEL_H

#include <QWidget>
#include <QPushButton>
#include <QString>
#include <string>
#include <vector>
#include <QGridLayout>
class Color
{
public:
    Color();
    Color(uint8_t, uint8_t, uint8_t, uint8_t);
    uint8_t* getColor()
    {
        return new uint8_t[4]{m_red, m_green, m_blue, m_index};
    }
    QString getColorString() const
    {
       return QString::fromStdString(std::to_string(m_red) + "," + std::to_string(m_green) + "," + std::to_string(m_blue));
    }
    QString getColorStringWithIndex() const
    {
        return QString::fromStdString(std::to_string(m_red) + "," + std::to_string(m_green) + "," + std::to_string(m_blue) + "-" + std::to_string(m_index));
    }
    uint8_t getIndex() const
    {
        return m_index;
    }
private:
    uint8_t m_red;
    uint8_t m_green;
    uint8_t m_blue;
    uint8_t m_index;
};

class ColorPanel : public QWidget
{
    Q_OBJECT
public:
    ColorPanel(const std::vector<Color>& colors, const QSize&, QWidget *parent = nullptr);
    ~ColorPanel() {}

private:
    void initbtns() const;
private:
    std::vector<Color> m_colors;
    QGridLayout* layout = nullptr;
    QSize m_size;
};

void test();


#endif //COLORPANELWIDGET_COLORPANEL_H
