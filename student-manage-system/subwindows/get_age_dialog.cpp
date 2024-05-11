#include "get_age_dialog.h"
#include "ui_get_age_dialog.h"

get_age_dialog::get_age_dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::get_age_dialog)
{
    ui->setupUi(this);
}

get_age_dialog::~get_age_dialog()
{
    delete ui;
}

void get_age_dialog::on_buttonBox_accepted()
{
    emit send(ui->spinBox->value());
    this->accept();
}

