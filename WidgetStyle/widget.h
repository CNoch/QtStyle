#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QPaintEvent>
#include "Screen_Color_Picker.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    //
    void InitWindows();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private slots:

    void on_pushButton_close_clicked();

    void on_pushButton_color_picker_clicked();

private:
    Ui::Widget *ui;

    Screen_Color_Picker *m_Screen_Color_Picker = nullptr;

    QPoint m_InitialPoint;  //初始点坐标
    bool m_InitialPoint_bool = false;//鼠标点击主窗口标识
};
#endif // WIDGET_H
