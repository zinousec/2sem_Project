#include "mainwindow.h"

#include <QApplication>

//!
//! \brief ���� �������
//! \param argc �������� ������� �1
//! \param argv �������� ������� �2
//! \return ��������� ���������� ����������
//!

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.show();
    return a.exec();
}
