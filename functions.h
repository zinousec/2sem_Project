#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QString>

QString parsing(QByteArray inputString_arr);
/// \parsing
QString auth(QString log, QString pass);
/*!
 * Регистрация пользователя
 * \param[in] log хеш логина
 * \param[in] pass хэш пароля
 * \param[out] результат о регистрации (ок или описание ошибки)
 * \return
 */
QString reg(QString log, QString pass);

#endif // FUNCTIONS_H
