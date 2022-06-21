#include <QtTest>
#include "..\server\task1.h"

// add necessary includes here

class task1_class_test : public QObject
{
    Q_OBJECT

public:
    task1_class_test();
    ~task1_class_test();

private slots:
    void test_case_task1_9();

};

task1_class_test::task1_class_test()
{

}

task1_class_test::~task1_class_test()
{

}

void task1_class_test::test_case_task1_9()
{
    QString ans = "12965";
    QString ansTask1 = task1("9");
    QCOMPARE(ans, ansTask1);
}

QTEST_APPLESS_MAIN(task1_class_test)

#include "tst_task1_class_test.moc"
