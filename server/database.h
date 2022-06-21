#ifndef DATABASE_H
#define DATABASE_H

#include <QCoreApplication>
#include <QVariant>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

class DataBase;

class DataBaseDestroyer;

class DataBase {
public:
    friend class DataBaseDestroyer;
private:
    static DataBase* p_instance;
    static DataBaseDestroyer destroyer;
    static QSqlDatabase db;
/*
    static int positive[4];
    static int negative[4];*/
protected:
    DataBase();
    DataBase(const DataBase&) = delete;
    DataBase& operator = (DataBase &) = delete;

    ~DataBase();
public:
    static DataBase* getInstance();
   /* static DataBase* getInstance() {
        if (DataBase::p_instance == nullptr) {
            DataBase::p_instance = new DataBase();
            DataBase::p_instance->db = QSqlDatabase::addDatabase("QSQLITE");
            DataBase::p_instance->db.setDatabaseName("Test.db");

            if (!DataBase::p_instance->db.open()) {
                qDebug() << DataBase::p_instance->db.lastError().text();
            }

            DataBase::destroyer.initialize(DataBase::p_instance);
        }

        return p_instance;
    }*/

    ///здесь пишем функцию сделать запрос к бд
   static QSqlQuery query_to_db(QString msg);
   static QSqlQuery query_to_db(QString msg, QString findStr, QString findMeaning);
   static QSqlQuery query_to_db_reg(QString log, QString pass, QString email);

   /*static void setPositive(int index, int num);
   static void setNegative(int index, int num);
   static int getPositive(int index);
   static int getNegative(int index);*/
};

class DataBaseDestroyer {
private:
    DataBase* p_instance = nullptr;
public:
    DataBaseDestroyer(){};
    ~DataBaseDestroyer() {
        if (p_instance != nullptr) {
            delete p_instance;
        }
    }

    void initialize(DataBase* p) {
        p_instance = p;
    }
};

#endif // DATABASE_H
