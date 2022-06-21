#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QStringList>
#include <QString>
#include <QDebug>
#include <QList>
#include "database.h"
#include "task1.h"
//#include "task2_Strelnikov.h"
#include "task3_Marco.h"
//#include "task4_Tawfik.h"

//! \brief Файл с некоторыми функциями сервера.
//! \details Здесь реализованы функции регистрации\аутентификации пользователя и анализа вводимого текста.
//!
QByteArray parsing(QString inputString_str);

QByteArray auth(QString log, QString pass);
QByteArray reg(QString log, QString pass, QString email);

QByteArray printdb();  //1
QByteArray statistics(QString log);
void upd_statistics(QString numTask, QString plusOrMinusAnswer, QString log);

#endif // FUNCTIONS_H
