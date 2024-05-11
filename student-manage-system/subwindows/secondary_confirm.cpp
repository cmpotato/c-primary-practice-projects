#include "secondary_confirm.h"
#include "ui_secondary_confirm.h"

secondary_confirm::secondary_confirm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::secondary_confirm)
{
    ui->setupUi(this);
}

secondary_confirm::~secondary_confirm()
{
    delete ui;
}
