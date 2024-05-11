#include "get_id_dialog.h"
#include "ui_get_id_dialog.h"

get_ID_dialog::get_ID_dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::get_ID_dialog)
{
    ui->setupUi(this);

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &get_ID_dialog::on_buttonBox_accepted);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &get_ID_dialog::on_buttonBox_rejected);
}

get_ID_dialog::~get_ID_dialog()
{
    delete ui;
}

void get_ID_dialog::on_buttonBox_accepted()
{
    emit this->send(this->ui->lineEdit->text());
    this->accept();
}

void get_ID_dialog::on_buttonBox_rejected()
{
    this->rejected();
}
