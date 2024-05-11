#include "gender_dialog.h"
#include "ui_gender_dialog.h"

gender_dialog::gender_dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::gender_dialog)
{
    ui->setupUi(this);
}

gender_dialog::~gender_dialog()
{
    delete ui;
}

void gender_dialog::on_pushButton_female_clicked()
{
    emit this->send("female");
    this->accept();
}

void gender_dialog::on_pushButton_male_clicked()
{
    emit this->send("male");
    this->accept();
}
