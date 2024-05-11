#ifndef GET_AGE_DIALOG_H
#define GET_AGE_DIALOG_H

#include <QDialog>

namespace Ui {
class get_age_dialog;
}

class get_age_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit get_age_dialog(QWidget *parent = nullptr);
    ~get_age_dialog();

signals:
    void send(int age);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::get_age_dialog *ui;
};

#endif // GET_AGE_DIALOG_H
