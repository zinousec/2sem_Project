#include "functions.h"
#include <QStringList>

QString parsing(QByteArray inputString_arr) {
    QString inputString_str = QString(inputString_arr);
    QStringList inputString_list = inputString_str.split(QLatin1Char('&'));
    QString NameOfFunc = inputString_list.front();
    inputString_list.pop_front();
    if (NameOfFunc == "auth") {
        return auth(inputString_list.at(0), inputString_list.at(1));
    } else if (NameOfFunc == "reg") {
        return reg(inputString_list.at(0), inputString_list.at(1));
    }
    return "error";
}

QString auth(QString log, QString pass) {
    if (log == "user" && pass == "123") {
        return "auth\n";
    } else {
        return "auth_false\n";
    }
}
QString reg(QString log, QString pass) {
    return "reg\n";
}
