#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "formtask.h"
#include <QMessageBox>
#include "formauthreg.h"
#include "clienttcp.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


//!
//! \brief ????? ???????
//! \details ? ?????? ?????? ??????????? ??????? ??? ????????? ???????? ???????????? ? ????????? ?????? ?? ??????.
//!
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Exit_clicked();
    void on_actionExit_triggered();
    void on_pushButton_Task1_clicked();
    void on_actionTask1_triggered();
    void on_pushButton_Task2_clicked();
    void on_actionTask2_triggered();
    void on_pushButton_task3_clicked();
    void on_actionTask3_triggered();
    void on_pushButton_Task4_clicked();
    void on_actionTask4_triggered();

    void on_pushButton_Statistics_clicked();

private:
    Ui::MainWindow *ui;
    FormTask *ui_task;
    FormAuthReg *ui_auth;
};
#endif // MAINWINDOW_H
