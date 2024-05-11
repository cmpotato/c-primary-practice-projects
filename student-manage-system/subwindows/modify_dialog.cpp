#include "modify_dialog.h"
#include "ui_modify_dialog.h"
#include <QMessageBox>

enum GENDER_INDEX { male, female };
static const int max_age = 30;
static const int min_age = 18;

modify_dialog::modify_dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::modify_dialog)
{
    ui->setupUi(this);
}

modify_dialog::modify_dialog(QWidget *parent, const student &stu)
    : QDialog(parent)
    , ui(new Ui::modify_dialog)
{
    ui->setupUi(this);
    ui->lineEdit_name->setText(stu.name);
    if (stu.gender == "male") {
        ui->comboBox_gender->setCurrentIndex(GENDER_INDEX::male);
    } else {
        ui->comboBox_gender->setCurrentIndex(GENDER_INDEX::female);
    }
    if (stu.age >= min_age && stu.age <= max_age) {
        ui->spinBox_age->setValue(stu.age);
    }
    ui->lineEdit_id->setText(stu.ID);
}

modify_dialog::~modify_dialog()
{
    delete ui;
}

void modify_dialog::on_buttonBox_accepted()
{
    QMessageBox messageBox;
    messageBox.setWindowTitle("confirm");
    messageBox.setText("sure to modify?");
    messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    messageBox.setDefaultButton(QMessageBox::No);
    int result = messageBox.exec(); // 使用 exec() 使对话框模态
    if (result == QMessageBox::Yes) {
        s.name = ui->lineEdit_name->text();
        s.gender = ui->comboBox_gender->currentText();
        s.age = ui->spinBox_age->value();
        s.ID = ui->lineEdit_id->text();
        emit send(s);
        this->accept();
    } else {
        return;
    }
}

