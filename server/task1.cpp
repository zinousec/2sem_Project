#include "task1.h"

QByteArray task1(QString num)
{
    qDebug() << num;
    //qDebug() << answer;
    const int SIZE = 9;
    int a[SIZE][SIZE] = {
            { 0, -1, 0, 0, 0, 0, -1, -1, -1 },
            { -1, 0, -1, 0, 0, 0, -1, 0, -1 },
            { 0, -1, 0, -1, 0, -1, 0, 0, -1 },
            { 0, 0, -1, 0, -1, -1, -1, 0, 0 },
            { 0, 0, 0, -1, 0, -1, 0, 0, 0 },
            { 0, 0, -1, -1, -1, 0, -1, -1, -1 },
            { -1, -1, 0, -1, 0, -1, 0, 0, -1 },
            { -1, 0, 0, 0, 0, -1, 0, 0, -1 },
            { -1, -1, -1, 0, 0, -1, -1, -1, 0 }
        }; // матрица связей
    int d[SIZE]; // минимальное расстояние
    int v[SIZE]; // посещенные вершины
    int temp, minindex, min;
    int begin_index = 0;
    int N = num.toInt();

    /*system("chcp 1251");
    system("cls");*/
    // Инициализация матрицы связей
    /*for (int i = 0; i<SIZE; i++)
    {
    a[i][i] = 0;
    for (int j = i + 1; j<SIZE; j++) {
      printf("Введите расстояние %d - %d: ", i + 1, j + 1);
      scanf("%d", &temp);
      a[i][j] = temp;
      a[j][i] = temp;
    }
    }*/
    for (int i = 0; i<SIZE; i++)
    {
        for (int j = i + 1; j<SIZE; j++) {
            if (a[i][j] == -1) {
                temp = N * ((i + 1) * (i + 1) + (j + 1) * (j + 1)) + (i + 1) * (i + 1) + (j + 1) * (j + 1) + (i + 1) + (j + 1);
                temp %= 10;
                a[i][j] = temp;
                a[j][i] = temp;
            }
        }
    }
    // Вывод матрицы связей
    /*for (int i = 0; i<SIZE; i++)
    {
    for (int j = 0; j<SIZE; j++)
      printf("%5d ", a[i][j]);
    printf("\n");
    }*/

    /*for (int i = 0; i<SIZE; i++)
        {
        for (int j = 0; j<SIZE; j++)
            qDebug() << a[i][j];
        qDebug() << endl;
        }*/
    //Инициализация вершин и расстояний
    for (int i = 0; i<SIZE; i++)
    {
        d[i] = 10000;
        v[i] = 1;
    }
    d[begin_index] = 0;
    // Шаг алгоритма
    do {
        minindex = 10000;
        min = 10000;
        for (int i = 0; i<SIZE; i++)
        { // Если вершину ещё не обошли и вес меньше min
          if ((v[i] == 1) && (d[i]<min))
          { // Переприсваиваем значения
            min = d[i];
            minindex = i;
          }
        }
        // Добавляем найденный минимальный вес
        // к текущему весу вершины
        // и сравниваем с текущим минимальным весом вершины
        if (minindex != 10000)
        {
          for (int i = 0; i<SIZE; i++)
          {
            if (a[minindex][i] > 0)
            {
              temp = min + a[minindex][i];
              if (temp < d[i])
              {
                d[i] = temp;
              }
            }
          }
          v[minindex] = 0;
        }
    } while (minindex < 10000);
    // Вывод кратчайших расстояний до вершин
    /*printf("\nКратчайшие расстояния до вершин: \n");
    for (int i = 0; i<SIZE; i++)
    printf("%5d ", d[i]);*/

    // Восстановление пути
    int ver[SIZE]; // массив посещенных вершин
    int end = 4; // индекс конечной вершины = 5 - 1
    ver[0] = end + 1; // начальный элемент - конечная вершина
    int k = 1; // индекс предыдущей вершины
    int weight = d[end]; // вес конечной вершины

    while (end != begin_index) // пока не дошли до начальной вершины
    {
    for (int i = 0; i<SIZE; i++) // просматриваем все вершины
      if (a[i][end] != 0)   // если связь есть
      {
        int temp = weight - a[i][end]; // определяем вес пути из предыдущей вершины
        if (temp == d[i]) // если вес совпал с рассчитанным
        {                 // значит из этой вершины и был переход
          weight = temp; // сохраняем новый вес
          end = i;       // сохраняем предыдущую вершину
          ver[k] = i + 1; // и записываем ее в массив
          k++;
        }
      }
    }
    QString answer_to_string = "";
    for (int i = k - 1; i >= 0; i--) {
        answer_to_string += QString::number(ver[i]);
    }

    qDebug() << answer_to_string;

    return answer_to_string.toUtf8();
    /*if (answer_to_string == answer) {
        //upd_statistics(1, 1);
        return "+";
    }

    //upd_statistics(1, -1);
    return "-";*/
}
