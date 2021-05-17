#include "mainwindow.h"

#include <QApplication>
#include<QDebug>
#include<QtSql/QSqlDatabase>
#include<QSqlQuery>
#include <QTime>
#include <QDate>
#include<QDateTime>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
