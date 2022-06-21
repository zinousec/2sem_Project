#include "clienttcp.h"
clientTCP* clientTCP::clientInstance = nullptr;
QHostAddress clientTCP::host = QHostAddress("127.0.0.1");
QTcpSocket* clientTCP::clientSocket = new QTcpSocket;

QString clientTCP::login = "";

/*int clientTCP::num = 0;
int clientTCP::numTask = 0;*/

clientTCP::clientTCP(){
    clientSocket->connectToHost(host, 33333);

    //num = rand() % 30 + 1;
    //connect(clientSocket, &QTcpSocket::readyRead, this, &clientTCP::on_readyRead);
}

clientTCP::~clientTCP()
{
    clientSocket->close();
    delete clientSocket;
}

clientTCP* clientTCP::getInstance()
{
    if(!clientInstance) clientInstance = new clientTCP();
    return clientInstance;
}

QString clientTCP::sendToServer(QString msg)
{
    QString serverRespond = "NaN";
    if(!(clientSocket -> isWritable())) return "cannot-write";
    if(!(clientSocket -> bytesAvailable()==0)) return "busy-stream";
    clientSocket -> write(msg.toUtf8());
    //qDebug() << "sent:" << msg;
    clientSocket -> waitForReadyRead();
    serverRespond = clientSocket -> readLine(); qDebug() << "received:" << serverRespond << "\n";
    return serverRespond;
}

void clientTCP::setLogin(QString log)
{
    login = log;
}

QString clientTCP::getLogin()
{
    return login;
}
/*
bool clientTCP::connectToServer()
{
    clientSocket->connectToHost(host, 33333);
    if(clientSocket->isWritable() && clientSocket->isReadable())
    {
        return clientSocket->isWritable();
    }
    return false;
}
*/
bool clientTCP::getStatus()
{
    if(clientSocket->isWritable() && clientSocket->isReadable()) return true;
    else return false;
}

/*int clientTCP::getNum()
{
    return num;
}

int clientTCP::getNumTask()
{
    return numTask;
}

void clientTCP::setNumTask(int numFormTask)
{
    numTask = numFormTask;
}*/

/*void clientTCP::on_readyRead() {
    QTcpSocket* temp = (QTcpSocket*)sender();

    QString res = "";
    while(temp->bytesAvailable()>0)
    {
        res = temp -> readLine();
    }

    ///ТОЛЬКО ПОКА РАБОТАЕМ С PUTTY!!!!!!!!!!!!!!!!!!!!
    res = res.mid(0,res.length()-2);



  //  temp->write(parsing(res));

    qDebug() << "received on read:" << res;
    QByteArray answer = parsing(res);
    temp -> write(answer);
    qDebug() << "sent on read:" << answer << "\n";
}
*/
