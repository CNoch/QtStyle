#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include "Screen_Color_Picker.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::InitWindows()
{
    //*取消窗口栏
    this->setWindowFlag(Qt::FramelessWindowHint);
    //*设置窗口透明
    this->setAttribute(Qt::WA_TranslucentBackground);
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.fillRect(this->rect(),QColor(0,0,0,50));
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton && m_InitialPoint_bool)
    {
        QPoint point = this->pos();
        point.setX(point.x() + event->x() - m_InitialPoint.x());
        point.setY(point.y() + event->y() - m_InitialPoint.y());
        this->move(point);
    }
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    m_InitialPoint = event->pos();
    m_InitialPoint_bool = true;
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    m_InitialPoint_bool = false;
}



void Widget::on_pushButton_close_clicked()
{
    close();
}

void Widget::on_pushButton_color_picker_clicked()
{
    if (m_Screen_Color_Picker == nullptr)
        m_Screen_Color_Picker = new Screen_Color_Picker(this);
    m_Screen_Color_Picker->show();
}
