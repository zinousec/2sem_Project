#include <QCoreApplication>
#include <QDebug>

QString weight(QString rebro)
{

    int i = rebro.mid(0,rebro.indexOf(',')).toInt();
    int j = rebro.mid(rebro.indexOf(','),-1).toInt();

    return "0";
}

QString checkCircle(QString robr, QStringList karkas)
{
  QString res = "";
  QStringList carcases=karkas;
  QString rbr = robr;
  QStringList circle;
  circle.push_back(rbr);

  QString start = rbr.mid(rbr.indexOf(',')+1,rbr.lastIndexOf(',')-rbr.indexOf(',')-1);
  QString finish = rbr.mid(rbr.lastIndexOf(',')+1,-1);

  if(carcases.length()==0)
      return "";
  while (start!=finish)
  {
      qDebug()<<start<<finish;



  auto it_elem = carcases.begin();

  while (it_elem->indexOf(finish)<1)
  {
      qDebug()<< *it_elem;
      if (it_elem==carcases.end()-1)
      {
          if (circle.length()<2)
              return "";
          auto t = circle.back();
          circle.pop_back();
          finish = circle.back().mid(circle.back().lastIndexOf(',')+1,-1);
          carcases.push_back(t);
          it_elem = carcases.begin();
      }
      else
          it_elem ++;
  }

  if((it_elem->indexOf(finish))==(it_elem->lastIndexOf(',')+1))
  {
      circle.push_back(it_elem->mid(0,it_elem->indexOf(','))+","+finish+it_elem->mid(it_elem->indexOf(','),it_elem->lastIndexOf(',')-it_elem->indexOf(',')));
      qDebug()<<circle.back()+"iiii";

  }
  else if(it_elem->indexOf(finish)==it_elem->lastIndexOf(',')-1)
  {
      circle.push_back(it_elem->mid(0,it_elem->indexOf(','))+it_elem->mid(it_elem->indexOf(','),it_elem->lastIndexOf(',')-1)+","+it_elem->mid(it_elem->lastIndexOf(',')+1,-1));
      qDebug()<<circle.back();
  }
  qDebug()<<carcases.at(it_elem-carcases.begin())+"start";
  carcases.removeAt(it_elem-carcases.begin());

  if (circle.length()>=1)
    finish = circle.back().mid(circle.back().lastIndexOf(',')+1,-1);
  }
  for (auto it=circle.begin();it!=circle.end();it++)
  {
      res+=*it +';';
  }


  return res;
}

QString task6(QString task_variant)
{
    QStringList all_rebra;
    QStringList all_cycles = {};
    QStringList carcases = {};
    QStringList hords = {};
    all_rebra = task_variant.split(";");
   for (int i=0;i<all_rebra.size();i++)
    {
        all_rebra[i] = weight(all_rebra[i])+","+ all_rebra[i];
    }
    QString circle = "";
    QString rebro = "";


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
