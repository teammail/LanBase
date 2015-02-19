#ifndef IPBANKCLASS
#define IPBANKCLASS

#include <QMainWindow>

class IPBank
{
    QString strip;
    QString strname;

public:
    IPBank(QString ip, QString name): strip(ip), strname(name) {}
    QString getIPandNAME () { // Метод отдаёт связку IP+ИМЯ
       QString s;
       s = strip + " " + strname;
       return s;
    }
};

#endif // IPBANKCLASS

