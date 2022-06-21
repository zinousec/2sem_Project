#include "mainwindow.h"
#include "ui_mainwindow.h"

//!
//! \brief Конструктор объекта приложения, так же обрабатывает взаимодействие с сервером и проверяет успешное подключение к нему
//! \param parent Родительский объект интерфейса
//!
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    clientTCP::getInstance();

    //QString ans = "null";
    //QByteArray qbAns = ans.toUtf8();
    //clientTCP::connectToServer();
    if (clientTCP::getStatus())
    {
        if (clientTCP::sendToServer("catch") == "respond string")
        {
            ui->connectionStatus->setText("Successfully connected!");
        }
        else
        {
            ui->connectionStatus->setText("Not connected!");
        }
    }


    ui_task = new FormTask;
    ui_auth = new FormAuthReg;


    connect(ui_auth, &FormAuthReg::return_auth, this, &MainWindow::show);
    ui_auth->show();

}

//!
//! \brief Деструктор объекта приложения
//!
MainWindow::~MainWindow()
{
    //delete clientTCP::getInstance();//2
    delete ui_task;
    delete ui_auth;
    delete ui;
}


void MainWindow::on_pushButton_Exit_clicked()
{
    close();
}


void MainWindow::on_actionExit_triggered()
{
    on_pushButton_Exit_clicked();
}


void MainWindow::on_pushButton_Task1_clicked()
{
    FormTask::setTaskNumber(1);
    ui_task -> FormTask::text_Task();
    ui_task -> FormTask::clean_lineEdit_Answer();
    ui_task->show();
}

void MainWindow::on_actionTask1_triggered()
{
    on_pushButton_Task1_clicked();
}

void MainWindow::on_pushButton_Task2_clicked()
{
    FormTask::setTaskNumber(2);
    ui_task -> FormTask::text_Task();
    ui_task -> FormTask::clean_lineEdit_Answer();
    ui_task->show();
}

void MainWindow::on_actionTask2_triggered()
{
    on_pushButton_Task2_clicked();
}

void MainWindow::on_pushButton_task3_clicked()
{
    FormTask::setTaskNumber(3);
    ui_task -> FormTask::text_Task();
    ui_task -> FormTask::clean_lineEdit_Answer();
    ui_task->show();
}


void MainWindow::on_actionTask3_triggered()
{
    on_pushButton_task3_clicked();
}

void MainWindow::on_pushButton_Task4_clicked()
{
    FormTask::setTaskNumber(4);
    ui_task -> FormTask::text_Task();
    ui_task -> FormTask::clean_lineEdit_Answer();
    ui_task->show();
}


void MainWindow::on_actionTask4_triggered()
{
    on_pushButton_Task4_clicked();
}

void MainWindow::on_pushButton_Statistics_clicked()
{
    QMessageBox msg_box_stat;
    QString query = clientTCP::sendToServer("statistics&" + clientTCP::getLogin());

    QStringList statisticsString_list = query.split(' ');

    msg_box_stat.setText("Your Statistics \n task1: " + statisticsString_list.at(0) + "\n task2: " + statisticsString_list.at(1) + "\n task3: " + statisticsString_list.at(2) + "\n task4: " + statisticsString_list.at(3));
    msg_box_stat.exec();
}

