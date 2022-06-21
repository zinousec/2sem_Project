#ifndef FORMAUTHREG_H
#define FORMAUTHREG_H

#include <QWidget>
#include <QString>
#include "clienttcp.h"
//#include "mainwindow.h"

namespace Ui {
class FormAuthReg;
}

class FormAuthReg : public QWidget
{
    Q_OBJECT

public:
    explicit FormAuthReg(QWidget *parent = nullptr);
    ~FormAuthReg();
private:
    Ui::FormAuthReg *ui;
    void regAndAuth(QString funcType);

private slots:
    void on_pushButton_Reg_clicked();

    void on_pushButton_cancel_clicked();

    void on_pushButton_Enter_clicked();

signals:
    void return_auth();
};

#endif // FORMAUTHREG_H
