#ifndef FORMTASK_H
#define FORMTASK_H

#include <QWidget>
#include <QMessageBox>
#include <map>
#include "clienttcp.h"

using std::map;

namespace Ui {
class FormTask;
}

class FormTask : public QWidget
{
    Q_OBJECT

private:
    Ui::FormTask *ui;
    static int task_number;
    static int variant;
    QString generate_task();
    static map<int, QString> task5Map;

public:
    explicit FormTask(QWidget *parent = nullptr);
    ~FormTask();

    static void setTaskNumber(int task);
    static int getTaskNumber();
    static void setVariant(int var);
    static int getVariant();
    void text_Task();
    void clean_lineEdit_Answer();

private slots:
    void on_pushButton_clicked();

};

#endif // FORMTASK_H
