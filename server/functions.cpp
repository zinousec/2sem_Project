#include "functions.h"

//! \brief Функция парсинга
//! \details Функция анализа вводимого текста. Воспринимает шаблоны xxx&xxx&xxx как вызовы функций, остальное выводит на экран пользователя.
//! \param input_str Переменная для хранения разбитой функции
//! \return Возвращает статус вызова функции. Приведено к человекочитаемому формату.
//!
QByteArray parsing(QString inputString_str) {

    /*if (inputString_arr.contains('$')) {
        return tasks -> value(inputString_arr.split('$').back().toInt());
    } else if(inputString_arr.contains('&')) {*/
    QStringList inputString_list = inputString_str.split('&');

    QString nameOfFunc = inputString_list.front();
    inputString_list.pop_front();

    /*if (nameOfFunc == "auth")
    {                             //auth&log&pass
        if (auth(inputString_list.at(0), inputString_list.at(1)) == "auth+") {

            return "auth+";
        }
        return "auth-";
    }*/

    /*if (!) {
        return "error auth!";
    }*/

    if (nameOfFunc == "print") {
        return printdb();
    } else if (nameOfFunc == "statistics") {                     //statistics&log
        return statistics(inputString_list.at(0));
    } else if (nameOfFunc == "upd_stat") {                       //upd_stat&task_number&+&log
        upd_statistics(inputString_list.at(0), inputString_list.at(1), inputString_list.at(2));
        return "upd+";
    }

//Здесь добавить варианты обработок запросов к серверу
    if (nameOfFunc == "auth") {                       //auth&log&pass
        return auth(inputString_list.at(0), inputString_list.at(1));
    } else if (nameOfFunc == "reg") {                       //reg&log&pass&email
        return reg(inputString_list.at(0), inputString_list.at(1), inputString_list.at(2));
    } else if (nameOfFunc == "task1") {                       //task1&num&answer
        return ((task1(inputString_list.at(0)) == inputString_list.at(1))?"+":"-");
    }/* else if (nameOfFunc == "task2") {                       //task2&num&ListOfRebra&answer
        return ((task2(inputString_list.at(0), inputString_list.at(1)) == inputString_list.at(2))? "+":"-");
    }*/ else if (nameOfFunc == "task3") {                       //task3&ListOfRebra&answer
        return ((task3(inputString_list.at(0)) == inputString_list.at(1))? "+":"-");
    }/* else if (nameOfFunc == "task4") {                       //task4&num&ListOfRebra&answer
        return ((task4(inputString_list.at(0), inputString_list.at(1)) == inputString_list.at(2))? "+":"-");
    }*/
    //statistics&
    //upd_stat&task_number&+
   // }
    return "respond string";
}


//!
//! \brief Функция регистрации нового пользователя
//! \details Функция обращается к базе данных, проверяет отсутствие введённой пары и проводит запись пары в базу данных.
//! \param login Логин пользователя {char, max 20 символов}
//! \param pass Пароль пользователя {char, max 20 символов}
//! \return Если пара найдена в базе, то регистрация считается успешной. Если в БД найден только логин, а пароль не совпадает - регистрация провалена.
//!

/*
    QSqlRecord rec = query.record();
    const int loginIndex = rec.indexOf("login"); //номер "столбца"
    const int passwordIndex = rec.indexOf("password");

    pass = pass.remove((pass.size() - 2), (pass.size() - 1));
    query.next();

    if(!query.isValid()) {
        query.prepare("INSERT INTO User(login, password) "
                          "VALUES (:login, :password)");
        query.bindValue(":password", pass);
        query.bindValue(":login", log);

        query.exec(); // выполнить запрос
        return "register true";
    }
    else if (query.value(loginIndex) == log && query.value(passwordIndex) != pass) {
        return "wrong password";
    }
    return "user already exist";
*/
QByteArray reg(QString log, QString pass, QString email) {

    DataBase::getInstance();
    QSqlQuery res = DataBase::query_to_db("SELECT * FROM User WHERE login==:login", ":login", log);


    QSqlRecord rec = res.record();
    const int loginIndex = rec.indexOf("login"); //номер "столбца"
    //const int passwordIndex = rec.indexOf("password");

    //email
    //pass = pass.remove((pass.size() - 2), (pass.size() - 1));

     res.next();
     qDebug()<< res.value(loginIndex)<<"\n";

    if(!res.isValid()) {
        DataBase::query_to_db_reg(log, pass, email);
        return "reg+";
    }

    return "reg-";
}

