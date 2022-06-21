#ifndef CLIENTTCP_H
#define CLIENTTCP_H
#include <QTcpSocket>
#include <QTcpServer>
#include <QString>


class clientTCP
{
    private:
        static clientTCP* clientInstance;
        static QTcpSocket *clientSocket;
        static QHostAddress host;
        static QString login;
        clientTCP();
        clientTCP(const clientTCP &);
        clientTCP& operator = (clientTCP &);
       // static int num;
       // static int numTask;
    public:
        ~clientTCP();
        static clientTCP* getInstance();
       // static bool connectToServer();
        static QString sendToServer(QString msg);
        static bool getStatus();

        static void setLogin(QString log);
        static QString getLogin();
      //  static int getNum();
      //  static int getNumTask();
      //  static void setNumTask(int numFormTask);
public slots:
        void on_readyRead();//
};

#endif // CLIENTTCP_H
