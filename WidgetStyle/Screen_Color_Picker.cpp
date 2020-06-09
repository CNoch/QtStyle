#include "Screen_Color_Picker.h"
#include "ui_Screen_Color_Picker.h"
#include <QDesktopWidget>
#include <QPainter>

Screen_Color_Picker::Screen_Color_Picker(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Screen_Color_Picker)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    m_Scree_Size = QApplication::desktop()->size();
    this->setFixedSize(m_Scree_Size.width()/5,m_Scree_Size.height()/3);
    this->move(m_Scree_Size.width()-this->width(), m_Scree_Size.height()-this->height());
}

Screen_Color_Picker::~Screen_Color_Picker()
{
    delete ui;
}

void Screen_Color_Picker::setPosition(ENUM_WINDOW_POSITION position)
{
    m_Position = position;
    switch (position) {
    case E_RIGHT_TOP:
    {
        this->move(m_Scree_Size.width()-this->width(),0);
        break;
    }
    case E_RIGHT_BOTTOM:
    {
        this->move(m_Scree_Size.width()-this->width(),m_Scree_Size.height()-this->height());
        break;
    }
    }
}

ENUM_WINDOW_POSITION Screen_Color_Picker::getPosition()
{
    return m_Position;
}

void Screen_Color_Picker::enterEvent(QEvent *event)
{
    ENUM_WINDOW_POSITION position = getPosition();
    switch (position) {
    case E_RIGHT_TOP:
    {
        setPosition(E_RIGHT_BOTTOM);
        break;
    }
    case E_RIGHT_BOTTOM:
    {
        setPosition(E_RIGHT_TOP);
        break;
    }
    }
}

void Screen_Color_Picker::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.fillRect(this->rect(),QColor(0,0,0,100));
}
