#pragma once

#include <QWidget>

namespace Ui {
class add_new_student_widget;
}

class add_new_student_widget : public QWidget
{
    Q_OBJECT

public:
    explicit add_new_student_widget(QWidget *parent = nullptr);
    ~add_new_student_widget();

    QString get_name();
    QString get_gender();
    int get_age();
    QString get_ID();

signals:
    void send_student_info(QString name, QString gender, int age, QString ID);

private slots:
    void on_pushButton_confirm_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::add_new_student_widget *ui;
};
