#pragma once

#include <QDialog>

namespace Ui {
class get_name_dialog;
}

class get_name_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit get_name_dialog(QWidget *parent = nullptr);
    ~get_name_dialog();

    void send_name();
signals:
    void send(QString name);

private:
    Ui::get_name_dialog *ui;
};

