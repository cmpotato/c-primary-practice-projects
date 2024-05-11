#pragma once

#include <QDialog>

namespace Ui {
class gender_dialog;
}

class gender_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit gender_dialog(QWidget *parent = nullptr);
    ~gender_dialog();



signals:
    void send(QString gender);

private slots:
    void on_pushButton_female_clicked();

    void on_pushButton_male_clicked();

private:
    Ui::gender_dialog *ui;
};

