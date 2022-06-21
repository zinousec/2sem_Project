#include "task2_Strelnikov.h"

QByteArray task2_Strelnikov(QString num, QString answer)
{
    int task_number=0;
    task_number=num.toInt();
    QString w="";
    QString t=answer;
    int n=0,m=0;
    QStringList List = t.split(';');
    int first,second;
    for (int i=0;i<List.size();i++)
    {
        QStringList sList=List.at(i).split(',');
        first=sList.at(0).toInt();
        second=sList.at(1).toInt();
        if ((first>n)&&(first>second)) n=first;
        if ((second>first)&&(second>n)) n=second;
    }
    m=n;
    double b[12][12];
    QStringList StrList = t.split(";");

    for (int i=1;i<n+1;i++)
        for (int j=1;j<m+1;j++)
        {
            int check=0;
            int index=0;
            for (int y=0;y<StrList.length();y++)
            {
                if(check!=1)
                {
                    QString g;
                    g=QString::number(i)+","+QString::number(j);
                    QString p;
                    p=QString::number(j)+","+QString::number(i);
                    if (g==StrList.at(index))
                    {
                        b[i][j]=1;
                        check=1;
                        StrList.append(p);

                    }
                    else b[i][j]=0;
                    if (p==StrList.at(index))
                    {
                        b[i][j]=1;
                        check=1;

                    }
                    index++;
                }
            }
        }

    for (int i=1;i<n+1;i++)
    {
        int x=0;
        for (int j=1;j<m+1;j++)
        {
             x+=b[i][j];
        }
        for (int g=1;g<n+1;g++)
        {
            if (i==g) b[i][g]=x;
            else b[i][g]=-b[i][g];
        }

    }
    for (int i=1;i<n;i++)
         for (int j=1;j<m;j++)
        {

                 b[i][j]=b[i+1][j+1];
 }
     double z=1;
     for (int i=1;i<n;i++)
     {
         for (int k=i+1;k<n+1;k++)
         {
             double x=0;

             double v=b[k][i];
             double w=b[i][i];
             x=-v/w;
             for (int j=1;j<n+1;j++)
             {
                 b[k][j]+=x*b[i][j];
             }
         }

     }
     for (int i=1;i<n;i++)
         for (int j=1;j<n;j++)
             if (i==j) z=z*b[i][j];
     w=QString::number(z);


     return w.toUtf8();
 }
