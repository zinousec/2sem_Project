#include "database.h"

DataBase* DataBase::p_instance = nullptr;
DataBaseDestroyer DataBase::destroyer;
QSqlDatabase DataBase::db;

/*int DataBase::positive[4] = {};
int DataBase::negative[4] = {};*/

//!
//! \brief Конструктор объекта класса DataBase
//!
DataBase::DataBase() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("sqlite.db");

    if(!db.open()) {
        qDebug() << db.lastError().text();
    }

   /* for (int i = 0; i <= 3; i++) {
        positive[i] = 0;
    }

    for (int i = 0; i <= 3; i++) {
        negative[i] = 0;
    }

    QSqlQuery res = query_to_db("SELECT * FROM User");

    QSqlRecord rec = res.record();
    const int task1Index = rec.indexOf("task1");
    const int task2Index = rec.indexOf("task2");
    const int task3Index = rec.indexOf("task3");
    const int task4Index = rec.indexOf("task4");

    while(res.next()) {
        if (res.value(task1Index).toString() == "1") {
            setPositive(0, getPositive(0) + 1);
        } else if (res.value(task1Index).toString() == "-1") {
            setNegative(0, getNegative(0) + 1);
        }

        if (res.value(task2Index).toString() == "1") {
            setPositive(1, getPositive(1) + 1);
        } else if (res.value(task2Index).toString() == "-1") {
            setNegative(1, getNegative(1) + 1);
        }

        if (res.value(task3Index).toString() == "1") {
            setPositive(2, getPositive(2) + 1);
        } else if (res.value(task3Index).toString() == "-1") {
            setNegative(2, getNegative(2) + 1);
        }

        if (res.value(task4Index).toString() == "1") {
            setPositive(3, getPositive(3) + 1);
        } else if (res.value(task4Index).toString() == "-1") {
            setNegative(3, getNegative(3) + 1);
        }
    }*/
    /*query = QSqlQuery(db); //создали таблицу
    query.exec("CREATE TABLE User("r
                   "login VARCHAR(20) NOT NULL, "
                   "password VARCHAR(20) NOT NULL"
                   ")");
    */
}

//!
//! \brief Деструктор объекта класса DataBase
//!
DataBase::~DataBase() {
//    query.exec("DROP TABLE User");
    db.close();
}

DataBase* DataBase::getInstance()  {
    if (!p_instance) {
        p_instance = new DataBase();
        destroyer.initialize(p_instance);
    }
    return p_instance;
}


QSqlQuery DataBase::query_to_db(QString msg) {
    QSqlQuery query(db);
    query.exec(msg);

    return query;
}

QSqlQuery DataBase::query_to_db(QString msg, QString findStr, QString findMeaning) {
    QSqlQuery query(db);
    query.prepare(msg);
    query.bindValue(findStr, findMeaning);
    query.exec();
    return query;
}

QSqlQuery DataBase::query_to_db_reg(QString log, QString pass, QString email) {
    QSqlQuery query(db);
    query.prepare("INSERT INTO User(login, password, email) "
                              "VALUES (:login, :password, :email)");
    query.bindValue(":login", log);
    query.bindValue(":password", pass);
    query.bindValue(":email", email);
    query.exec();
    return query;
}
/*
void DataBase::setPositive(int index, int num) {
    positive[index] = num;
}

void DataBase::setNegative(int index, int num) {
    negative[index] = num;
}

int DataBase::getPositive(int index) {
    return positive[index];
}

int DataBase::getNegative(int index) {
    return negative[index];
}
*/
