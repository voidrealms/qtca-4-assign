#include <QCoreApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QStringList>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QStringList drivers = QSqlDatabase::drivers();
    qInfo() << "Drivers: " << drivers;
    qInfo() << "";

    for (int i = 0;i < drivers.size();i++)
    {
        QString name = drivers.at(i);
        QSqlDatabase db = QSqlDatabase::addDatabase(name,name);
        if(db.driver()->hasFeature(QSqlDriver::Transactions))
        {
            qInfo() << name;
        }
    }


    return a.exec();
}
