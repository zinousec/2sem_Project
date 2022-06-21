#include <QCoreApplication>
#include <QDebug>

QString checkCircle(QString rbra, QStringList arcases)
{
  QString res = "";
  QStringList carcases=arcases;//={"0,3,5","1,1,4","3,1,2","4,1,3"};
  QString rbr = rbra;//= "7,3,4";
  QStringList circle;
  circle.push_back(rbr); //{"7,3,4"}
  //qDebug()<<rbr;
  QString start = rbr.mid(rbr.indexOf(',')+1,rbr.lastIndexOf(',')-rbr.indexOf(',')-1); //start=3
  QString finish = rbr.mid(rbr.lastIndexOf(',')+1,-1); //finish = 4
  //qDebug()<<start<<finish;
  if(carcases.length()==0)
      return "";
  while (start!=finish)
  {
      qDebug()<<start<<finish;


  //qDebug()<<rbr.indexOf(',')+1;
  auto it_elem = carcases.begin(); // *it_elem = "0,3,5"
  //qDebug()<< it_elem->indexOf(finish);
  while (it_elem->indexOf(finish)<1)
  {
      qDebug()<< *it_elem;
      if (it_elem==carcases.end()-1)
      {
          /*вернуться на шаг назад - 1) убрать последнее ребро из циклов. 2)исправить finish на предыдущее значение 3) добавить это ребро в конец каркаса
           *  4)заново искать
            */
          if (circle.length()<2)
              return "";
          auto t = circle.back();
          circle.pop_back(); // circle = {"7,3,4","1,4,1"}
          finish = circle.back().mid(circle.back().lastIndexOf(',')+1,-1); //finish=1
          carcases.push_back(t); //carcases={"0,3,5","4,1,3","3,1,2"};
          it_elem = carcases.begin();

          //return "";
      }
      else
          it_elem ++; //*it_elem = "1,1,4" //*it_elem = "3,1,2"
  }

  if((it_elem->indexOf(finish))==(it_elem->lastIndexOf(',')+1))
  {
      circle.push_back(it_elem->mid(0,it_elem->indexOf(','))+","+finish+it_elem->mid(it_elem->indexOf(','),it_elem->lastIndexOf(',')-it_elem->indexOf(',')));
      qDebug()<<circle.back()+"iiii";
      /*circle.push_back(finish);
      circle.push_back(start);*/
      // circle = {"7,3,4","1,4,1"}
  }
  else if(it_elem->indexOf(finish)==it_elem->lastIndexOf(',')-1)
  {
      circle.push_back(it_elem->mid(0,it_elem->indexOf(','))+it_elem->mid(it_elem->indexOf(','),it_elem->lastIndexOf(',')-1)+","+it_elem->mid(it_elem->lastIndexOf(',')+1,-1));
      /*circle.push_back(start);
      circle.push_back(finish);*/
      // circle = {"7,3,4","1,4,1","3,1,2"}
      qDebug()<<circle.back();
  }
  qDebug()<<carcases.at(it_elem-carcases.begin())+"gggg";
  carcases.removeAt(it_elem-carcases.begin()); //carcases={"0,3,5","3,1,2","4,1,3"}; //carcases={"0,3,5","4,1,3"};

  if (circle.length()>=1)
    finish = circle.back().mid(circle.back().lastIndexOf(',')+1,-1); //finish = 1 //finish=2
  }
  for (auto it=circle.begin();it!=circle.end();it++)
  {
      res+=*it +';';
  }


  return res;
}

QString task3(QString task_variant)
{
    //QString task= task_variant;
    //task_variant = "1,2;1,4;1,5;1,6;2,3;2,5;3,4;3,6;4,5;5,6";
    QStringList all_rebra;// = task_variant.split("\\s+"); //1 2 1 4 1 5 1 6 2 3 2 5 3 4 3 6 4 5 5 6
    QStringList all_cycles = {};
    QStringList carcases = {};
    QStringList hords = {};
    all_rebra = task_variant.split(";");
   /* for (int i=0;i<all_rebra.size();i++)
    {
        all_rebra[i] = weight(all_rebra[i])+","+ all_rebra[i];
    }*/
    //all_rebra.sort();
    QString circle = "";
    QString rebro = "";

    //rebro= all_rebra.front();
    //all_rebra.pop_front();
    //circle = checkCircle(rebro, carcases);
    while (all_rebra.length()>0)
    {
        QString rbr=all_rebra.front();
        circle = checkCircle(rbr, carcases);

        if(circle.length()>0)
        {
            hords.push_back(rbr);
            all_cycles.push_back(circle);
        }
        else
        {
            carcases.push_back(rbr);
        }
        all_rebra.pop_front();
    }
    QString res = "";

    foreach (auto elem, hords) {
        res.append(elem);
        res.append (";");
    }
    return res;
}
