#include "mytcpserver.h"


//!
//! \brief Деструктор объекта сервера
//!
MyTcpServer::~MyTcpServer()
{
    mTcpServer->close();
    server_status=0;
}

//! \brief Конструктор объекта сервера
//! \details Проводит инициализвацию объекта сервера с последующим уведомлением в qDebug о статусе сервера.
//! \param parent Родительский объект {QObject}
//!
MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){
    DataBase::getInstance();

    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << "server is not started";
    } else {
        server_status=1;
        qDebug() << "server is started";
    }
}


//! \brief Слот нового подключения
//! \details Создаёт новый объект сокета, инициализирует его и проводит запись в список активных клиентов.
//!
void MyTcpServer::slotNewConnection(){
   if (server_status == 1){
        QTcpSocket * temp = mTcpServer->nextPendingConnection();
        //temp->write("Hello, World!!! I am echo server!\r\n");
        int idTemp = temp->socketDescriptor();
        mTcpSocket[idTemp] = temp;
        //authSocket[idTemp] = false;
        connect(temp, &QTcpSocket::readyRead, this, &MyTcpServer::slotServerRead);
        connect(temp, &QTcpSocket::disconnected, this, &MyTcpServer::slotClientDisconnected);
    }
}

//! \brief Слот чтения
//! \details Считывает вводимые клиентом данные и передаёт их в функцию парсера.
//!
void MyTcpServer::slotServerRead(){
    QTcpSocket* temp = (QTcpSocket*)sender();

    QString res = "";
    while(temp->bytesAvailable()>0)
    {
        res = temp -> readLine();
    }

    ///ТОЛЬКО ПОКА РАБОТАЕМ С PUTTY!!!!!!!!!!!!!!!!!!!!
    //res = res.mid(0,res.length()-2);

  //  temp->write(parsing(res));

    qDebug() << "received on read:" << res;
    QByteArray answer = parsing(res);

    /*QTcpSocket* tempSocket = (QTcpSocket*)sender();
    int idTemp = tempSocket->socketDescriptor();
    QByteArray answer = parsing(res, &authSocket[idTemp]);*/

    temp -> write(answer);
    qDebug() << "sent on read:" << answer << "\n";
}

//! \brief Слот отключения
//! \details Убирает сокет из списка активных и закрывает его.
//!
void MyTcpServer::slotClientDisconnected(){
    QTcpSocket* temp = (QTcpSocket*)sender();
    int idTemp = temp->socketDescriptor();
    mTcpSocket.remove(idTemp);
    //authSocket.remove(idTemp);
    temp->close();
}
