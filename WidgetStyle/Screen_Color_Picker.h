#ifndef SCREEN_COLOR_PICKER_H
#define SCREEN_COLOR_PICKER_H
//屏幕拾色器

#include <QDialog>
#include <QWidget>
#include <QEvent>
#include <QScreen>
#include <QPixmap>

enum ENUM_WINDOW_POSITION
{
    E_LEFT_TOP,
    E_RIGHT_BOTTOM
};

namespace Ui {
class Screen_Color_Picker;
}

class Screen_Color_Picker : public QDialog
{
    Q_OBJECT

public:
    explicit Screen_Color_Picker(QWidget *parent = nullptr);
    ~Screen_Color_Picker();

    void setPosition(ENUM_WINDOW_POSITION position);

private:
    ENUM_WINDOW_POSITION getPosition();
protected:
    void enterEvent(QEvent *event);
private:
    Ui::Screen_Color_Picker *ui;

    QSize m_Scree_Size;

    ENUM_WINDOW_POSITION m_Position = E_RIGHT_BOTTOM;
};

#endif // SCREEN_COLOR_PICKER_H
