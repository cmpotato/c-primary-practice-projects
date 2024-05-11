#ifndef SECONDARY_CONFIRM_H
#define SECONDARY_CONFIRM_H

#include <QDialog>

namespace Ui {
class secondary_confirm;
}

class secondary_confirm : public QDialog
{
    Q_OBJECT

public:
    explicit secondary_confirm(QWidget *parent = nullptr);
    ~secondary_confirm();

private:
    Ui::secondary_confirm *ui;
};

#endif // SECONDARY_CONFIRM_H
