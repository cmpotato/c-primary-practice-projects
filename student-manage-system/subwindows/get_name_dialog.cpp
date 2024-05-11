#include "get_name_dialog.h"
#include "ui_get_name_dialog.h"

get_name_dialog::get_name_dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::get_name_dialog)
{
    ui->setupUi(this);

    connect(ui->buttonBox,
            &QDialogButtonBox::accepted,
            this,
            &get_name_dialog::send_name);
}

get_name_dialog::~get_name_dialog()
{
    delete ui;
}

void get_name_dialog::send_name(){
    emit send(this->ui->lineEdit->text());
}
