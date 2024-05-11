#ifndef MODIFY_DIALOG_H
#define MODIFY_DIALOG_H

#include <QDialog>
#include "student.h"

namespace Ui {
class modify_dialog;
}

class modify_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit modify_dialog(QWidget *parent = nullptr);
    modify_dialog(QWidget *parent, const student &stu);
    ~modify_dialog();

    student s;


signals:
    void send(student s);

private slots:
    void on_buttonBox_accepted();

private:

    Ui::modify_dialog *ui;
};

#endif // MODIFY_DIALOG_H
