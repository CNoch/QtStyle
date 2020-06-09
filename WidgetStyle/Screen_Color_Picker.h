#ifndef SCREEN_COLOR_PICKER_H
#define SCREEN_COLOR_PICKER_H

#include <QDialog>

namespace Ui {
class Screen_Color_Picker;
}

class Screen_Color_Picker : public QDialog
{
    Q_OBJECT

public:
    explicit Screen_Color_Picker(QWidget *parent = nullptr);
    ~Screen_Color_Picker();

private:
    Ui::Screen_Color_Picker *ui;
};

#endif // SCREEN_COLOR_PICKER_H
