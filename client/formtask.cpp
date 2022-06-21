#include "formtask.h"
#include "ui_formtask.h"

int FormTask::task_number = 0;
int FormTask::variant = 0;

map<int, QString> FormTask::task5Map = {
    { 1, "1,2;1,3;1,5;1,6;2,3;2,4;2,6;3,4;3,5;4,5;4,6;5,6"},
    { 2, "1,4;1,5;1,6;1,7;2,4;2,7;3,4;3,5;3,6;3,7;4,7"},
    { 3, "1,4;1,5;1,6;1,7;2,4;2,7;3,4;3,5;3,6;3,7;4,7"},
    { 4, "1,2;1,3;1,5;1,6;2,4;3,4;3,6;4,5;4,6;5,6"},
    { 5, "1,2;1,3;1,5;1,6;2,4;3,4;3,5;3,6;4,5;4,6;5,6"},
    { 6,"1,2;1,4;1,5;1,6;2,3;2,4;2,8;3,8;5,6;6,7;6,8;7,8"},
    { 7,"1,8;1,9;2,5;2,9;3,5;3,6;3,7;3,9;4,5;4,9;5,6;7,9;8,9"},
    { 8,"1,4;1,5;1,6;1,7;2,4;2,7;3,4;3,7;4,5;6,7"},
    { 9,"1,2;1,3;1,5;1,6;2,3;2,4;2,6;3,4;3,5;4,5;4,6;5,6"},
    { 10,"1,2;1,3;1,4;1,5;2,4;2,6;2,7;3,4;4,5;5,6;5,7"},
    { 11,"1,4;1,9;2,5;2,9;3,5;3,7;4,6;4,7;4,9;6,7;7,8;8,9"},
    { 12,"1,2;1,3;1,6;1,7;2,3;2,5;2,6;3,4;3,7;4,7;5,6;6,7"},
    { 13,"1,2;1,3;1,5;1,6;2,5;2,6;3,7;4,6;4,7;6,7"},
    { 14,"1,2;1,3;1,5;1,7;2,6;3,4;3,6;3,7;4,5;4,6;4,7;6,7"},
    { 15,"1,2;1,8;2,3;2,5;2,8;3,4;3,6;3,7;4,6;5,6;5,8;6,8"},
    { 16,"1,2;1,3;1,5;1,8;2,3;2,4;2,6;2,7;2,8;3,4;3,7;4,5;"},
    { 17,"1,2;1,3;1,5;2,3;2,4;2,5;3,4;3,5;4,5"},
    { 18,"1,2;1,3;1,4;1,5;2,3;2,4;2,5;3,4;3,5;4,5"},
    { 19,"1,4;1,5;1,6;1,7;2,4;2,5;2,6;2,7;3,4;3,5;3,6;3,7;4,8;5,8;6,8;7,8"},
    { 20,"1,2;1,4;1,6;1,8;2,3;2,5;2,7;3,4;3,6;3,8;4,5;4,7;5,6;5,8;6,7;7,8"},
    { 21,"1,5;1,6;1,7;1,9;2,4;2,5;2,6;3,4;3,5;3,6;3,9;4,8;5,8;4,9;6,8;7,8;7,9"},
    { 22,"1,2;1,4;1,7;1,8;3,4;2,4;2,6;3,5;3,7;3,8;4,5;4,8;5,6;7,8"},
    { 23,"1,2;1,4;1,5;1,6;2,3;2,4;2,7;3,4;3,5;3,7;4,5;4,6;4,7;5,6;6,7"},
    { 24,"1,2;1,3;1,6;1,7;2,3;2,7;2,8;3,4;3,8;4,5;4,7;4,8;5,6;5,7;5,8"},
    { 25,"1,7;1,8;2,4;2,6;2,8;2,9;3,6;3,8;4,8;5,6;5,7;6,8;6,9;7,8"},
    { 26,"1,2;1,3;1,5;1,9;2,3;2,6;2,8;3,4;3,9;4,5;4,7;4,8;5,6;5,7;6,8;6,9;8,9"},
    { 27,"1,2;1,6;2,3;2,4;2,7;3,6;4,5;4,9;4,11;5,7;6,8;6,10;7,9;7,11;8,9;9,10"},
    { 28,"1,3;1,5;1,8;1,10;2,4;2,7;3,4;3,6;3,7;4,7;4,9;5,10;6,9;7,10;8,10"},
    { 29,"1,2;1,3;1,4;1,5;2,3;2,4;2,5;3,4;3,5;4,5;4,6;4,7;5,6;5,7"},
    { 30,"1,2;1,3;1,5;1,6;2,3;2,4;2,6;3,4;3,5;3,7;3,8;6,7;6,8"}
};

