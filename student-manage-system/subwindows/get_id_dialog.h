#ifndef GET_ID_DIALOG_H
#define GET_ID_DIALOG_H

#include <QDialog>

namespace Ui {
class get_ID_dialog;
}

class get_ID_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit get_ID_dialog(QWidget *parent = nullptr);
    ~get_ID_dialog();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

signals:
    void send(QString ID);

private:
    Ui::get_ID_dialog *ui;
};

#endif // GET_ID_DIALOG_H
