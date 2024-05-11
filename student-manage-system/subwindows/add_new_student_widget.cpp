#include "add_new_student_widget.h"
#include "ui_add_new_student_widget.h"

add_new_student_widget::add_new_student_widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::add_new_student_widget)
{
    ui->setupUi(this);
    ui->comboBox_gender->addItem("male");
    ui->comboBox_gender->addItem("female");
}

add_new_student_widget::~add_new_student_widget()
{
    delete ui;
}

void add_new_student_widget::on_pushButton_confirm_clicked()
{
    //send_student_info(ui->lineEdit_name->text(),ui->comboBox_gender->currentText(),ui->lineEdit_age->text().toInt(),ui->lineEdit_id->text());
    emit send_student_info(ui->lineEdit_name->text(),ui->comboBox_gender->currentText(),ui->lineEdit_age->text().toInt(),ui->lineEdit_id->text());
}

void add_new_student_widget::on_pushButton_cancel_clicked()
{
    this->close();
}


QString add_new_student_widget::get_name(){
    return ui->lineEdit_name->text();
}

QString add_new_student_widget::get_gender(){
    return ui->comboBox_gender->currentText();
}

int add_new_student_widget::get_age(){
    return ui->lineEdit_age->text().toInt();
}

QString add_new_student_widget::get_ID(){
    return ui->lineEdit_id->text();
}