FormTask::FormTask(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormTask)
{
    ui->setupUi(this);
}

FormTask::~FormTask()
{
    delete ui;
}

void FormTask::setTaskNumber(int task)
{
    FormTask::task_number = task;
}

int FormTask::getTaskNumber()
{
    return task_number;
}

void FormTask::setVariant(int var)
{
    variant = var;
}

int FormTask::getVariant()
{
    return variant;
}

QString FormTask::generate_task()
{
    FormTask::setVariant(rand() % 30 + 1);
    switch(FormTask::getTaskNumber()) {
        case 1:
            return "Найти кратчайший путь между вершинами s=v1, t=v4 в нагруженном связном ориентированном графе\nG = (V,E) = (V={v1,v2,v3,v4,v5,v6,v7,v8,v9}, E={{v1,v2},(v1,v7),{v1,v8}, {v1,v9},{v2,v3},{v2,v7},{v2,v9},{v3,v4},{v3,v6},{v3,v9}, (v4,v5), (v4,v6), {v4,v7},{v5,v6},{v6,v7},{v6,v8},{v6,v9},{v7,v9},{v8,v9}}).\nВес wji ребра {vi,vj} или дуги (vi,vj) равен N(i^2+j^2)+i^2+j^2+i+j по модулю 10 (остаток от деления wij на 10). N есть номер варианта. \nНеориентированные ребра (проходимые в обоих направлениях) указаны в фигурных скобках. Ориентированные ребра указаны в круглых скобках. \nТретья координата ребра есть его вес.\nN=" + QString::number(FormTask::getVariant());
        break;
        case 2:
            return "В ненагруженном графе G " + task5Map[FormTask::getVariant()] + " с помощью алгоритма удаления циклических ребер найти фундаментальную систему циклов и соответствующие множество хорд, каркас, все фундаментальные сечения (разрезы).\nN=" + QString::number(FormTask::getVariant());
        break;
        case 3:
            return "" + QString::number(FormTask::getVariant());
        break;
        case 4:
            return "" + QString::number(FormTask::getVariant());
        break;
    }
    return "";
}

void FormTask::text_Task() {
    ui->TextBrowser_Task -> setText(generate_task());
}

void FormTask::clean_lineEdit_Answer() {
    ui->lineEdit_Answer -> setText("");
}

/*
QString chech_answer(int task_num, QString ans, QString var)
{
    if(ans == solve(task_num, var))
        return "+";
    else
        return "-";
}
*/

void FormTask::on_pushButton_clicked()
{
    QString answer = ui->lineEdit_Answer->text();

    QString res;
    if (FormTask::getTaskNumber() == 1) {
        res = "task" + QString::number(FormTask::getTaskNumber()) + "&" + QString::number(FormTask::getVariant()) + "&" + answer;
    } else if (FormTask::getTaskNumber() == 3) {
        res = "task" + QString::number(FormTask::getTaskNumber()) + "&" + task5Map[FormTask::getVariant()] + "&" + answer;
    }
    res = clientTCP::sendToServer(res);

    QString query = "upd_stat&" + QString::number(FormTask::getTaskNumber()) + "&" + res + "&" + res + "&" + clientTCP::getLogin();
    query = clientTCP::sendToServer(query);

    QMessageBox msg_box;
    msg_box.setText(res);
    msg_box.exec();

    hide();
}
