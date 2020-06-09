#include "Screen_Color_Picker.h"
#include "ui_Screen_Color_Picker.h"

Screen_Color_Picker::Screen_Color_Picker(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Screen_Color_Picker)
{
    ui->setupUi(this);
}

Screen_Color_Picker::~Screen_Color_Picker()
{
    delete ui;
}
