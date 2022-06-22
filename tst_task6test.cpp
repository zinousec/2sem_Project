#include <QtTest>
#include "C:\Users\zinou\QT\Client_353\task6.h"
// add necessary includes here

class Task6test : public QObject
{
    Q_OBJECT

public:
    Task6test();
    ~Task6test();

private slots:
    void test_case1();

};

Task6test::Task6test()
{

}

Task6test::~Task6test()
{

}

void Task6test::test_case_task6()
{
    QString t="1,2;1,4;1,5;1,6;2,3;2,5;3,4;3,6;4,5;5,6";
            QCOMPARE("7,3,4",test_case_task6(1,t));
}

QTEST_APPLESS_MAIN(Task6test)

#include "tst_task6test.moc"