//!
//! \brief Функция аутентификации пользователя
//! \details Функция обращается к базе данных, проверяет наличие введённой пары и проводит валидацию данных.
//! \param login Логин пользователя {char, max 20 символов}
//! \param pass Пароль пользователя {char, max 20 символов}
//! \return Возвращает сигнал true, если в базе данных найдена введённая пара логин\пароль
//!
QByteArray auth(QString log, QString pass) {
    QSqlQuery res = DataBase::query_to_db("SELECT * FROM User WHERE login==:login", ":login", log);

    QSqlRecord rec = res.record();
    const int passwordIndex = rec.indexOf("password");

    //pass = pass.remove((pass.size() - 2), (pass.size() - 1));

    res.next();

    if(!rec.isEmpty() && res.isValid())
    {
        if (res.value(passwordIndex) != pass) {
            return "auth-";
        }
        return "auth+";
    }

    return "auth-";
}

//!
//! \brief Функция вывода всех записей БД
//!
QByteArray printdb()
{
    DataBase::getInstance();
    QSqlQuery res = DataBase::query_to_db("SELECT * FROM User");

    QSqlRecord rec = res.record();
    const int loginIndex = rec.indexOf("login");
    const int passwordIndex = rec.indexOf("password");
    const int emailIndex = rec.indexOf("email");
    const int task1Index = rec.indexOf("task1");
    const int task2Index = rec.indexOf("task2");
    const int task3Index = rec.indexOf("task3");
    const int task4Index = rec.indexOf("task4");

    while(res.next()) {
        qDebug() << res.value(loginIndex).toString()
            << "\t" << res.value(passwordIndex).toString()
            << "\t" << res.value(emailIndex).toString()
            << "\t" << res.value(task1Index).toString()
            << "\t" << res.value(task2Index).toString()
            << "\t" << res.value(task3Index).toString()
            << "\t" << res.value(task4Index).toString() << "\n";

    }

    return "DB";
}



// + " " + DataBase::query_to_db("SELECT SUM(task2) FROM User") + " " + DataBase::query_to_db("SELECT SUM(task3) FROM User") + " " + DataBase::query_to_db("SELECT SUM(task4) FROM User")
/*DataBase::getInstance();
QByteArray statistics_to_string = "";

for (int i = 1; i <= 4; i++) {
    QSqlQuery res = DataBase::query_to_db("SELECT SUM(task " + QString::number(i) + ") FROM User");
    QSqlRecord rec = res.record();
    if (i != 4) {
        statistics_to_string += res.value(rec.indexOf("SUM")).toString().toUtf8() + " ";
    }
}*/

/*QByteArray statistics_to_string = "";

for (int i = 0; i <= 3; i++) {
    if (i != 3) {
        statistics_to_string += QString::number(DataBase::getPositive(i)) + " ";//append
    }
}

statistics_to_string += "&";

for (int i = 0; i <= 3; i++) {
    if (i != 3) {
        statistics_to_string += QString::number(DataBase::getNegative(i)) + " ";
    }
}*/

QByteArray statistics(QString log) {

    QSqlQuery res = DataBase::query_to_db("SELECT * FROM User WHERE login==:login", ":login", log);

    QByteArray statistics_to_string = "";

    QSqlRecord rec = res.record();
    const int task1Index = rec.indexOf("task1");
    const int task2Index = rec.indexOf("task2");
    const int task3Index = rec.indexOf("task3");
    const int task4Index = rec.indexOf("task4");

    res.next();

    statistics_to_string = (res.value(task1Index).toString() + " " + res.value(task2Index).toString() + " " + res.value(task3Index).toString() + " " + res.value(task4Index).toString()).toUtf8();

    return statistics_to_string;
}

void upd_statistics(QString numTask, QString plusOrMinusAnswer, QString log) {

    int numAnswer = 0;

    QSqlQuery res = DataBase::query_to_db("SELECT * FROM User WHERE login==:login", ":login", log);

    QSqlRecord rec = res.record();
    const int taskIndex = rec.indexOf("task" + numTask);

    res.next();

    numAnswer = res.value(taskIndex).toInt();

    if (plusOrMinusAnswer == "+") {
        numAnswer++;
    } else {
        numAnswer--;
    }

    DataBase::query_to_db("UPDATE User SET task" + numTask + " = " + QString::number(numAnswer) + " WHERE login = :login", ":login", log);

    printdb();
}
/*
QByteArray printdb()
{
    DataBase::getInstance();
    DataBase::query_to_db("INSERT INTO User(login, password,task1,task2,task3,task4) VALUES (\"asdfg\", \"asdfg\",0,0,0,0)");
    return "DB";
}
*/
