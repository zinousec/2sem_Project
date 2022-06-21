#include "formauthreg.h"
#include "ui_formauthreg.h"

FormAuthReg::FormAuthReg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormAuthReg)
{
    ui->setupUi(this);
    ui->lineEdit_Email->setVisible(false);
    ui->pushButton_cancel->setVisible(false);
}

FormAuthReg::~FormAuthReg()
{
    delete ui;
    //delete ui_mw;
}

void FormAuthReg::on_pushButton_Reg_clicked()
{
    ui->lineEdit_Email->setVisible(true);
    ui->pushButton_cancel->setVisible(true);
    ui->pushButton_Reg->setVisible(false);
    //regAndAuth("reg");
}

void FormAuthReg::on_pushButton_cancel_clicked()
{
    ui->lineEdit_Email->setVisible(false);
    ui->pushButton_cancel->setVisible(false);
    ui->pushButton_Reg->setVisible(true);
}

void FormAuthReg::on_pushButton_Enter_clicked()
{
    if (ui->lineEdit_Email->isVisible()) {
        qDebug()<<"reg";
        regAndAuth("reg");
    } else {
        qDebug()<<"auth";
        regAndAuth("auth");
    }
    //emit return_auth();
    //hide();
}

void FormAuthReg::regAndAuth(QString funcType)
{
    if (clientTCP::getStatus())
    {
        QString query = "";

        QString login = ui->lineEdit_Login->text();
        QString email = ui->lineEdit_Email->text();
        QString pass = ui->lineEdit_Pass->text();

        query = funcType + "&" + login + "&" + pass;
        if (funcType == "reg") {
            query += "&" + email;
        }

        qDebug()<<query;
        query = clientTCP::sendToServer(query);

        clientTCP::setLogin(login);

        qDebug()<<query;

        if (query == "auth+")
        {

            ui->regAndAuthStatus->setText("Authorization successful!");
            emit return_auth();
            hide();
            /*ui_mw = new MainWindow;
            ui_mw->show();*/
        }
        else if (query == "auth-")
        {
            clientTCP::setLogin("");
            ui->regAndAuthStatus->setText("Authorization NOT successful!");
        }
        else if (query == "reg+")
        {
            ui->regAndAuthStatus->setText("Registration successful!");
        }
        else if (query == "reg-")
        {
            clientTCP::setLogin("");
            ui->regAndAuthStatus->setText("Registration NOT successful!");
        }
        /*else if (query == "wrong password") ui->regAndAuthStatus->setText("Неверный пароль.");
        else if (query == "user already exist") ui->regAndAuthStatus->setText("Пользователь с данным логином уже существует.");
        else if (query == "no such user") ui->regAndAuthStatus->setText("Пользователь с данным логином не найден.");*/
    }
}
